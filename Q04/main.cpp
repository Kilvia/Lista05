#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "Cliente.h"
#include <string>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	Fila fila1;

	fila1.adicionarCliente("Bete", "0125896");
	
	fila1.adicionarCliente("Sehun","7457");
	
	fila1.adicionarCliente("Chanyeol","0256");

	fila1.adicionarCliente("Anny","01025");

	fila1.adicionarCliente("Molly","130916");

		fila1.imprimirFila();

	Cliente c = fila1.removerCliente();

	printf("\nNome do cliente removido: %s\nCPF do cliente removido: %s\n", c.getNomeCliente().c_str(), c.getCpfCliente().c_str());
	
	printf("\n");
	
	fila1.imprimirFila();
		
	printf("\n");
	
	fila1.deletarFila();

	fila1.imprimirFila();	
		
	return 0;
}

