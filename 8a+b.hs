import qualified Data.Map as M
import qualified Data.Set as S
main = do
    inputStr <- getContents
    let
        signals0 = parse inputStr
        signals = map deduceCt signals0
        nums = map (read . toNums) signals :: [Int]
    print nums
    print $ sum nums

type Segs = S.Set Char
type SegMap = M.Map Segs Char

data Data = Data { signal :: [Segs]
                 , conTable :: SegMap
                 , input :: [String]
                 } deriving (Show)

toNums (Data _ ct i) = map ((ct M.!) . S.fromList) i

parse :: String -> [Data]
parse inStr =
    let
        inLines = lines inStr
        inData = map words inLines
        signals = map (\a -> Data (map S.fromList $ take 10 a) M.empty (drop 11 a)) inData
    in
        signals


findSeg :: Char -> SegMap -> Segs
findSeg num ct = head [a | (a, b) <- M.toList ct, b == num]

-- Digit 1 has 2 segments
-- Digit 4 has 4 segments
-- Digit 7 has 3 segments
-- Digit 8 has 7 segments
trivialSegs :: [Segs] -> SegMap
trivialSegs s = M.fromList $ filter (\x -> snd x /= '-') $ map segToDigit s
    where
        segToDigit = \s -> case S.size s of
            2 -> (s, '1')
            4 -> (s, '4')
            3 -> (s, '7')
            7 -> (s, '8')
            _ -> (s, '-')

leftFromDifference num a = head . filter ((==num) . S.size . S.difference a)
a `subtractS` b = filter (/= b) a

deduceCt :: Data -> Data
deduceCt (Data s _ i) =
    let
        -- Get trivially 1, 4, 7, 8
        trivCt = trivialSegs s
        s069 = filter ((==6) . S.size) s
        s235 = filter ((==5) . S.size) s
        -- Get 9 from 4
        s9 = leftFromDifference 0 (findSeg '4' trivCt) s069
        s06 = s069 `subtractS` s9
        -- Get 2 from 9
        s2 = leftFromDifference 2 s9 s235
        s35 = s235 `subtractS` s2
        -- Get 3, 5 from 2
        s5 = leftFromDifference 2 s2 s35
        s3 = leftFromDifference 1 s2 s35
        -- Get 0, 6 from 1
        s0 = leftFromDifference 0 (findSeg '1' trivCt) s06
        s6 = leftFromDifference 1 (findSeg '1' trivCt) s06
        -- Combine
        ct = M.union trivCt $ M.fromList [(s0, '0'),
                                          (s2, '2'),
                                          (s3, '3'),
                                          (s5, '5'),
                                          (s6, '6'),
                                          (s9, '9')]
    in
        Data s ct i

