#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <locale.h>
#include "Arvore.h" //LIBRARY WITH ALL FEATURES.

//DEVELOPED BY: Ícaro dais dos Santos

//--------------------MAIN------------------------//
int main(void) {
	
	setlocale(LC_ALL, "portuguese");
	
	int option, result;
	Node aux, *node = NULL;
	
	resetNode(node);
	
	do{
		
	 	printf("\n\n\tDigite uma opcao:");
	 	printf("\n\n\t1- Inserir Pessoa:");
	 	printf("\n\t2- Imprimir Pessoas por CPF:");
	 	printf("\n\t3- Imprimir Pessoas :");
	 	printf("\n\t4- Remover Pessoa:");
	 	printf("\n\t5- Procurar Pessoa:");
	 	printf("\n\t6- Salvar Arvore:");
	 	printf("\n\t7- Ler Arvore Salva:");
	 	printf("\n\t8- Resetar Arvore Salva:");
	 	printf("\n\t9- Altura da arvore:");
	 	printf("\n\t10- Nos na arvore:");
	 	printf("\n\t11- Folhas na arvore:");
	 	printf("\n\t12- Inserir Pessoa na Arvore AVL:");
	 	printf("\n\t13- Versão:");
	 	printf("\n\t0- Sair:\n\n\t\t\t>>>");
		scanf("%i", &option);
	 	system("cls");
	 	
	 	switch(option){
	 		case 1:
	 			aux.people = scanPeople();
	 			scanNode(&node, aux.people);
	 		break;
	 	
	 		case 2:
				printf("\n\n\t--------------Arvore de Pessoas--------------\n");
				printfNode(node);
				printf("\t-------------------FINAL---------------------");
	 		break;
	 		
	 		case 3:
				printf("\n\n\t--------------Arvore de Pessoas--------------\n");
				printfNodeOrderedValue(node);
				printf("\t-------------------FINAL---------------------\n");
	 		break;
	 		
	 		case 4:
				printf("\n\n\t\tDigite o cpf da pessoa que voce deseja remover da arvore?\n\t\t>>>");
				scanf("%lld",&aux.people.cpf);
				node = removeNode(node, aux.people);
	 		break;
	 		
	 		case 5:
				printf("\n\n\t\tDigite o cpf da pessoa que voce deseja procurar na arvore?\n\t\t>>>");
				scanf("%lld",&aux.people.cpf);
	 			searchforperson(node, aux.people);
	 		break;
	 		
	 		case 6:
			 	result = keepFile(node);
			 	if(result==1){
			 		printf("\n\n\tSALVO COM SUCESSO!\n\n");
				 }else{
			 		printf("\n\n\tNÃO FOI POSSÍVEL SALVAR O ARQUIVO!\n\n");
				 }
	 		break;
	 		
	 		case 7:
			 	readFile(&node);
	 		break;
	 		
	 		case 8:
			 	resetFile();
	 		break;
	 		
	 		case 9:
			 	printf("\n\t a height é de %i ", height(node));
	 		break;
	 		
	 		case 10:
			 	printf("\n\tPossui %i nos\n", countNode(node));
	 		break;
	 		
	 		case 11:
			 	printf("\n\tPossui %i Folhas\n", countLeaf(node));
	 		break;
	 		
	 		case 12:
	 			aux.people = scanPeople();
				result = scanNodeV2(&node, aux.people);
	 		break;
	 		
	 		case 13:
			 	printf("\n\t........................................................");
			 	printf("\n\t........................................................");
			 	printf("\n\t....##........##....######.......##........##...........");
			 	printf("\n\t....##........##.......##.......##.......####...........");
			 	printf("\n\t.....##......##.......##.......##..........##...........");
			 	printf("\n\t.....##......##....####.......######.......##...........");
			 	printf("\n\t......##....##........##......##...##......##...........");
			 	printf("\n\t.......##..##.........##......##...##......##...........");
			 	printf("\n\t........####......#####....##..#####....########........");
			 	printf("\n\t........................................................");
	 		break;
	 		
	 		
	 		
		 }
	}while(option!=0);
	
	
	
	return 0;
}

