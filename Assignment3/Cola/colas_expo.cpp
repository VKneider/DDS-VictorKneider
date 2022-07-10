// Programa para calcular el promedio de alumnos de una sección tomando en cuenta sus definitivas y utilizando colas.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>


struct Estudiante {
	float definitiva;
	char nombre[80];
};

struct Nodo {
	Estudiante e;
	Nodo *siguiente;

};


//Prototipos de las Funciones
void insertarDato(Nodo *&inicio, Nodo *&fin, Estudiante &e);
int verificarCola(Nodo *inicio);
void crearEstudiante(Estudiante &e);
void mostrarCola(Nodo *&inicio);
void eliminarDato(Nodo *&inicio,Nodo *&fin,Estudiante &e);
float obtenerPromedio(Nodo *&inicio);



//Función principal o Main
int main() {
	
	setlocale(LC_ALL, "spanish");
	int flag=0,op=0;
	//"Estructura" Cola
	Nodo *inicio = NULL;
	Nodo *fin = NULL;
	Estudiante e;
	
                                 
	do {
		
		printf (" .d8888b.           888                  \n");
		printf ("d88P  Y88b          888                   \n");
		printf ("888    888          888                   \n");
		printf ("888         .d88b.  888  8888b.  .d8888b  \n");
		printf ("888        d88  88b 888     888b 88K     \n");
		printf ("888    888 888  888 888 .d888888 Y88888b. \n");
		printf ("Y88b  d88P Y88..88P 888 888  888      X88 \n");
		printf (" YY8888PP   YY88PP  888 Y8888888  8888888 \n\n");
		
		
		printf ("¤ Ingrese 1 para visualizar la cola\n");
		printf ("¤ Ingrese 2 para añadir un estudiante a la cola\n");
		printf ("¤ Ingrese 3 para eliminar un estudiante de la cola la cola\n");
		printf ("¤ Ingrese 4 para calcular el promedio de la sección\n");
		printf ("¤ Ingrese 5 para finalizar la ejecución\n\n");

		do{
			scanf("%i", &op);
			if (op<=0 || op >5) { printf ("\nFavor ingrese una opción válida."); } 	
		}while(op<=0 || op >5);
	
		
		switch (op) {

			case 1:
				{
				int flagCase=verificarCola(inicio);
				if(flagCase == 1){ printf ("\nLa cola está vacia\n"); 
				
				break;
				} else {mostrarCola(inicio);
					break;	}	
				
					}
	
				
				
			
			case 2:
				{
				crearEstudiante(e);
				insertarDato(inicio,fin,e);
				printf("\nEstudiante añadido satisfactoriamente");
				break;	
				}
				
			
			case 3:{
				int flagCase=verificarCola(inicio);
				if(flagCase == 1){ printf ("\nLa cola está vacia\n"); 
				break;} else {
				eliminarDato(inicio,fin,e);
				break;	
				}
				
			}
			
			case 4:{
				
				int flagCase=verificarCola(inicio);
				if(flagCase == 1){ printf ("\nLa cola está vacia\n"); 
				break;} else {
					
				float promedio=obtenerPromedio(inicio);
				printf ("El promedio de la sección es de [%f] puntos", promedio);
				
				break;	
				}
				
				
			}
			
			case 5:{
				
				printf ("\n Ejecución Finalizada\n");
				system("pause");
				return 0;
			}
	
		}

	printf("\n");
	system("pause");
      system("cls");
	} while(flag==0);

	system("pause");
	return 0;




}

float obtenerPromedio(Nodo *&inicio){
	float promedio=0;
	int i=0;
		Nodo *aux = inicio;
		while(aux != NULL){
				promedio+=aux->e.definitiva;
				aux=aux->siguiente;
				i++; }
	return promedio/i;
				
}

void crearEstudiante(Estudiante &e) {
	
	fflush(stdin);
	printf ("\n\n• Ingrese el nombre del estudiante: ");
	fgets(e.nombre,80,stdin);

	printf ("\n\n• Ingrese la definitiva del estudiante: ");
	scanf("%f", &e.definitiva);
}



void insertarDato(Nodo *&inicio, Nodo *&fin, Estudiante &e ) {
	Nodo *nuevoNodo = new Nodo();

	nuevoNodo->e=e;	//El nuevo nodo apunta al tipo de dato de la struct y se le asigna el valor del string nombre
	nuevoNodo->siguiente=NULL; //Apuntamos a la struct y al siguiente le asignamos NULL

	if(verificarCola(inicio) == 1 ) {
		inicio = nuevoNodo; //Si la cola está vacía, se asigna el inicio al nuevo nodo
	} else {
		fin->siguiente=nuevoNodo; //Si la cola no está vacia, asignamos el final al nuevo nodo agregado
	}
	fin = nuevoNodo;




}


int verificarCola(Nodo *inicio) {

	return (inicio==NULL)? 1 : 0; //Si inicio=NULL, retorna 1.


}



void eliminarDato(Nodo *&inicio,Nodo *&fin,Estudiante &e) {
	e = inicio->e;
	Nodo *aux = inicio;

	if(inicio == fin) {
		inicio = NULL;
		fin = NULL; //Si solo hay un dato, este se elimina y ambos pasan a ser NULL.
	} else {
		inicio = inicio->siguiente; //El inicio se mueve un puesto
	}

	delete aux;
}





void mostrarCola(Nodo *&inicio){

	Nodo *aux = inicio;
		while(aux != NULL){
				
				printf("\nNombre: %s", aux->e.nombre);
				printf("Definitiva: %f", aux->e.definitiva);
				aux=aux->siguiente;
				
	
}

}


