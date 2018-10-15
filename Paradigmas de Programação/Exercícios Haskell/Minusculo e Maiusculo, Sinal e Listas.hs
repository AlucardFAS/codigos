abc::Char->Bool
abc x = x >= 'a' && x <= 'z'


sinal :: Int -> Int
sinal x | x > 0 = 1
        | x == 0 = 0
        | otherwise = -1

concatenar::[Int]->[Int]->[Int]
concatenar lista1 lista2 = lista1++lista2

concatenarlista::[[Int]] -> [Int]
concatenarlista [] = []
concatenarlista ([]:x) = concatenarlista x
concatenarlista ((y:xy):x) = y:concatenarlista (xy:x)
