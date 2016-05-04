import Data.Int
import Data.List

isqrt :: Int64 -> Int64
isqrt = floor . sqrt . fromIntegral

is_prime :: Int64 -> Bool
is_prime n = null [ x | x <- [2.. isqrt n], n `mod`x  == 0]

largest_prime_factor :: Int64 -> Maybe Int64
largest_prime_factor n = find (\x -> (mod n x == 0) && is_prime x) (reverse [2,3..isqrt n])
