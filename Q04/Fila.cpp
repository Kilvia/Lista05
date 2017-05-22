#include "Fila.h"
#include "Cliente.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

Fila::Fila(){
	
	criarFila();
}


void Fila::criarFila(){
	
	head = NULL;

	quantElem = 0;
}

void Fila::adicionarCliente(string nome, string cpf){

	int i = 0;

	Cliente *aux = head;

	Cliente *novo = new Cliente(nome,cpf);

	if(quantElem == 0){

		head = novo;

		quantElem++;

		return;
	}

	while(i < quantElem){

		if(i == (quantElem - 1)){

			aux->next = novo;

			quantElem++;

			break;
		}

		i++;

		aux = aux->next;
	}

}

void Fila::imprimirFila( ){
 
	int i;

	printf("\tElementos da Fila\n");

	Cliente *aux = head;

	printf("Quantidade de Elementos: %d\n", quantElem);

	for(i = 0; i <= (quantElem - 1); i++){ 

		printf("\n");
	
		printf("Cliente: %s\n", aux->getNomeCliente().c_str());

		printf("CPF: %s\n",aux->getCpfCliente().c_str());

		aux = aux->next;

	}
}

Cliente Fila::removerCliente(){

	Cliente *aux = head;

	head = head->next;

	aux->next = NULL;

	quantElem--;

	return *aux;

}

void Fila::deletarFila(){

	int i;

	int times = quantElem;

	for(i = 0; i < times; i++ ){

		removerCliente();
	}
}