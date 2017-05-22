#ifndef FILA_H
#define FILA_H
#include <string>
#include "Cliente.h"
using namespace std;

class Fila{

	Cliente *head;

	int quantElem;
	
	void criarFila();

public:
	Fila();

	void adicionarCliente(string nome, string cpf);
	
	Cliente removerCliente();
	
	void deletarFila();
	
	void imprimirFila();
};

#endif