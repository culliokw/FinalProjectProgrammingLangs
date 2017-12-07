{-# LANGUAGE ParallelListComp #-}

--Add function 
add :: Num h => [[h]] -> [[h]] -> [[h]]
add a b
      |(calcLengthRows a /= calcLengthRows b) || (calcLengthCols a /= calcLengthCols b) = [[]]
      |otherwise = zipWith (zipWith (+)) a b

--recursive add function
add1 :: Num l => [[l]] -> [[l]] -> [[l]]
add1 [] [] = [] 
add1 x y 
          |(calcLengthRows x /= calcLengthRows y) || (calcLengthCols x /= calcLengthCols y) = [[]]
add1 (x:xs) (y:ys) = zipWith (+) x y : add1 xs ys


--map-reduce multiplication function
multiplication :: Num p => [[p]] -> [[p]] -> [[p]]
multiplication a b
                 |(calcLengthRows b) /= (calcLengthCols a) = [[]]
                 | otherwise = [map (foldl (+) 0 . zipWith (*) x) (transpose b) | x<-a]

--Check length of rows of matrix
calcLengthRows x = length x

--Check length of columns of matrix
calcLengthCols y = length (head y)

--multiplication function that uses helper functions to calculate
multiply :: Num f => [[f]] -> [[f]] -> [[f]]
multiply a b 
          | (calcLengthRows b) /= (calcLengthCols a)  = [[]]
          | otherwise = [calcrow a1 (transpose b) | a1<-a]

--function to calculate the row
calcrow :: Num v => [v] -> [[v]] -> [v]
calcrow a b = [calccell a b1 | b1 <- b]

--function to calculate cell
calccell :: Num s => [s] -> [s] -> s
calccell a b = foldr (+) 0 [a1 * b1 |a1<-a | b1<-b]

--function to transpose a matrix
transpose :: [[g]] -> [[g]]
transpose ([]:_) = []
transpose x = (map head x) : transpose (map tail x)