#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
#include "Cliente.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	
	Pilha pilha1;

	pilha1.adicionarCliente("Rodrigo", "0125896");
	
	pilha1.adicionarCliente("Sehun","7457");
		
	pilha1.adicionarCliente("Chanyeol","0256");

	pilha1.adicionarCliente("Anny","01025");

	pilha1.adicionarCliente("Molly","130916");

	pilha1.imprimirPilha();

	Cliente c = pilha1.removerCliente();

	printf("\nNome do cliente removido: %s\nCPF do cliente removido: %s\n", c.getNomeCliente().c_str(), c.getCpfCliente().c_str());
	
	printf("\n");

	pilha1.imprimirPilha();
	
	printf("\n");

	pilha1.deletarPilha();

	pilha1.imprimirPilha();
		
	return 0;
}

