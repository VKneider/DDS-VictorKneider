#include <stdio.h>

int main(){
	
	int cantidad=0;
	printf("Ingrese la cantidad de mediciones realizadas: ");
	scanf ("%i", &cantidad);
	
	float *teorica= new float[cantidad];
	float *experimental= new float[cantidad];
	float *error = new float[cantidad];
	
	for (int i=0;i<cantidad;i++){
		printf ("\nIngrese la medición teórica nro[%i]: ", i);
		scanf ("%f",&teorica[i]);
	}


	for (int i=0;i<cantidad;i++){
		printf ("\nIngrese la medición experimental nro[%i]: ", i);
		scanf ("%f",&experimental[i]);
	}
	
	for (int i=0;i<cantidad;i++){
		error[i]=(experimental[i]-teorica[i])*(experimental[i]-teorica[i]);
		printf ("\nError cuadrado medición [%i] : [%f]", i, error[i]);
	}
	
	delete[] teorica;
	delete[] experimental;
	delete[] error; 
	return 0;
		
}
