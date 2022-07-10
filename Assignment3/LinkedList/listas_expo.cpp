#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


struct Nodo {
	char nombre[20];
	float definitiva;
	Nodo *siguiente;

};

struct Lista {

	Nodo *inicio;
	int longitud;
};


//Prototipos de Funciones
Nodo* crearNodo(char nombre[20], float definitiva);
struct Lista* crearLista();
void eliminarLista(Lista *lista);
void visualizarLista(Lista *lista);
void insertarPrincipio(Lista *lista,  char nombre[100], float definitiva);
void insertarFinal(Lista *lista,  char nombre[100], float definitiva);
void insertarNodo(Lista* lista, int posicion, char nombre[20], float definitiva);
void visualizarEstudiante(Lista *lista, int posicion);
void eliminarFinal(Lista *lista);
void eliminarInicio(Lista* lista);
int longitudLista(Lista *lista);
void eliminarParticular(Lista *lista, int posicion);
void calcularPromedio(Lista* lista);


int main () {

	int flag=0,op=0;
	setlocale(LC_ALL, "spanish");
	Lista *lista=crearLista();

	do {
		printf ("\n[VISUALIZAR]\n");
		printf ("¤ Ingrese 1 para visualizar la lista\n");
		printf ("¤ Ingrese 2 para visualizar un estudiante de la lista\n");
		printf ("\n\n[AÑADIR]\n");
		printf ("¤ Ingrese 3 para añadir un estudiante al inicio de la lista\n");
		printf ("¤ Ingrese 4 para añadir un estudiante al final de la lista\n");
		printf ("¤ Ingrese 5 para añadir un estudiante en una posicion determinada de la lista\n");
		printf ("\n\n[ELIMINAR]\n");
		printf ("¤ Ingrese 6 para eliminar un estudiante al principio de la lista\n");
		printf ("¤ Ingrese 7 para eliminar un estudiante al final de la lista\n");
		printf ("¤ Ingrese 8 para eliminar un estudiante en una posicion determinada de la lista\n");
		printf ("\n\n[OTROS]\n");
		printf ("¤ Ingrese 9 para calcular el promedio de estudiantes de la lista\n");
		printf ("¤ Ingrese 10 para visualizar la cantidad de estudiantes de la lista\n");
		printf ("¤ Ingrese 11 para terminar la ejecución\n\n");
		
		do {
			scanf("%i", &op);
			if (op<=0 || op >11) {
				printf ("\nFavor ingrese una opción válida.");
			}
		} while(op<=0 || op >11);


		switch (op) {

			case 1: {

				visualizarLista(lista);
				break;

			}


			case 3: {

				fflush(stdin);
				char nombre[100];
				float definitiva=0;

				printf("\nIngrese el nombre del estudiante: ");
				fgets(nombre,20,stdin);
				printf("\nIngrese la definitiva del estudiante: ");
				scanf("%f", &definitiva);
				insertarPrincipio(lista,nombre,definitiva);
				printf("\nEstudiante añadido satisfactoriamente");
				fflush(stdin);
				break;
			}

			case 4: {

				fflush(stdin);
				char nombre[100];
				float definitiva=0;
				printf("\nIngrese el nombre del estudiante: ");
				fgets(nombre,20,stdin);
				printf("\nIngrese la definitiva del estudiante: ");
				scanf("%f", &definitiva);
				insertarFinal(lista,nombre,definitiva);
				printf("\nEstudiante añadido satisfactoriamente");
				fflush(stdin);
				break;
			}
			
			
			case 5: {
				
				fflush(stdin);
				char nombre[100];
				float definitiva=0;
				int posicion=0;
				printf("\nIngrese el nombre del estudiante: ");
				fgets(nombre,20,stdin);
				printf("\nIngrese la definitiva del estudiante: ");
				scanf("%f", &definitiva);
				printf("\nIngrese la posición donde desea almacenar al estudiante: ");
				scanf("%i", &posicion);
				insertarNodo(lista,posicion,nombre,definitiva);
				printf("\nEstudiante añadido satisfactoriamente", posicion);
				fflush(stdin);
				break;
				

			}
			
			
			case 2: {
				int posicion=0;
				fflush(stdin);
				printf("\nIngrese la posición del estudiante que desea visualizar: ");
				scanf("%i", &posicion);
				visualizarEstudiante(lista, posicion);
				
				break;
			}
			
			case 6: {
				
				eliminarInicio(lista);
				break;
			}
			
			case 7:{
				eliminarFinal(lista);
				break;
			}
			
			case 8:{
				int posicion=0;
				fflush(stdin);
				printf("\nIngrese la posición del estudiante que desea eliminarr: ");
				scanf("%i", &posicion);
				eliminarParticular(lista,posicion);
				break;
			}
			
			case 9: {
				
				calcularPromedio(lista);
				break;
			}
			
			case 10: {
				
				printf ("\n\nLa cantidad de estudiantes en la lista es de: %i", longitudLista(lista));
				break;
			}
			
			case 11:{
				return 0;
				break;
			}

		}

		printf("\n");
		system("pause");
		system("cls");
	} while(flag==0);

	system("pause");
	return 0;








}


//Longitud de la lista
int longitudLista(Lista *lista){
	return lista->longitud;
}

//Constructor lista
struct Lista* crearLista() {
	struct Lista* lista = new Lista();
	lista->inicio = NULL;
	lista->longitud = 0;
	return lista;
}

//Elimina Lista
void eliminarLista(Lista *lista) {
	delete lista;
}

//Crear Nodo
Nodo* crearNodo(char nombre[20], float definitiva) {

	Nodo *nuevoNodo = new Nodo();
	strncpy(nuevoNodo->nombre, nombre, 20);
	nuevoNodo->definitiva=definitiva;
	nuevoNodo->siguiente=NULL;
	return nuevoNodo;

}

//Eliminar Nodo
void eliminarNodo(Nodo *nodo) {
	delete nodo;

}

//Insertar Nodo al principio
void insertarPrincipio(Lista *lista,  char nombre[20], float definitiva) {

	Nodo *nodo = crearNodo(nombre, definitiva);
	nodo->siguiente=lista->inicio;
	lista->inicio=nodo;

	lista->longitud++;
}


//Insertar nodo al final
void insertarFinal(Lista* lista, char nombre[20], float definitiva) {
	Nodo*nodo = crearNodo(nombre,definitiva);
	if (lista->inicio == NULL) {
		
		lista->inicio = nodo;
	} else {
		Nodo* aux = lista->inicio;
		while (aux->siguiente) {
			aux = aux->siguiente;
		}
		aux->siguiente = nodo;
	}
	lista->longitud++;
}



//Muestra la lista por consola
void visualizarLista(Lista *lista) {

	if (lista->inicio == NULL) {
		printf("\n La lista está vacia.");

	} else {

		int i = 0;
		Nodo* aux = lista->inicio;
		while (i < lista->longitud) {
			printf ("\n\n	¤Posicion: %i", i);
			printf("\n	Nombre: %s", aux->nombre);
			printf("	Definitiva: %f ", aux->definitiva);
			aux = aux->siguiente;
			i++;
		}
	}

}

//Muestra los datos de la posición del estudiado ingresado por consola
void visualizarEstudiante(Lista *lista, int posicion) {

	if (lista->inicio == NULL) {
		printf("\n La lista está vacia.");

	} else {

		int i = 0;
		Nodo* aux = lista->inicio;
		while (i < posicion && aux->siguiente)  {
			aux = aux->siguiente;
			i++;
		}
		
		printf ("\n\n	¤Posicion: %i", i);
			printf("\n	Nombre: %s", aux->nombre);
			printf("	Definitiva: %.2f ", aux->definitiva);
			
	}

}


//Insertar nodo en posición específica
void insertarNodo(Lista* lista, int posicion, char nombre[20], float definitiva) {
	
	posicion-=1;
	
	Nodo*nodo = crearNodo(nombre,definitiva);
	if (lista->inicio == NULL) {
		
		lista->inicio = nodo;
	} else {
		
		Nodo* aux = lista->inicio;
		int i=0;
		
		while (i<posicion && aux->siguiente) {
			aux = aux->siguiente;
			i++;
		}
		nodo->siguiente=aux->siguiente;
		aux->siguiente = nodo;
		
		
	}
	lista->longitud++;
}


//Eliminar un nodo del inicio de la lista
void eliminarInicio(Lista* lista){
	
	if (lista->inicio == NULL) {
		printf("\n La lista está vacia.");

	} else {

		Nodo *eliminar=lista->inicio;
		lista->inicio=lista->inicio->siguiente;
		eliminarNodo(eliminar);
		lista->longitud--;
		printf ("\nEstudiante eliminado satisfactoriamente");
			
	}
	
}

//Eliminar un nodo al final de la lista
void eliminarFinal(Lista *lista){
	
	if (lista->inicio == NULL) {
		printf("\n La lista está vacia.");

	} else {
		if(lista->inicio->siguiente){
			Nodo *aux=lista->inicio;
			
			while(aux->siguiente->siguiente){
				aux=aux->siguiente;
			}
			
		Nodo *eliminar = aux->siguiente;
		aux->siguiente=NULL;
		eliminarNodo(eliminar);
		lista->longitud--;
		printf ("\nEstudiante eliminado satisfactoriamente");
		} else { //En caso que la lista tenga solo un elemento
			Nodo* eliminar = lista->inicio;
			lista->inicio=NULL;
			eliminarNodo(eliminar);
			lista->longitud--;
			
		  printf ("\nEstudiante eliminado satisfactoriamente");
		}
		
		
			
	}
	
}


void eliminarParticular(Lista *lista, int posicion){
	
	if (lista->inicio == NULL) {
		printf("\n La lista está vacia.");

	} else {
		if(posicion==0){
			Nodo* eliminar = lista->inicio;
			lista->inicio=NULL;
			eliminarNodo(eliminar);
			lista->longitud--;
			
		  printf ("\nEstudiante eliminado satisfactoriamente");
		} else if(posicion<lista->longitud){
			Nodo *aux = lista->inicio;
			int i=0;
			posicion-=1;
			while(i<posicion){
				aux=aux->siguiente;
				i++;
			}
			Nodo *eliminar = aux->siguiente;
			aux->siguiente=eliminar->siguiente;
			lista->longitud--;
			 printf ("\nEstudiante eliminado satisfactoriamente");
		}
			
		  
	}
		
		
			
}
	

void calcularPromedio(Lista* lista){
	if (lista->inicio == NULL) {
		printf("\n La lista está vacia.");

	} else {
		float promedio=0;
		int i = 0;
		Nodo* aux = lista->inicio;
		while (i < lista->longitud) {
			promedio+=aux->definitiva;
			aux = aux->siguiente;
			i++;
		}
		
		promedio=promedio/i;
		printf ("El promedio de los estudiantes en la lista es de: [%.2f]", promedio);
		
		
	}
}

















