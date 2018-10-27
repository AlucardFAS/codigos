abc::Char->Bool
abc x = x >= 'a' && x <= 'z'


sinal :: Int -> Int
sinal x | x > 0 = 1
        | x == 0 = 0
        | otherwise = -1

--Concatenação de listas
concatenar::[Int]->[Int]->[Int]
concatenar lista1 lista2 = lista1++lista2

--Concatenação de elementos de uma lista de listas
--utilizando recursividade
concatenarlista::[[Int]] -> [Int]
concatenarlista [] = []
concatenarlista ([]:x) = concatenarlista x
concatenarlista ((y:xy):x) = y:concatenarlista (xy:x)

--Concatenação de elementos de uma lista de listas
--utilizando extração
concatenarlista2 :: [[a]] -> [a]
concatenarlista2 xss = [x | xs<-xss, x<-xs] 

--Recebe um vetor e retorna um vetor de tuplas
--contendo pares dos elementos do vetor recebido
--ex: [1,2,3,4] => [[1,2],[2,3],[3,4]]
pares :: [a] -> [(a,a)]
pares xs = zip xs (tail xs)

--Verifica se o vetor está em ordem crescente
--Utiliza função pares
crescente :: Ord a => [a] -> Bool
crescente xs = and [x <= x' | (x, x') <- pares xs]
