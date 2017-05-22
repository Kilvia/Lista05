#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Cliente.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Cliente *aux_tail;
	Cliente c;
	Lista lista1;

	
	printf("\n------ Insert five elements ------\n\n");

	lista1.inserirCliente("Junmyeon","01",0);
	lista1.inserirCliente("Sehun","7457",0);
	lista1.inserirCliente("Chanyeol","0256",2);
	lista1.inserirCliente("Anny","01025",3);
	lista1.inserirCliente("Molly","130916",1);

	lista1.imprimirLista();

	printf("\n------ Remove from Head ------\n\n");

	c = lista1.removerCliente(0);
	lista1.imprimirLista();

	printf("\nNome do cliente removido: %s\nCPF do cliente removido: %s\n", c.getNomeCliente().c_str(), c.getCpfCliente().c_str());

	printf("\n\n### \n\n");
	aux_tail = lista1.getLastElement();

	printf("Last Cliente - %s\n", aux_tail->getNomeCliente().c_str());
	printf("First Cliente - %s\n", aux_tail->next->getNomeCliente().c_str());
	
	printf("\n------ Remove from middle ------\n\n");

	c = lista1.removerCliente(2);
	lista1.imprimirLista();

	printf("\nNome do cliente removido: %s\nCPF do cliente removido: %s\n", c.getNomeCliente().c_str(), c.getCpfCliente().c_str());
	
	printf("\n\n### \n\n");
	aux_tail = lista1.getLastElement();

	printf("Last Cliente - %s\n", aux_tail->getNomeCliente().c_str());
	printf("First Cliente - %s\n", aux_tail->next->getNomeCliente().c_str());

	printf("\n------ Remove from tail ------\n\n");

	c = lista1.removerCliente(2);
	lista1.imprimirLista();

	printf("\nNome do cliente removido: %s\nCPF do cliente removido: %s\n", c.getNomeCliente().c_str(), c.getCpfCliente().c_str());
	
	printf("\n\n### \n\n");
	aux_tail = lista1.getLastElement();

	printf("Last Cliente - %s\n", aux_tail->getNomeCliente().c_str());
	printf("First Cliente - %s\n", aux_tail->next->getNomeCliente().c_str());

	printf("---------------\n");

	int posi = lista1.buscarCliente("Junmyeon","01");
	
	if(posi == 0){
		printf("\nCliente não encontrado!\n");
	
	} else{
		printf("\nCliente encontrado na posição: %d\n",posi);
	}
	
	printf("\n------ Delete list ------\n\n");

	lista1.deletarLista();

	lista1.imprimirLista();
		
	return 0;
}

