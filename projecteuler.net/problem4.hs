import Data.Int
import Data.List

largest_palindrome :: Maybe Int
largest_palindrome = find (\x -> elem x product_3dig_nums) (palindromes_below (999^2))
    where product_3dig_nums = [ (i*j) | i <- [100..999], j <- [100..999] ]

palindromes_below :: Int -> [Int]
palindromes_below n = filter (\x -> show x == (reverse $ show x)) (reverse [1,2..n])
