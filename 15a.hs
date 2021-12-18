import qualified Data.Set as S
import Data.Char (digitToInt)
main = do
    inputStr <- getContents
    let
        arr = parse inputStr
        maxIndex = length arr - 1
        result = calcRisk arr S.empty maxIndex maxIndex
    print result

parse :: String -> [[Int]]
parse s = map (map digitToInt) $ lines s

calcRisk :: [[Int]] -> S.Set (Int, Int) -> Int -> Int -> Int
calcRisk arr past i j
    | i == 0 && j == 0                         = 0
    | i < 0 || j < 0 || i >= size || j >= size = maxBound
    | (i, j) `S.member` past                   = maxBound
    | otherwise                                = curVal + minPrev
    where
        size = length arr
        curVal = arr !! i !! j
        calc = calcRisk arr $ S.insert (i, j) past
        minPrev = minimum [calc (i-1) j, calc i (j-1), calc (i+1) j, calc i (j+1)]
