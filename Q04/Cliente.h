#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
using namespace std;

class Cliente {
	
	string nome;
	
	string cpf;
	

public:
	
	Cliente *next;

	Cliente(string name, string ident);

	Cliente();

	string getNomeCliente();

	string getCpfCliente();

	void setNomeCliente(string name);

	void setCpfCliente(string ident);
};


#endif