{-# LANGUAGE ParallelListComp #-}


add :: Num h => [[h]] -> [[h]] -> [[h]]
add = zipWith $ zipWith (+)

add1 :: (Num l) => [[l]] -> [[l]] -> [[l]]
add1 [] [] = [] 
add1 (x:xs) (y:ys) = zipWith (+) x y : add xs ys


multiplication :: Num a => [[a]] -> [[a]] -> [[a]]
multiplication a b = [map (foldl (+) 0 . zipWith (*) x) (transpose b) | x<-a]


calcLengthRows x = length x

calcLengthCols y = length $ head y

multiply :: Num a => [[a]] -> [[a]] -> [[a]]
multiply a b 
          | (calcLengthRows b) /= (calcLengthCols a)  = [[]]
          | otherwise = [calcrow a1 $ transpose b | a1<-a]

calcrow :: Num a => [a] -> [[a]] -> [a]
calcrow a b = [calccell a b1 | b1 <- b]

calccell :: Num a => [a] -> [a] -> a
calccell a b = foldr (+) 0 [a1 * b1 |a1<-a | b1<-b]


transpose :: [[g]] -> [[g]]
transpose ([]:_) = []
transpose x = (map head x) : transpose (map tail x)