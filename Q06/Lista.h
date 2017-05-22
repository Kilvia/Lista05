#ifndef LISTA_H
#define LISTA_H
#include <string>
#include "Cliente.h"
using namespace std;

class Lista{

	int quantElem;
	Cliente *head;
	
	void criarLista();

public:
	Lista();
	
	int tamanhoLista();
	Cliente *getLastElement();

	void inserirCliente(string nome, string cpf, int posi);
	Cliente removerCliente(int posi);
	int buscarCliente(string nome, string cpf);
	void deletarLista();
	void imprimirLista();
};

#endif