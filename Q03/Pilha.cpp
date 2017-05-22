#include "Pilha.h"
#include "Cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

Pilha::Pilha(){
	
	criarPilha();
}


void Pilha::criarPilha(){
	
	head = NULL;

	quantElem = 0;
}

void Pilha::adicionarCliente(string nome, string cpf){

	int i = 0;

	Cliente *aux = head;

	Cliente *novo = new Cliente(nome, cpf);

	if(quantElem == 0){
		
		head = novo;

		novo->next = NULL;

	}else{

		novo->next = head;

		head = novo;
	}

	quantElem++;
}

Cliente Pilha::removerCliente(){

	Cliente *aux = head;

	head = head->next;

	aux->next = NULL;

	quantElem--;

	return *aux;
}

void Pilha::deletarPilha(){
	
	int i;
	
	int times = quantElem;
	
	for (i = 0; i < times; i++)
	{
	
		removerCliente();

	}
}

void Pilha::imprimirPilha(){
 
	int i;

	printf("\tElementos da Pilha\n");

	Cliente *aux = head;

	printf("Quanidade de Elementos: %d\n", quantElem);

	for(i = 0; i <= (quantElem - 1); i++){ 

		printf("\n");
	
		printf("Cliente: %s\n", aux->getNomeCliente().c_str());
		
		printf("CPF: %s\n",aux->getCpfCliente().c_str());

		aux = aux->next;

	}
}