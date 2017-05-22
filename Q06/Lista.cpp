#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

Lista::Lista(){
	criarLista();
}


void Lista::criarLista(){
	head = NULL;
	quantElem = 0;
}

void Lista::deletarLista(){
	int i;
	int times = quantElem; // holds the number of elements at the beginning of the operation

	for (i = 0; i < times; i++)
	{
		removerCliente(0);
	}
}


Cliente *Lista::getLastElement()
{
	int i = 1;
	Cliente *aux = head;

	while(i <= quantElem){
		if(i == quantElem)
			return aux;
		i++;
		aux = aux->next;
	}
}

void Lista::inserirCliente(string nome, string cpf, int posi){
	
	int i = 0;

	Cliente *aux = head;
	Cliente *aux_tail = getLastElement();

	Cliente *novo = new Cliente(nome, cpf);

	if(quantElem == 0) { // empty list
		head = novo;

		quantElem++;

	} else if(posi == 0) { // insert in the beginning 
		novo->next = head;
		aux_tail->next = novo;
		head = novo;

		quantElem++;
		
	} else { // insert at any other position
		while(i < quantElem) {

			if(i == (posi - 1)) {

				novo->next = aux->next;
				aux->next = novo;

				quantElem++;
				break;
			}

			i++;
			aux = aux->next;
		}
	}


	aux = aux_tail = novo = NULL;
	delete(aux);
	delete(aux_tail);
	delete(novo);
}

Cliente Lista::removerCliente(int posi) {
	if(posi >= quantElem){ // avoid segmentation error with position is higher 
					// than the number of elements on the list
		Cliente *null_cliente = new Cliente("", "");
		return *null_cliente;	
	}

	int i = 0;

	Cliente *aux = head;
	Cliente *aux_tail = getLastElement();
	
	Cliente *temp;

	if(posi == 0) { // remove from beginning
		temp = aux;
		aux_tail->next = aux->next;
		head = aux->next;
		temp->next = NULL;

		quantElem--;
	
	} else { // remove at any other position
		while(i <= (quantElem - 1)) {

			if (i == (posi - 1)) {
				temp = aux->next;
				aux->next = temp->next;
				temp->next = NULL;
			
				quantElem--;
				break;
			}
			
			i++;
			aux = aux->next;
		}
	}


	aux = aux_tail = NULL;
	delete(aux);
	delete(aux_tail);

	return *temp;	
}	

int Lista::buscarCliente(string nome, string cpf){
	int i = 0;
	Cliente *aux = head;

	while(i < (quantElem - 1)){
		if(nome.compare(aux->getNomeCliente()) == 0 
			&& cpf.compare(aux->getCpfCliente()) == 0) {	
			return i + 1; // add +1 cause we start counting from 0
		}	

		i++;
		aux = aux->next;
	}

	return 0; // return -1 with no correspond element was found
}

void Lista::imprimirLista( ){
 
	int i;
	Cliente *aux = head;

	if (quantElem == 0) {
		printf("Lista vazia\n");
		return;
	}

	printf("Elementos da Lista\n");
	printf("---------------------- \n"); 

	// printf("%d\n", quantElem);

	for(i = 0; i <= (quantElem - 1); i++) {
		printf("Cliente: %s\n", aux->getNomeCliente().c_str());
		printf("CPF: %s\n",aux->getCpfCliente().c_str());
		printf("---------------------- \n"); 
		aux = aux->next;
	}
}