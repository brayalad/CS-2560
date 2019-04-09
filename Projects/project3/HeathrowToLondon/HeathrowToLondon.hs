--HeathrowToLondon.hs
import System.Random
import System.IO
import Data.List


data Section = Section { getA :: Int, getB :: Int, getC :: Int } deriving (Show)  
type RoadSystem = [Section]  

data Label = A | B | C deriving (Show)  
type Path = [(Label, Int)] 

roadStep :: (Path, Path, Int, Int) -> Section -> (Path, Path, Int, Int)
roadStep (pathA, pathB, pathPriceA, pathPriceB) (Section a b c) =   
    let priceA = if pathPriceA == 0
                    then sum $ map snd pathA  
                    else pathPriceA
        priceB = if pathPriceB == 0
                    then sum $ map snd pathB 
                    else pathPriceB 
        forwardPriceToA = priceA + a  
        crossPriceToA = priceB + b + c  
        forwardPriceToB = priceB + b  
        crossPriceToB = priceA + a + c  
        newPathToA = if forwardPriceToA <= crossPriceToA  
                        then (A,a):pathA  
                        else (C,c):(B,b):pathB  
        newPathToB = if forwardPriceToB <= crossPriceToB  
                        then (B,b):pathB  
                        else (C,c):(A,a):pathA  
    in  (newPathToA, newPathToB, priceA, priceB) 

optimalPath :: RoadSystem -> Path  
optimalPath roadSystem = 
    let (bestAPath, bestBPath, currentPriceA, currentPriceB) = foldl' roadStep ([],[],0,0) roadSystem  
    in  if sum (map snd bestAPath) <= sum (map snd bestBPath)  
            then reverse bestAPath  
            else reverse bestBPath  

groupsOf :: Int -> [a] -> [[a]]  
groupsOf 0 _ = undefined  
groupsOf _ [] = []  
groupsOf n xs = take n xs : groupsOf n (drop n xs)  

(?) :: Bool -> a -> a -> a
True  ? x = const x
False ? _ = id

roundToNearestMultiple :: Int -> Int -> Int
roundToNearestMultiple n m = (m >= n) ? m $ (n `div` m + 1) * m


main :: IO()
main = do  
    gen <-newStdGen 
    let randNumGenerated = randomR (1,25) gen :: (Int, StdGen)
    let randNum = fst randNumGenerated
    let multThree = roundToNearestMultiple randNum 3
    let randList = take multThree $ randomRs (1,500) gen :: [Int] 
    writeFile "paths.txt" . intercalate "\n" . map show $ randList
    handle <- openFile "paths.txt" ReadMode
    contents <- hGetContents handle 
    putStrLn $ "\nCurrent Cost of All " ++ show multThree ++ " Available Roads: "
    putStrLn contents
    let threes = groupsOf 3 (map read $ lines contents)  
        roadSystem = map (\[a,b,c] -> Section a b c) threes  
        path = optimalPath roadSystem  
        pathString = concat $ map (show . fst) path  
        pathPrice = sum $ map snd path  
    putStrLn $ "\nThe best path to take is: " ++ pathString  
    putStrLn $ "The price is: " ++ show pathPrice ++ "\n"
    hClose handle