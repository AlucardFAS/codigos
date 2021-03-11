busca :- inicial(So), busca([0-0-0-So-[]],[]).
	busca([_-G-_-Estado-Caminho|_],_) :-
	meta(M), member(Estado,M), !,
	reverse(Caminho,Solucao).
	
busca([_-G-_-Estado-Caminho|ListaEstados],Expandidos) :-
	sucessores(Estado,Sucessores),
	union([Estado],Expandidos,NovosExpandidos),
	subtract(Sucessores,NovosExpandidos,SucessoresNaoExpandidos),
	estende(G,Estado,Caminho,SucessoresNaoExpandidos,NovosEstados),
	insere(NovosEstados,ListaEstados,NovaListaEstados),
    busca(NovaListaEstados,NovosExpandidos).

sucessores(Estado,Sucessores) :-
	findall(X,oper(_,Estado,X,_),Sucessores).

estende(_,_,_,[],[]).

estende(X,E,C,[S|Ss],[0-G-H-S-[A|C]|Ps]) :-
	oper(A,E,S,Y),
	G is X+Y,
	h(S,H),
	estende(X,E,C,Ss,Ps).

insere(NovosEstados,ListaEstados,NovaListaEstados) :-
	estrategia(Tipo),
  	(Tipo=1 -> append(ListaEstados,NovosEstados,NovaListaEstados) ;
	Tipo=2 -> append(NovosEstados,ListaEstados,NovaListaEstados) ;
	append(ListaEstados,NovosEstados,Lista), sort(Lista,NovaListaEstados)).