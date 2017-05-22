#include "Cliente.h"

Cliente::Cliente(string nome, string cpf){

	setNomeCliente(nome);
	
	setCpfCliente(cpf);
	
	next = NULL;
	
	prev = NULL;
}

Cliente::Cliente(){}

string Cliente::getNomeCliente(){

	return nome;
}

string Cliente::getCpfCliente(){

	return cpf;
}

void Cliente::setNomeCliente(string name){

	nome = name;
}

void Cliente::setCpfCliente(string iden){

	cpf = iden;
}