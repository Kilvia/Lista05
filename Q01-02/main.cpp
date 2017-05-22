#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Cliente.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	
	Lista lista1;

	lista1.inserirCliente("Junmyeon","01",0);

	lista1.inserirCliente("Sehun","7457",1);
	
	lista1.inserirCliente("Chanyeol","0256",2);

	lista1.inserirCliente("Anny","01025",3);

	lista1.inserirCliente("Molly","130916",1);

	lista1.imprimirLista();

	Cliente c = lista1.removerCliente(4);

	printf("\nNome do cliente removido: %s\nCPF do cliente removido: %s\n", c.getNomeCliente().c_str(), c.getCpfCliente().c_str());
	
	printf("\n");
	
	lista1.imprimirLista();

	int posi = lista1.buscarCliente("Sehun","7457");	
	
	if(posi == -1){

		printf("\nCliente não encontrado!\n");
	
	}else{
	
		printf("\nCliente encontrado na posição: %d\n",posi);
	
	}
	
	printf("\n");

	lista1.deletarLista();

	lista1.imprimirLista();
		
	return 0;
}

