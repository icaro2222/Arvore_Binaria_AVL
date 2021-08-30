/* THIS FILE WILL BE OVERWRITTEN BY DEV-C++ */
/* DO NOT EDIT ! */

#ifndef ARVORE_H
#define ARVORE_H

/* VERSION DEFINITIONS */
#define VER_STRING	"1.0.0.0"
#define VER_MAJOR	1
#define VER_MINOR	0
#define VER_RELEASE	0
#define VER_BUILD	0
#define COMPANY_NAME	""
#define FILE_VERSION	""
#define FILE_DESCRIPTION	"Developed using the Dev-C++ IDE"
#define INTERNAL_NAME	""
#define LEGAL_COPYRIGHT	""
#define LEGAL_TRADEMARKS	""
#define ORIGINAL_FILENAME	""
#define PRODUCT_NAME	""
#define PRODUCT_VERSION	""

#endif /*PEOPLE_TREE_H*/



//			Developed by: Ícaro days dos Santos


//           AVL TREE AND BINARY SEARCH TREE


//-------------------STRUCTs----------------------//
typedef struct date{
	
	int day, month, year;
	
}Date;

typedef struct people{
	
	Date dateBirth;
	Date dateNow;
	char name[30];
	char gender;
	char rg[11];
	long long int cpf;
	
}People;

typedef struct node{
	
	People people;
	int height;
	
	struct Node *left, *right;
	
}Node;

//-----------------height da TREE--------------------//
int heightNode(Node* node){
	
	if(node==NULL){
		return -1;
	}else{
		return node->height;
	}
}

//-----------------get TREE Balance --------------------//
int getbalance(Node* node){
	return labs(heightNode(node->left) - heightNode(node->right));
}

//-----------------BIGGER--------------------//
int bigger(int x, int y){
	
	//return (x>y) ? x : y ;
	if(x>y){
		return x;
	}else{
		return y;
	}
}

//-----------------rotation Left Left--------------------//
void rotationLL(Node **node){
	Node *aux;
	
	aux = (*node)->left;
	(*node)->left = aux->right;
	aux->right = *node;
	(*node)->height = bigger(heightNode((*node)->left), heightNode((*node)->right))+1;
	aux->height = bigger(heightNode(aux->left), (*node)->height)+ 1;
	*node = aux;
}

//-----------------rotation Right Right--------------------//
void rotationRR(Node **node){
	Node *aux;
	
	aux = (*node)->right;
	(*node)->right = aux->left;
	aux->left = *node;
	(*node)->height = bigger(heightNode((*node)->left), heightNode((*node)->right))+1;
	aux->height = bigger(heightNode(aux->right), (*node)->height)+ 1;
	*node = aux;
}

//-----------------rotation Left Right--------------------//
void rotationLR(Node **node){
	rotationRR(&(*node)->left);
	rotationLL(node);
}

//-----------------rotation Right Left--------------------//
void rotationRL(Node **node){
	rotationLL(&(*node)->right);
	rotationRR(node);
}

//-----------------INSERT INTO THE TREE AVL--------------------//

int scanNodeV2(Node **node, People people){
	
	int res;
	Node *aux2;
	aux2 = *node;
	
	Node *aux = malloc(sizeof(Node));
	
	if(!*node){
		
		aux->people = people;
		resetNode(aux);
		
		*node = aux;
		return 1;
		
	}else{
		
		Node *now = *node;
		
		if(people.cpf<(*node)->people.cpf){
			
			if((scanNodeV2(&(now->left), people))==1){
				
				if(getbalance(now) >= 2){
					
					if(people.cpf < aux2->people.cpf){
						rotationLL(node);
					}else{
						rotationLR(node);
					}
					
				}
			}
		}else{
			if(people.cpf>(*node)->people.cpf){
				
				if((res = scanNodeV2(&(now->right), people))==1){
				
					if(getbalance(now) >= 2){
						
						if(aux2->people.cpf<people.cpf){
							rotationRR(node);
						}else{
							rotationRL(node);
						}
						
					}
				}
			}else{
				
				printf("\n\tCPF >>>%lld, já existente:", now->people.cpf);
				
				printf("\n\t--------------Pessoa ja existe--------------\n");
				printfPeople(now->people);
			}
		}
	now->height = bigger(heightNode(now->left), heightNode(now->right))+1;
	
	return res;
	}
}

//-----------------IMPRESSIONS--------------------//
void printfDate(Date date){
	
	printf("\n\t%i/%i/%i", date.day, date.month, date.year);
	
}

void printfPeople(People people){
	
	printf("\n\tO nome é:%s", people.name);
	printf("\n\tO sexo: %c", people.gender);
	printf("\n\tRg: %s", people.rg);
	printf("\n\tCPF: %lld", people.cpf);
	printfDate(people.dateBirth);
	printfDate(people.dateNow);
	printf("\n\t---------------------------------------------\n");
	
}

void printfNode(Node *node){
	
	if(node){
		printfNode(node->left);
		printfPeople(node->people);
		printfNode(node->right);
		
	}
}

void printfNodeOrderedValue(Node *node){
	
	if(node){
		printfNode(node->left);
		printfNode(node->right);
		printfPeople(node->people);
		
	}
}

//-------------------SCANs------------------------//
People scanPeople(){
		
	People people;
	
	printf("\n\t\tDigite sua data de nascimento separando por barra:\n\t\t\t>>>");
	scanf("%i/%i/%i", &people.dateBirth.day, &people.dateBirth.month, &people.dateBirth.year);
	
	printf("\n\t\tDigite a data atual separando por barra:\n\t\t\t>>>");
	scanf("%i/%i/%i",&people.dateNow.day, &people.dateNow.month, &people.dateNow.year);
	printf("\n\t\tDigite o seu nome:\n\t\t\t>>>");
	scanf(" %29[^\n]", &people.name);
	printf("\n\t\tDigite 'M' para mascolino e 'F' para feminino:\n\t\t\t>>>");
	scanf(" %c", &people.gender);
	printf("\n\t\tDigite o seu RG:\n\t\t\t>>>");
	scanf(" %10[^\n]", &people.rg);
	printf("\n\t\tDigite o seu CPF:\n\t\t\t>>>");
	scanf("%lld", &people.cpf);
	return people;
}

void scanNode(Node **node, People people){
	
		
	Node *aux = malloc(sizeof(Node));
	
	if(!*node){
		
		aux->people = people;
		resetNode(aux);
		
		*node = aux;
		
	}else{
		
		if(people.cpf<(*node)->people.cpf){
			scanNode(&((*node)->left), people);
		}else{
			if(people.cpf>(*node)->people.cpf){
				scanNode(&((*node)->right), people);
			}else{
				printf("\n\tJá tem pessoa com esse CPF:");
				
				printf("\n\t--------------Pessoa ja existe--------------\n");
				printfPeople((*node)->people);
			}
		}
			
	}
}

//-----------REMOVE PERSON FROM TREE--------------//
Node* removeNode(Node *node, People people){
	
		
	if(node==NULL){
		
		printf("\n\tNão encotrado!");
		return NULL;
		
	}else{
		if(people.cpf==node->people.cpf){
			
			if(node->left == NULL && node->right == NULL){
				
				printf("\n\n\t--------------Pessoa que foi removida--------------\n");
				printfPeople(node->people);
				printf("\n\tRemovida com sucesso!\n");	
				free(node);
				return NULL;
			}else{
				if(node->left != NULL && node->right != NULL){
					People p;
					Node *aux = node->right;
					while(aux->left != NULL){
						aux = aux->left;
					}
					p = node->people;
					node->people = aux->people;
					aux->people = p;
					node->right = removeNode(node->right, p);
					
				}else{
					
					Node *aux;
					
					if(node->left!=NULL){
						aux = node->left;
					}else{
						aux = node->right;
					}
					printf("\n\n\t--------------Pessoa que foi removida--------------\n");
					printfPeople(node->people);
					printf("\n\tRemovida com sucesso!\n");	
					free(node);
					return aux;
				}
			}
		}else{
				
			if(people.cpf<node->people.cpf){
				node->left = removeNode(node->left, people);
			}else{
				node->right = removeNode(node->right, people);
				return node;
			}
				
		}
	}
}

//----------SEARCH FOR PERSON IN THE TREE---------//
void searchforperson(Node *node, People people){
	
	if(node==NULL){
		
		printf("\n\tNão encotrado!");
		
	}else{
		if(people.cpf==node->people.cpf){
			
			printf("\n\n\t--------------PESSOA ENCONTRADA--------------\n");
			printfPeople(node->people);
			
		}else{
				
			if(people.cpf<node->people.cpf){
				searchforperson(node->left, people);
			}else{
				searchforperson(node->right, people);
			}	
		}
	}
}

//------------------RESET TREE--------------------//
void resetNode(Node *node){
	if(node!=NULL){
	node->left = NULL;
	node->right = NULL;
	}
}

//----------------KEEP TREE FILE------------------//
int keepFile(Node *node){
	
	FILE *file = fopen("Arvore.txt", "a");
	if(file){
		
		if(node!=NULL){
		fprintf(file, "\n%s", node->people.name);
		fprintf(file, "%c\n", node->people.gender);
		fprintf(file, "%s\n%lld\n", node->people.rg, node->people.cpf);
		fprintf(file, "%i/%i/%i\n", node->people.dateBirth.day, node->people.dateBirth.month, node->people.dateBirth.year);
		fprintf(file, "%i/%i/%i\n", node->people.dateNow.day, node->people.dateNow.month, node->people.dateNow.year);
		
		keepFile(node->left);
		keepFile(node->right);
	}
		fclose(file);
		return 1;
	}else{
		printf("\n\nERRO\n\n");
		return 0;
	}
}

//-------------READ SAVED TREE FILE---------------//
void readFile(Node **node){
	
	People people;
	
	FILE *file = fopen("Arvore.txt", "r");
	if(file){
		
		while(!feof(file)){
			fscanf(file, "\n");
			fgets(people.name, 29, file);
			fscanf(file, "%c\n", &people.gender);
			fscanf(file, "%s\n%lld\n", &people.rg, &people.cpf);
			fscanf(file, "%i/%i/%i\n", &people.dateBirth.day, &people.dateBirth.month, &people.dateBirth.year);
			fscanf(file, "%i/%i/%i\n", &people.dateNow.day, &people.dateNow.month, &people.dateNow.year);
			
			scanNodeV2(node, people);
		}
		printf("\n\n\tSUCESSO!\n\n");
		fclose(file);
	}else{
		printf("\n\nERRO\n\n");
	}
}

//----------------RESET TREE FILE-----------------//
void resetFile(){
	
	FILE *arq = fopen("Arvore.txt", "w");
	
	printf("\n\n\tARQUIVO RESETADO!\n\n");
	fclose(arq);
}

//----------------HEIGHT TREE-----------------//
int height(Node *node){
	
	if(node==NULL){
		return -1;
	}else{
		int left = height(node->left);
		int right = height(node->right);
		
		if(left>right){
			return left + 1;
		}else{
			return right + 1;
		}
	}
	
}

//----------------COUNT NODE TREE-----------------//
int countNode(Node *node){
	
	if(node==NULL){
		
		return 0;
		
	}else{
		return 1 + countNode(node->left) + countNode(node->right);
	}
}

//----------------LEAF TREE-----------------//
int countLeaf(Node *node){
	
	if(node==NULL){
		
		return 0;
		
	}else{
		if(node->left == NULL && node->right == NULL){
			
			return 1;
			
		}else{
			
			return countLeaf(node->left) + countLeaf(node->right);
			
		}
	}
}





