import Text.Printf

main = do
  a <- getLine
  b <- getLine
  let soma = (read a :: Int) + (read b :: Int)
  printf "SOMA = %d\n" (soma :: Int)