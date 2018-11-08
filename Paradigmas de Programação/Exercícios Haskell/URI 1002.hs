import Text.Printf

main = do
  raio <- getLine
  let n = 3.14159
  let area = n * (read raio :: Double) ^ 2
  printf "A=%.4f\n" (area :: Double)