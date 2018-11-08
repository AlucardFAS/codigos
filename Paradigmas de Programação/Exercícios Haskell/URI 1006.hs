import Text.Printf

main = do
  a <- getLine
  b <- getLine
  c <- getLine
  let media = (((read a :: Double) * 2) + ((read b :: Double) * 3) + ((read c :: Double) * 5))/10
  printf "MEDIA = %.1f\n" (media :: Double)