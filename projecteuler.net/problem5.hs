import Data.Int
import Data.List
import Data.Function (on)

prime_factors :: Int -> [Int]
prime_factors 1 = []
prime_factors n
  | factors == [] = [n]
  | otherwise = factors ++ prime_factors (n `div` (head factors))
  where factors = take 1 $ filter (\x -> (n `mod` x) == 0) [2 .. n-1]

my_lcm :: Int
my_lcm = product $ concat (map (\x -> occurrences_of x) ([2,3,5,7,11,13,17,19]))
  where occurrences_of n = maximumBy (compare `on` length) (filter (\x -> head x == n) list_prime_fac)
        list_prime_fac   = group $ concat (map prime_factors [2..20])
