module Main (main) where

import Lib

main :: IO ()
main = do
  sq <- lines <$> getContents
  let nLine = show $ mostLoadedElf sq 3
  putStrLn nLine
