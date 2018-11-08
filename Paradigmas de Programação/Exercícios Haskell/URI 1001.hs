main = do
  x <- getLine
  y <- getLine
  let z = read x + read y
  putStrLn("X = " ++ show(z))
