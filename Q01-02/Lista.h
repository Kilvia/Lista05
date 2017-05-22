#ifndef LISTA_H
#define LISTA_H
#define MAX 50

#include <string>
#include "Cliente.h"
using namespace std;

class Lista{

	Cliente *head;

	int quantElem;
	
	void criarLista();

public:
	Lista();

	void inserirCliente(string nome, string cpf, int posi);
	
	int tamanhoLista();
	
	Cliente removerCliente(int posi);
	
	int buscarCliente(string nome, string cpf);
	
	void deletarLista();
	
	void imprimirLista();

};

#endif