#include "stdafx.h"
#include <string.h>
#include "corrector.h"
#include <stdlib.h>
#include <ctype.h>
#define LONGITUD 32
/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/
void Diccionario(char* szNombre, char szPalabras[][TAMTOKEN], int iEstadisticas[], int& iNumElementos)
{
	/*
	//Sustituya estas lineas por su código
	iNumElementos = 1;
	strcpy(szPalabras[0], "AquiVaElDiccionario");
	iEstadisticas[0] = 1; // la primer palabra aparece solo una vez.*/

	/* Variable de archivo*/
	FILE* fp;
	iNumElementos = 0;

	/*Variable = i*/
	int i;
	

	/*Variables para que usaremos para guardar los datos */
	char lectura, array[TAMTOKEN];

	/*Aca era el problema*/
	//Para iniciar el arreglo de estadisticas.
	for (i = 0; i < NUMPALABRAS; i++)
		iEstadisticas[i] = 0;

	/*Se abre el archivo en modo lectura*/
	fopen_s(&fp, szNombre, "r");

	/*Variable */
	int contador = 0;

	/*Variable para el puntuacion <<Esto nos servira para conocer las palabras>> */
	char puntuacion[] = " \t\n\r.,;() ";

	//char puntuacion2[] = { ',',';','.','(',')',9,10,13,32 } ;

	/*Comprobamos que de verdad abrio*/
	if (fp == NULL)
		return;

	/*Mientras que la lectura sea igual al fichero (sea diferente a fin del documento */
	while ((lectura = fgetc(fp)) != EOF) {

		/*Declaramos una bandera*/
		/*Nota: bandera = flag*/
		bool bandera = true;

		/*Para pasar las mayusculas a minusculas*/
		lectura = tolower(lectura);

		/*Comprobar que no hay palabras con signo de puntuación */
		for (i = 0; i < strlen(puntuacion); i++)

			/*Compara si el caracter que recibió si esta dentro de la lectura o es un signo de puntuación*/
			if (puntuacion[i] == lectura)
				bandera = false;

		/*Si count es menor que TAMTOKEN Y de la bandera <<Continuar>> */
		if (contador < TAMTOKEN && bandera) {
			/*De lectura guardarlo al array*/
			array[contador++] = lectura;
			continue;
		}
		/* Si no(si es count el igua a cero <<Continuar>> */
		else if (contador == 0)
			continue;

		/*Si no(si es count el igua a 1, asignar 0 a count. <<Continuar>> */
		else if (contador == 1 && bandera) {
			contador = 0;
			continue;
		}
		/*Cuando las encuentre marcar un espacio*/
		array[contador] = '\0';

		/*Despues de comprobar en el abecedario y la puntuacion */
		for (i = 0; i < iNumElementos && !bandera; i++) {

			/*Aqui se hace la comparacion de las palabras*/
			if (strcmp(szPalabras[i], array) == 0) {
				/*Hacerlo hasta formar la palabra*/
				iEstadisticas[i]++;
				bandera = true;
			}
		}
		/*Si es diferente de la bandera*/
		if (!bandera) {
			/*Pasar todos los palabras que estan en el array a szPalabras[]*/
			strcpy_s(szPalabras[iNumElementos], array);
			iEstadisticas[iNumElementos++]++;

		}/*Para retornar*/
		contador = 0;
	}/*Fin del while o el documento*/
	fclose(fp);

	 
	//iEstadisticas[iNumElementos] = 1;

	/*Método burbuja para el ordenamiento*/
	for (int j = 0; j < iNumElementos - 1; j++) {

		for (i = j + 1; i < iNumElementos; i++) {

			if (strcmp(szPalabras[j], szPalabras[i]) > 0) {
				strcpy_s(array, szPalabras[j]);
				strcpy_s(szPalabras[j], szPalabras[i]);
				strcpy_s(szPalabras[i], array);
				contador = iEstadisticas[j];
				iEstadisticas[j] = iEstadisticas[i];
				iEstadisticas[i] = contador;
			}
		}
	}
}









/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/












/*****************************************************************************************************************
	ListaCandidatas: Esta funcion recupera desde el diccionario las palabras validas y su peso
	Regresa las palabras ordenadas por su peso
	char	szPalabrasSugeridas[][TAMTOKEN],	//Lista de palabras clonadas
	int		iNumSugeridas,						//Lista de palabras clonadas
	char	szPalabras[][TAMTOKEN],				//Lista de palabras del diccionario
	int		iEstadisticas[],					//Lista de las frecuencias de las palabras
	int		iNumElementos,						//Numero de elementos en el diccionario
	char	szListaFinal[][TAMTOKEN],			//Lista final de palabras a sugerir
	int		iPeso[],							//Peso de las palabras en la lista final
	int &	iNumLista)							//Numero de elementos en la szListaFinal
******************************************************************************************************************/