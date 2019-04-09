--ReversePolish.hs
import Data.List  

main = do
    putStr "\nEnter Calulation in Reverse Polish Notation: "
    input <- getLine
    if null input
        then return()
        else do
            let calc = solveRPN input
            putStr "Calulation Result: "
            print calc
            main



solveRPN :: String -> Float  
solveRPN = head . foldl foldingFunction [] . words  
    where   foldingFunction (x:y:ys) "*" = (x * y):ys  
            foldingFunction (x:y:ys) "+" = (x + y):ys  
            foldingFunction (x:y:ys) "-" = (y - x):ys  
            foldingFunction (x:y:ys) "/" = (y / x):ys  
            foldingFunction (x:y:ys) "^" = (y ** x):ys  
            foldingFunction (x:xs) "ln" = log x:xs  
            foldingFunction xs "sum" = [sum xs]  
            foldingFunction xs numberString = read numberString:xs  

