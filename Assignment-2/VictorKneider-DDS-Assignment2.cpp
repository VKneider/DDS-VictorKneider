#include <stdio.h>
#include <stdlib.h>
int n=0;

void equiposGanadores(int n, int verificador[]){
	
	
		for (int i=0; i < n ; i++){
		
		if (verificador[i] == 1){ 
		printf ("\n El equipo [%i] pasa a la siguiente ronda ", i+1);}
		
		} 
		
}	


void ganadorRonda(int n, int puntuacion[]){
	
	int mayor=0;
	int bandera=0;
	
	
	for (int i=0; i < n ; i++){
		
		if (puntuacion[i]>mayor){
			mayor=i;
		}
	} 
		


	for (int i=0; i<n; i++){
		if (puntuacion[i] == puntuacion[mayor]) {
			bandera++;
		}
		
	}
	
	if (bandera>1){
		
		printf ("\n\nLos equipos");
	for (int i=0; i<n; i++){
		if (puntuacion[i] ==  puntuacion[mayor]) {
			printf (" %i ", i+1);
		}
		
	}
		printf (" obtuvieron la misma puntuacion [%i] ", puntuacion[mayor]);
	} else {
		
		printf ("\n\n El ganador de la ronda es el equipo [%i] con una puntuacion de [%i]", mayor+1, puntuacion[mayor]);
	}
	
}


int main (){
	
	 
	 printf ("Ingrese la cantidad de equipos participantes: ");
	 scanf ("%i", &n);
	 

	 int* puntuacion= (int*)malloc(n*sizeof(int));
	 int* verificador= (int*)malloc(n*sizeof(int));
	 
	
	
	for (int i=0; i < n ; i++){
		printf ("\nIngrese la puntuacion del equipo [%i] : ", i+1);
		scanf ("%i", &puntuacion[i]);
	}
	
	
	for (int i=0; i < n ; i++){
		
		if (puntuacion[i] >= 5){ 
		verificador[i]=1;	
		
		} 	
			else { verificador[i]=0;}
			
	}
	
	equiposGanadores( n,  verificador);
	ganadorRonda(n, puntuacion);
	printf ("\n");
	system("pause");
	
	free (puntuacion);
	free (verificador);
	return 0;
	
}
