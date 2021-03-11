import Text.Printf

main = do
  a <- getLine
  b <- getLine
  let prod = (read a :: Int) * (read b :: Int)
  printf "PROD = %d\n" (prod :: Int)