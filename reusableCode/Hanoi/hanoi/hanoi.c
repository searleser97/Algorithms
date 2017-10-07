#include<stdio.h>
#include"presentacion.h"
#include"TADPilaEst.h"

//Variables Globales
pila pilares[3]; //Declarar un arreglo "pilares" de tipo pilas (o sea que en cada localidad del arreglo hay una estructura pila)
pila pilares_auxiliares[3];//Pilares que ayudan a almacenar el contenido de la pila "pilares"
elemento disco; //Variable global elemento disco

//Funcion void para imprimir los tres pilares
void imprimir_pilares()
{
	int i, j, caracter_cuadro = 220;

	printf("\n\n\n");

	for (i = 0; i < 3; i++) //Iterar entre los pilares
	{
		while (!Empty(&pilares[i]))//Mientras tenga algo el pilar en el cual se itera
		{
			disco = Top(&pilares[i]);//Obtener el disco del pilar en el cual se itera
			Pop(&pilares[i]);//Desempilar el disco del pilar en el cual se itera
			Push(&pilares_auxiliares[i], disco);//Respaldar ese disco en otro pilar auxiliar

			//Nota: Lo anterior se hizo con el fin de poder ir imprimiendo todos los discos que contiene el pilar y no perderlos al desempilar

			for (j = 1; j <= disco.dim_disco; j++)
			{
				printf("%c", caracter_cuadro);//Imprimir un "caracter cuadro" a partir de
			}								  //de la dimension del disco en uso	

			printf("\n");
		}

		printf("=============%c\n", i+'A');//Imprimir la base de cada pilar con su letra respectiva

		while (!Empty(&pilares_auxiliares[i]))//Este while es para devolver los discos que se almacenaron 
		{									  //en los pilares auxiliares y ponerlos en su pilar original
			disco = Top(&pilares_auxiliares[i]);
			Pop(&pilares_auxiliares[i]);
			Push(&pilares[i], disco);
		}

		printf("\n\n\n");
	}
}
//funcion para mover los discos, recibe un pilar origen y un pilar destino
void mover_discos(int origen, int destino)//Funcion para mover los discos de un pilar "origen" a un pilar "destino"
{
	disco = Top(&pilares[origen]);//Obtener el disco del tope de la pila origen
	Pop(&pilares[origen]);//Desempilar un disco del pilar origen
	Push(&pilares[destino], disco);//Empilar el disco en su pilar destino
}

//funcion recursiva de hanoi, recibe numero de discos, pilares, origen, auxiliar y destino
void hanoi(int num_discos, int origen, int auxiliar, int destino)//Funcion que resuelve el problema de hanoi
{

	if (num_discos == 1)//Caso base donde solo hay un disco por mover
	{
		mover_discos(origen, destino);//En caso de que haya un disco disponible para moverlo directamente de origen (Pilar A)
									  //a destino (Pilar C)

		imprimir_pilares();//Llamar a la funcion imprimir pilares
		EsperarMiliSeg(2000);//Esperar 2 segundos 
		BorrarPantalla();
	}
	else//Caso recursivo
	{
		//Originalmente tenemos...
							//origen auxiliar destino
		hanoi(num_discos - 1, origen, destino, auxiliar);//Llamar a la funcion hanoi para que resuelva la piramide parcial de discos
														 //sin el disco "mas grande (El de hasta abajo)". Esta piramide parcial queremos
														 //que la coloque de origen(Pilar A) y ahora el nuevo destino será el auxiliar (Pilar B)

		mover_discos(origen, destino);//Como ya se movio toda la piramide parcial a un pilar auxiliar, ya podemos mover el disco
									  //de hasta abajo al verdadero destino (Pilar C)
		
		imprimir_pilares();//Llamar a la funcion imprimir pilares
		EsperarMiliSeg(2000);//Esperar 2 segundos 
		BorrarPantalla();

		//Originalmente tenemos...
							//origen auxiliar destino
		hanoi(num_discos - 1, auxiliar, origen, destino);//Llamar otra vez a hanoi para que nos resuelva otra piramide parcial pero ahora en otro
														 //auxiliar para que el disco mas abajo de esta la podamos mover al (Pilar c)
		
		//Nota: Estas llamadas recursivas las hacemos hasta llegar al caso base decrementando num_discos
	}

}

int main()
{
	int s, radio_discos;
	int num_discos, origen, auxiliar, destino;

	origen = 0;//Pilar A
	auxiliar = 1;//Pilar B
	destino = 2;//Pilar C

	printf("===============\n");
	printf("TORRES DE HANOI\n");
	printf("===============\n\n");

	printf("Ingrese la cantidad de discos: ");
	scanf("%i", &num_discos);

	for (s = 0; s < 3; s++) //Inicializa todas las pilas del arreglo
	{
		Initialize(&pilares[s]);
		Initialize(&pilares_auxiliares[s]);
	}

	for (radio_discos = num_discos; radio_discos >= 1; radio_discos--) //Llena el Pilar A (pilares[0]) con el radio de los
	{																   //discos en orden decreciente
		disco.dim_disco = radio_discos;
		Push(&pilares[0], disco);
	}

	BorrarPantalla();
	imprimir_pilares();//Imprime los pilares en su estado inicial (antes de llamar a la funcion hanoi)
	EsperarMiliSeg(2000);//Espera 2 segundos
	BorrarPantalla();

	hanoi(num_discos, origen, auxiliar, destino);//Funcion recursiva para resolver el problema de hanoi

	imprimir_pilares();//Imprime los pilares en su estado final

	return 0;
}

