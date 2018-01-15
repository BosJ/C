import Data.Int
import Data.List

pyth_triplet :: Int -> [ (Int, Int, Int) ]
pyth_triplet x = [ (a,b,c) | a<-[1..x], b<-[1..a], c<-[1..x], (a^2) + (b^2) == (c^2), a + b + c == 1000]
