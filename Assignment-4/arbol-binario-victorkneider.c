#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>






typedef struct nodo{
	struct nodo *izq;
    int hijosIzq;
    struct nodo *padre;
    int dato;
    int hijosDer;
    struct nodo *der; 
}Nodo;


typedef struct arbol{
	int totalIzq;
    Nodo *raiz;
    int totalDer;
}Arbol;



Nodo* crearNodo(int dato){
	Nodo *aux=(Nodo*) malloc(sizeof(Nodo));
    aux->izq=NULL;
    aux->padre=NULL;
    aux->der=NULL;
    aux->hijosIzq=0;
    aux->hijosDer=0;
    aux->dato=dato;
    return aux;
}




Arbol* crearArbol(){
	Arbol *aux=(Arbol*)malloc(sizeof(Arbol));
    aux->totalIzq=0;
    aux->totalDer=0;
    aux->raiz=NULL;
    return aux;
}

int estaVacioElArbol(Arbol *a){
	if(a->raiz==NULL){
		return 1;
	}else{
		return 0;
	}
}

void insertarNodo(Arbol *a,Nodo *n){
	Nodo *aux,*ant;
	if(estaVacioElArbol(a)){
		a->raiz=n;
	}else{
		aux=a->raiz;
		while(aux!=NULL){
			ant=aux;
			if(n->dato > aux ->dato){
				aux=aux->der;
			}else{
				aux=aux->izq;
			}
		}
		n->padre=ant;
		if(n->dato > ant->dato){
			ant->der=n;
		}else{
			ant->izq=n;
		}
	}
}

void imprimirNodo(Nodo *n){
	if(n!=NULL){
		printf(" %d ",n->dato);
		imprimirNodo(n->izq);
		imprimirNodo(n->der);
	}
}

void imprimir(Arbol *a){
	if(estaVacioElArbol(a)){
		printf("Arbol vacio");
	}else{
		imprimirNodo(a->raiz);
	}
}



int main(){
	Arbol *a=crearArbol();	//Se crea el arbol
	int x=0; // Variable para el loop
	
	
	do{
		
		
	printf("\nMenu de Opciones - Arbol Binario Victor Kneider");
	printf ("\nIngrese 1 para añadir un nodo al arbol");
	printf ("\nIngrese 2 para visualizar los valores de los nodos");
	printf ("\nIngrese 3 para salir\n\n\n");
	
	int op=0;	
	int valor=0;
	do{
		
		scanf("%i", &op);
		
		if(op<1 | op > 3){
			printf("\n Ingrese una opción valida");
		} else {
			
			
			
			
			switch (op){
				
				
				case 1: {
					
					
					printf ("\nIngrese un numero entero para añadir al arbol: ");
					scanf ("%i", &valor);
					
					insertarNodo(a,crearNodo(valor));
					
					
					
					break;
				}
				
				case 2:
				{
					
					
					imprimir(a);
					break;
					
					
				}
				
				
				case 3:{
					return 0;
					break;
				}
				
				
			}
			
			
		
			
		}
		
		printf("\n\n\n");
		system("pause");
		system("cls");
		
		
	}while(op<1 | op > 3);	
		
		
		
		
		
	}while(x==0);

}



