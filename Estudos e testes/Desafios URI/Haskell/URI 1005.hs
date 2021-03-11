import Text.Printf

main = do
  a <- getLine
  b <- getLine
  let media = (((read a :: Double) * 3.5) + ((read b :: Double) * 7.5))/11
  printf "MEDIA = %.5f\n" (media :: Double)