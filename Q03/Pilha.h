#ifndef PILHA_H
#define PILHA_H
#define MAX 50

#include <string>
#include "Cliente.h"
using namespace std;

class Pilha{

	Cliente *head;

	int quantElem;
	
	void criarPilha();

public:
	Pilha();

	void adicionarCliente(string nome, string cpf);
	
	Cliente removerCliente();
	
	void deletarPilha();
	
	void imprimirPilha();
};

#endif