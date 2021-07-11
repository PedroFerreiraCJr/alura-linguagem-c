.PHONY: all clean execute

# por padrao o target sera a execucao do arquivo compilado
all: clean execute

# caso o arquivo esteva com o timestamp mais antigo, sera apagado
clean:
	@rm -rf ./bin/
	@echo "arquivos removidos"

# local e arquivo que sera gerado na execucao da compilacao do arquivo do source code
./bin: ./main.c
	@echo "compilando..."
	@mkdir bin/
	@gcc -Wall -o ./bin/main mapa.c main.c

# simplesmente executa o arquivo caso nao tenha havido modificacao no source code
execute: ./bin
	@./bin/main
