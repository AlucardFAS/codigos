%%%%%%%%%%MADE BY ALUCARDFAS%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%% VERIFIQUE A SITUAÇÃO DO ALUNO %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%LOGICAL STATEMENTS%%%%%%%%%%
nota(joao, 5.0).
nota(maria, 6.0).
nota(pedro, 5.0).
nota(augusto, 3.0).
nota(mariana, 9.0).
nota(cleuza, 3.5).
nota(jose, 6.5).
nota(joaquim, 4.5).
nota(ronaldo, 6.5).
nota(maria, -1).
nota(marcos, 14).

%%%%%%%%%%%%%%PREDICATE%%%%%%%%%%%%%%

%VERIFICA A SITUAÇÃO
verifica_aluno :-
    read(Nome),
    nota(Nome, Nota),
    (   
    Nota >= 7.0 , Nota =< 10.0, write("Aprovado! __Parabéns!__"), nl ;
    Nota >= 5.0 , Nota < 7.0, write("Recuperação! __Vá estudar jovem gafanhoto__"), nl ;
    Nota >= 0.0 , Nota < 5.0, write("Reprooooovado! __Seu Madruga feelings...__"), nl ;
    Nota < 0.0 , Nota > 10.0, write("ERRO 404 __Essa nota ai não existe não meu consagrado__")
    ).

%VERIFICA SOMENTE SE APROVADO
aprovado :- 
    read(Nome),
    nota(Nome, Nota),
    Nota >= 7.0 , Nota =< 10.0, write("Aprovado! __Parabéns!__"), nl.

%VERIFICA SOMENTE SE DE RECUPERAÇÃO
recuperacao :- 
    read(Nome),
    nota(Nome, Nota),
    Nota >= 5.0 , Nota < 7.0, write("Recuperação! __Vá estudar jovem gafanhoto__"), nl.

%VERIFICA SOMENTE SE REPROVADO
reprovado :- 
    read(Nome),
    nota(Nome, Nota),
    Nota >= 0.0 , Nota < 5.0, write("Reprooooovado! __Seu Madruga feelings...__"), nl.

%VERIFICA SOMENTE SE ERRO
erro :- 
    read(Nome),
    nota(Nome, Nota),
    Nota < 0.0 , Nota > 10.0, write("ERRO 404 __Essa nota ai não existe não meu consagrado__"), nl.