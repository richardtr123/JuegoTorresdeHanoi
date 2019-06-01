#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


void Instrucciones()
{
	cout<<"===============================================================================\n";
    cout<<"                    	    INSTRUCCIONES                     "<<endl;
    cout<<"===============================================================================\n"<<endl;
    cout<<"'1' Para jugar es necesario haber ingresado la cantidad de discos"<<endl;   
    cout<<"'2' Los discos son interpretados por numeros"<<endl;
    cout<<"'3' Un disco mayor no puede estar encima de uno menor "<<endl;
    cout<<"'4' Terminara el juego si es que logra colocar todos los discos de la  "<<endl;
    cout<<" Pila 1 a la Pila 3 "<<endl<<endl;
    cout<<"Entendido!!!"<<endl<<endl;
}

void tituloPrincipal()
{
   int i;

   cout<<"===============================================================================\n";
   cout<<"                    	    Torres de Hanoi                     "<<endl;
   cout<<"===============================================================================\n"<<endl;
    cout<<"'1' Insertar cantidad de discos"<<endl;   
    cout<<"'2' JUGAR!!!"<<endl;
    cout<<"'3' Mostrar RESULTADOS"<<endl;
    cout<<"'4' Desea salir del Programa"<<endl;
   i = 0;
   putchar('\n');
   for (; i < 80; i++) {
      putchar('_');
   }
   cout<<endl;
}

struct Datos_Estadisticos
{
	char Nombre[20];
	int Puntaje;
};

template <class T>
class Torres_de_Hanoi
{
	private:
		T Datos_del_Jugador[30];
		int Pila_1[20];
		int Pila_2[20];
		int Pila_3[20];
		int tope_1;
		int tope_2;
		int tope_3;
		int cantidad_de_discos;
		int frente_1;
		int frente_2;
		int frente_3;
		int numero_de_jugador;
		bool Moneda;
	public:
		Torres_de_Hanoi();	
		void push();	
		void push_1();
		void push_2();
		void push_3();
		void pop_1(opcion);
		void pop_2(opcion);
		void pop_3(opcion);
		void origen_y_destino(int,int);
		int verificar(int,int);
		void jugar();
		void mostrar();
		void Resultados();
};

template<class T>
Torres_de_Hanoi<T>::Torres_de_Hanoi()
{
	frente_1 = -1;
	frente_2 = -1;
	frente_3 = -1; 
	tope_1 = -1;
	tope_2 = -1;
	tope_3 = -1;
	cantidad_de_discos = 0;
	numero_de_jugador = -1;
	Moneda = false;
}

template <class T>
void Torres_de_Hanoi<T>::jugar()
{
	
	if(Moneda == true)
	{
		int completado = 0;
		int movimientos = 0;
		int pre_1,pre_2;
		numero_de_jugador++;

		while((completado != cantidad_de_discos))
		{
			mostrar();
			cout<<"\nDisco Origen :";
			cin>>pre_1;
			cout<<"Disco Destino :";
			cin>>pre_2;
			movimientos++;
			//Inicio de comparacion para verificar el origen y destino de disco
			origen_y_destino(pre_1,pre_2);	
			//Fin de comparacion para verificar el origen y destino de disco
			cout<<"\n\nPulse enter"<<endl;
			getch();
			clrscr();
			completado = 0;
			for(int i=0;i<cantidad_de_discos;i++)
			{
				if(Pila_3[i] == i+1)
				{
					completado++;
				}
			}

			if(completado == cantidad_de_discos)
			{
				mostrar();
				cout<<"\nFelicitaciones. Gracias por Jugar :D\n\n";
				cout<<"Digite su nombre :";
				gets(Datos_del_Jugador[numero_de_jugador].Nombre);
				cout<<"Cantidad de Movimientos :"<<movimientos<<endl<<endl;
				Datos_del_Jugador[numero_de_jugador].Puntaje = movimientos;
				cout<<"¡¡¡GAME OVER!!!";
				Moneda = false;
			}
		}
	}

	else
	{
		cout<<"\n No dispone de una Moneda para jugar :("<<endl;
	}	
}



template <class T>
void Torres_de_Hanoi<T>::push()
{
	cout<<"Digite la cantidad total de Discos a jugar :";
	cin>>cantidad_de_discos;
	int valor = 1;
	for(int i=0;i<cantidad_de_discos;i++)
	{
		Pila_1[i] = valor;
		Pila_2[i] = 0;
		Pila_3[i] = 0;
		valor++;
	}
	tope_1 = 0;
	tope_2 = cantidad_de_discos;
	tope_3 = cantidad_de_discos;
	frente_1 = cantidad_de_discos;
	frente_2 = cantidad_de_discos;
	frente_3 = cantidad_de_discos;
	Moneda = true;
}


template <class T>
void Torres_de_Hanoi<T>::pop_1(int opcion)
{	
	if((tope_1 == cantidad_de_discos)||(tope_1 == frente_1+1))
	{
		cout<<"\nLa pila 1 esta vacia o llena de Discos";
	}
	else
	{
		if(opcion == 2)
		{
			int sentencia = verificar(Pila_2[tope_2] , Pila_1[tope_1]);
			if(sentencia == 1 && tope_2 != cantidad_de_discos )
			{
				cout<<"\nNo es posible realizar el cambio, verifique si el disco es menor al dato"; 
				cout<<"\nanterior guardado en la Pila de Destino " ;
			}
			else
			{
				cout<<"\nDe Disco 1 a -> 2";
				tope_2--;								//Indica la posicion del dato Rellenado
				Pila_2[tope_2] = Pila_1[tope_1];
				Pila_1[tope_1] = 0;
				tope_1++;	
			}														
		}

		if(opcion == 3)
		{
			int sentencia = verificar(Pila_3[tope_3] , Pila_1[tope_1]);
			if(sentencia == 1 && tope_3 != cantidad_de_discos )
			{
				cout<<"\nNo es posible realizar el cambio, verifique si el disco es menor al dato"; 
				cout<<"\nanterior guardado en la Pila de Destino " ;
			}
			else
			{
				cout<<"\nDe disco 1 a -> 3";
				tope_3--;								//Indica la posicion del dato Rellenado
				Pila_3[tope_3] = Pila_1[tope_1];
				Pila_1[tope_1] = 0;
				tope_1++;
			}			
		}
	}
}

template <class T>
void Torres_de_Hanoi<T>::pop_2(int opcion)
{	
	if((tope_2 == cantidad_de_discos)||(tope_2 == frente_2+1))
	{
		cout<<"\nLa pila 2 esta vacia ";
	}
	else
	{
		if(opcion == 1)
		{
			int sentencia = verificar(Pila_1[tope_1-1] , Pila_2[tope_2]);
			if(sentencia == 1 && tope_1 != cantidad_de_discos )		//Verifica si no esta llena la Pila de Destino
			{
				cout<<"\nNo es posible realizar el cambio, verifique si el disco es menor al dato"; 
				cout<<"\nanterior guardado en la Pila de Destino " ;
			}
			else
			{
				cout<<"\nDe Disco 2 a -> 1";
				tope_1--;									//Indica la posicion del dato Rellenado
				Pila_1[tope_1] = Pila_2[tope_2];
				Pila_2[tope_2] = 0;
				tope_2++;		
			}
							
		}
		if(opcion == 3)
		{
			int sentencia = verificar(Pila_3[tope_3] , Pila_2[tope_2]);
			if(sentencia == 1 && tope_3 != cantidad_de_discos )
			{
				cout<<"\nNo es posible realizar el cambio, verifique si el disco es menor al dato"; 
				cout<<"\nanterior guardado en la Pila de Destino " ;
			}
			else
			{
				cout<<"\nDe disco 2 a -> 3";
				tope_3--;								//Indica la posicion del dato Rellenado
				Pila_3[tope_3] = Pila_2[tope_2];
				Pila_2[tope_2] = 0;
				tope_2++;
			}			
		}
	}
}

template <class T>
void Torres_de_Hanoi<T>::pop_3(int opcion)
{	
	if((tope_3 == cantidad_de_discos)||(tope_3 == frente_3+1))
	{
		cout<<"\nLa pila 3 esta vacia o llena de Discos";
	}
	else
	{
		if(opcion == 1)
		{
			int sentencia = verificar(Pila_1[tope_1] , Pila_3[tope_3]);
			if(sentencia == 1 && tope_1 != cantidad_de_discos )
			{
				cout<<"\nNo es posible realizar el cambio, verifique si el disco es menor al dato"; 
				cout<<"\nanterior guardado en la Pila de Destino " ;
			}
			else
			{
				cout<<"\nDe Disco 3 a -> 1";
				tope_1--;								//Indica la posicion del dato Rellenado
				Pila_1[tope_1] = Pila_3[tope_3];
				Pila_3[tope_3] = 0;
				tope_3++;	
			}
					
		}
		if(opcion == 2)
		{
			int sentencia = verificar(Pila_2[tope_2] , Pila_3[tope_3]);
			if(sentencia == 1 && tope_2 != cantidad_de_discos )
			{
				cout<<"\nNo es posible realizar el cambio, verifique si el disco es menor al dato"; 
				cout<<"\nanterior guardado en la Pila de Destino " ;
			}
			else
			{
				cout<<"\nDe disco 3 a -> 2";
				tope_2--;								//Indica la posicion del dato Rellenado
				Pila_2[tope_2] = Pila_3[tope_3];
				Pila_3[tope_3] = 0;
				tope_3++;
			}			
		}
	}
}

template <class T>
int Torres_de_Hanoi<T>::verificar(int dato_1,int dato_2)
{
	if(dato_1 < dato_2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template <class T>
void Torres_de_Hanoi<T>::origen_y_destino(int pre_1, int pre_2)
{
	int selector;			//Elige la opcion para el manejo o movimiento de discos
	if(pre_1 == 1)
			{
				if(pre_2 == 2)
				{
					selector = 2;
					pop_1(selector);
				}
				if(pre_2 == 3)
				{
					selector = 3;
					pop_1(selector);
				}
			}

	if(pre_1 == 2)
	{
		if(pre_2 == 1)
		{
			selector = 1;
			pop_2(selector);
		}
		if(pre_2 == 3)
		{
			selector = 3;
			pop_2(selector);
		}
	}

	if(pre_1 == 3)
	{
		if(pre_2 == 1)
		{
			selector = 1;
			pop_3(selector);
		}
		if(pre_2 == 2)
		{
			selector = 2;
			pop_3(selector);
		}
	}
}

template <class T>
void Torres_de_Hanoi<T>::Resultados()
{
	cout<<"\t||||||||||||RESULTADOS||||||||||||"<<endl<<endl;
	cout<<"\t Nombre \tMovimientos"<<endl;
	for(int i=0;i<=numero_de_jugador;i++)
	{		
		cout<<"\t"<<Datos_del_Jugador[i].Nombre<<"\t\t\t"<<Datos_del_Jugador[i].Puntaje<<endl;
	}		
}

template <class T>
void Torres_de_Hanoi<T>::mostrar()
{
	cout<<"Si desea Salir pulse la tecla 2\n\n";

	for(int i=0;i<cantidad_de_discos;i++)
	{
		cout<<"\t"<<Pila_1[i]<<"\t"<<Pila_2[i]<<"\t"<<Pila_3[i]<<endl;
	}
}

void main()
{
	system("COLOR 0A");
	Torres_de_Hanoi<Datos_Estadisticos> Prueba;
	int discos;	
	int opcion;

	Instrucciones();
	cout<<"\n\nPulse enter"<<endl;
	getch();
	clrscr();		

	while(opcion!=4)
	{
		tituloPrincipal();
		cout<<"Opcion:";
		cin>>opcion;
		clrscr();
			switch(opcion)
			{
				case 1:
				{
					tituloPrincipal();
					Prueba.push();
					cout<<"\n\nPulse enter"<<endl;
					getch();
					clrscr();					
					break;
				}
				case 2:
				{
					Prueba.jugar();
					cout<<"\n\nPulse enter"<<endl;
					getch();
					clrscr();
										
					break;
				}
				case 3:
				{
					tituloPrincipal();
					Prueba.Resultados();
					cout<<"\n\nPulse enter"<<endl;
					getch();
					clrscr();
					break;
				}
			}
	}
	
	system("Pause");
}
