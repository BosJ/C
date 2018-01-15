import Data.Int
import Data.List

nth_prime :: Int -> Int
nth_prime n = last $ take n $ f [2,3..]
    where f (x:xs) = x : f [ y | y<-xs, (mod y x) /= 0 ]
