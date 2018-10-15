CC=gcc
warning=-W -Wall -pedantic -std=c11
bibl= -lm

arq=$(wildcard *.c)
bin=$(arq:.c=)

.PHONY: all clean help

help:
	@echo "Sintaxe: make <opções>"
	@echo "	Opções:"
	@echo "		help : mostra esta mensagem"
	@echo "		all  : compila todos os fontes da pasta"
	@echo "		clean: apaga todos os binários criados"
	@echo ""

all: $(bin)

clean: 
	@rm -f $(bin)

%:%.c
	@echo -n "Gerando executável $@"
	@$(CC) $< -o $@ $(warning) $bibl && echo " [OK]