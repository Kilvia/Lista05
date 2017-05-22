#include "ListaDuplEncad.h"
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
	if(quantElem == 0){

		head = novo;

		quantElem++;

		return;
	}

	if(posi == 0) { // inicio da lista
		
		aux->prev = novo;

		novo->next = aux;

		head = novo;

		quantElem++;
		
		return;
	}

	while(i < quantElem ) {
		
		if(i == (posi-1)){
			
			if(aux->next == NULL){ // quando for inserir no final da lista
		
				aux->next = novo;
			
				novo->prev = aux;

				quantElem++;

				return;
			}

			aux->next->prev = novo;

			novo->next = aux->next;

			novo->prev = aux;

			aux->next = novo;

			quantElem++;
			
			return;
		}

		i++;

		aux = aux->next;
	}
}	

Cliente Lista::removerCliente(int posi){

	int i = 0;

	Cliente *aux = head;
	
	Cliente *aux1;

	if(posi == 0 && quantElem == 1){
		
		aux1 = aux;
			
		head = NULL;

		quantElem--;

		aux = NULL;
		
		delete(aux);

		return *aux1;

	}

	while(i < quantElem){

		if(posi == 0){
		
			aux1 = head;
			
			head = head->next;
		
			aux->next->prev = NULL;
		
			aux1->next = NULL;
		
			quantElem--;
		
			return *aux1;
		}
		
		if (i == (posi - 1)){
		
			if(posi == (quantElem - 1)){
				
				aux1 = aux->next;
				
				aux->next->prev = NULL;
				
				aux->next = NULL;
					
				quantElem--;
				
				aux = NULL;
				
				delete(aux);

				return *aux1;	

			}
				
			aux1 = aux->next;

			aux->next = aux->next->next;

			aux->next->prev = aux->prev;
			
			aux->next->prev = NULL;
			
			quantElem--;
	
			aux = NULL;
			
			delete(aux);

			return *aux1;	
		}
		
		i++;

		aux = aux->next;
	}
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

	for(i = 0; i < times; i++){

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
		
		printf("CPF: %s\n",aux->getCpfCliente().c_str());

		aux = aux->next;
	}
}