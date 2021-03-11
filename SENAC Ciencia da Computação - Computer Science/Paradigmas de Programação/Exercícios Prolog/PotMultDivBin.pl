%potencia(BASE,EXPOENTE,POTENCIA)
%EXEMPLO: potencia(2,3,R) R = 8
potencia(_,0,1).
potencia(B,N,P) :- 				%passo
    			N > 0,			%condição do passo
    			M is N - 1,		%simplifica o problema
    			potencia(B,M,R),%chamada recursiva 
    			P is B * R.		%solução final


%fatorial(Numero, Fatorial)
%EXEMPLO: fatorial(4,R) R = 24
fatorial(0,1).
fatorial(N,F) :- 				%passo
			    N > 0, 			%condição do passo
			    M is N - 1, 	%simplifica o problema
			    fatorial(M,R),  %chamada recursiva 
 				F is N * R. 	%solução final

%multiplicacao(Numero 1, Numero 2, Multiplicados)
%EXEMPLO: multiplicacao(2,3,R) R = 6
multiplicacao(M,1,M).
multiplicacao(_,0,0).
multiplicacao(M,N,V) :-				 
    			N > 0,
    			J is N - 1,
    			multiplicacao(M,J,R),
    			V is M + R.

%divisao(dividendo,divisor,quociente,)
%EXEMPLO: divisao(8,2,Resultado,Resto) Resultado = 4    Resto = 0
%EXEMPLO: divisao(8,3,Resultado,Resto) Resultado =    Resto = 2
divisao(_,0,"Non Ecziste!").
divisao(M,M,1).
divisao(M,N,V,Resto) :-			
    		(   M >= N,
    			M > 0,
    			J is M - N,
    			divisao(J,N,R,Resto),
    			V is R + 1		
            ) ; (   
    			N > M, V is 0, Resto is M	
            ).

%binario(DecimalParaBinario)
%EXEMPLO: binario(10) --> "1010"
binario(1) :- 
    			write(1).
binario(X) :-
    			X > 0,
	    		divisao(X,2,Resultado,Resto),
	    		binario(Resultado),
	    		write(Resto).