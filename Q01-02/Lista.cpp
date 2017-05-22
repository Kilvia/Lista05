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

void Lista::inserirCliente(string nome, string cpf, int posi){
	
	int i = 0;

	Cliente *aux = head;

	Cliente *novo = new Cliente(nome, cpf);

	// Lista vazia
	if(quantElem == 0) {

		head = novo;

		novo->next = NULL;

		quantElem++;

		aux = NULL;

		delete(aux);

	}else{ 

		while(i <= (quantElem - 1)) {

			if(i == (posi -1)){

				novo->next = aux->next;

				aux->next = novo;

				aux = NULL;

				delete(aux);

				quantElem++;
				
				break;
			}

			i++;

			aux = aux->next;
		}
	}
}	

Cliente Lista::removerCliente(int posi){
	int i = 0;

	Cliente *aux = head;
	Cliente *aux1;

	if(posi == 0){

		aux1 = head;

		head = head->next;

		aux1->next = NULL;
						
		quantElem--;
	
		aux = NULL;
		delete(aux);

		return *aux1;
	}

	while(i <= (quantElem - 1)){

		if (i == (posi - 1)){
			
			aux1 = aux->next;
			
			aux->next = aux->next->next;
			
			aux1->next = NULL;
			
			quantElem--;

			break;

		}
		
		i++;

		aux = aux->next;
	
	}

	aux = NULL;
	delete(aux);

	return *aux1;	
}	

int Lista::buscarCliente(string nome, string cpf){

	int i = 0;

	Cliente *aux = head;

	while(i < (quantElem - 1)){

		if(nome == aux->getNomeCliente() && cpf == aux->getCpfCliente()){
					
			return i;
		}	

		i++;

		aux = aux->next;
	}
	return -1;
	}

void Lista::deletarLista(){

	int i;

	int times = quantElem;

	for(i = 0 ; i < times ; i++){

		removerCliente(0);

	}	
}


void Lista::imprimirLista( ){
 
	int i;

	printf("\tElementos da Lista\n");

	Cliente *aux = head;

	printf("%d\n", quantElem);

	for(i = 0; i <= (quantElem - 1); i++){ 
	
		printf("Cliente: %s\n", aux->getNomeCliente().c_str());

		//cout << name << endl;
		
		printf("CPF: %s\n",aux->getCpfCliente().c_str());

		aux = aux->next;
	}
}