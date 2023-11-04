module Lib
  ( mostLoadedElf,
  )
where

import Data.List (sort)
import Data.List.Split

mostLoadedElf :: [String] -> Int -> Int
mostLoadedElf i n = sum $ take n sGrs
  where
    grs = splitOn [""] i
    sGrs = reverse $ sort $ map (sum . map read) grs :: [Int]
