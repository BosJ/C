import Data.Int
import Data.Char
import Data.List
import Data.Tuple

-- Note: sieve produces infinite prime numbers
sieve :: [Int64]
sieve = f [2,3..]
    where f (x:xs) = x : f [ y | y<-xs, (mod y x) /= 0 ]

-- Check if n is prime
checkIfPrime :: Int64 -> Bool
checkIfPrime n
    | find (>= n) sieve == Just n = True
    | otherwise = False

-- Get all divisors of m
divisors :: Int64 -> [Int64]
divisors m = [ x | x<-[1..m], (mod m x) == 0 ]

-- Largest prime factor
largestPrimeFactor :: Int64 -> Maybe Int64
largestPrimeFactor n = find checkIfPrime $ reverse (divisors n)
