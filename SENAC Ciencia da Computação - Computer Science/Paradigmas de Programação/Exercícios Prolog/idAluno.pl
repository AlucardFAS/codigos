%%%%%%%%% MADE BY ALUCARDFAS %%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%% BUSQUE VIA ID %%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

aluno("Alberto Silva",1001).
aluno("Carlos Costa",1002).
aluno("Andrea Matos",1003).

busca_id :-
    aluno(Nome_Aluno,ID_Aluno),
    write('Escreva o ID: '),
    read(ID_Aluno),
    write('O ID é: '),
    write(aluno(Nome_Aluno,ID_Aluno)).