import Data.Char (digitToInt)
main = do
    inputStr <- getContents
    let
        arr = parse inputStr
        maxIndex = length arr - 1
        result = dp arr maxIndex maxIndex
    print result

parse :: String -> [[Int]]
parse s = map (map digitToInt) $ lines s

dp :: [[Int]] -> Int -> Int -> Int
dp arr i j
    | i < 0 || j < 0   = maxBound
    | i == 0 && j == 0 = 0
    | otherwise        = curVal + minPrev
    where
        curVal = arr !! i !! j
        minPrev = min (dp arr (i-1) j) (dp arr i (j-1))
