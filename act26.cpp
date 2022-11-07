#include<iostream>
#include<conio.h>
#include <iomanip>
#include"coordenadas.h"
using namespace std;

struct info{
	int id;
	char producto[30];
	char marca[30];
	char categoria[30];
	char especie[30];
	float precio;
	int almacen;	
};
	
void entrada(info a[],int lim,int fila,int col);
void titulos(int fila,int col);
void salida(info a[],int lim,int fila,int col);
void buscar(info a[],char producto[],int lim,int fila, int col);
void cambio_almacen(info a[],int lim,int fila,int col,int id);
main(){
	int op,v1,id;
	char r,v2[30],op2;
	info prod[' '];
	
	do{		
		system("cls");
		gotoxy(30,6);cout<<"M E N U";
		gotoxy(30,8);cout<<"1)Alta";
		gotoxy(30,10);cout<<"2)Consulta";
		gotoxy(30,12);cout<<"3)Almacen";
		gotoxy(30,14);cout<<"4)Bajas";
		gotoxy(30,16);cout<<"5)Cambios";
		gotoxy(30,18);cout<<"6)Salir";
		gotoxy(30,20);cout<<"Opcion";
		gotoxy(38,20);cin>>op;	
		switch(op){
			case 1:
				system("cls");
				cout<<"Cantidad de productos: ";
				cin>>v1;
				titulos(7,5);
				entrada(prod,v1,7,7);
				break;
			
			case 2:
				system("cls");
				gotoxy(30,6);cout<<"a)Todos los productos";
				gotoxy(30,8);cout<<"b)Por categoria";
				gotoxy(30,10);cout<<"Opcion";
				gotoxy(38,10);cin>>op2;
				switch(op2){
					case 'a':					
						system("cls");
						titulos(7,5);
						salida(prod,v1,7,7);
						break;
						
					case 'b':
						system("cls");
						gotoxy(2,1);cout<<"Categoria a buscar: ";
						cin>>v2;
						titulos(7,5);
						buscar(prod,v2,v1,7,7);				
						break;
				}
				break;
			
			case 3:
				system("cls");
				gotoxy(30,6);cout<<"Id de producto a modificar:";
				gotoxy(55,6);cin>>id;
				gotoxy(30,7);cout<<"Nueva cantidad ";
				cambio_almacen(prod,v1,45,7,id);
				break;
		}
		
		cout<<"¿Desea repetir el programa?  s/n";
		cin>>r;
	}while(r=='s'||r=='S');
}

void cambio_almacen(info a[],int lim,int fila,int col,int id){
	int x,nuevo;
	for(x=0;x<lim;x++){
		if(a[x].id == id){
			gotoxy(fila,col);cin>>nuevo;
			a[x].almacen=nuevo;
		}
	}
	
}

void buscar(info a[],char producto[],int lim,int fila, int col){
	int x;
	for(x=0;x<lim;x++){
		if(strcmp(a[x].categoria,producto)==0){
			gotoxy(fila+2,col+x*3);cout<<a[x].id;
			gotoxy(fila+11,col+x*3);cout<<a[x].producto;
			gotoxy(fila+26,col+x*3);cout<<a[x].marca;
			gotoxy(fila+39,col+x*3);cout<<a[x].categoria;	
			gotoxy(fila+56,col+x*3);cout<<a[x].especie;
			gotoxy(fila+69,col+x*3);cout<<a[x].precio;
			gotoxy(fila+84,col+x*3);cout<<a[x].almacen;
		}
	}
	
}
void entrada(info a[],int lim,int fila,int col){
	int x;
	for(x=0;x<lim;x++){
		gotoxy(fila+2,col+x*3);cin>>a[x].id;
		gotoxy(fila+11,col+x*3);cin>>a[x].producto;
		gotoxy(fila+26,col+x*3);cin>>a[x].marca;
		gotoxy(fila+39,col+x*3);cin>>a[x].categoria;
		gotoxy(fila+56,col+x*3);cin>>a[x].especie;
		gotoxy(fila+69,col+x*3);cin>>a[x].precio;
		gotoxy(fila+84,col+x*3);cin>>a[x].almacen;
	}
}

void salida(info a[],int lim,int fila,int col){
	int x;
	for(x=0;x<lim;x++){
		gotoxy(fila+2,col+x*3);cout<<a[x].id;
		gotoxy(fila+11,col+x*3);cout<<a[x].producto;
		gotoxy(fila+26,col+x*3);cout<<a[x].marca;
		gotoxy(fila+39,col+x*3);cout<<a[x].categoria;	
		gotoxy(fila+56,col+x*3);cout<<a[x].especie;
		gotoxy(fila+69,col+x*3);cout<<a[x].precio;
		gotoxy(fila+84,col+x*3);cout<<a[x].almacen;
	}
}

void titulos(int fila,int col){
	gotoxy(fila,col);cout<<"No.Id";
	gotoxy(fila+11,col);cout<<"Producto";
	gotoxy(fila+27,col);cout<<"Marca";
	gotoxy(fila+39,col);cout<<"Categoria";
	gotoxy(fila+55,col);cout<<"Especie";
	gotoxy(fila+69,col);cout<<"Precio";
	gotoxy(fila+80,col);cout<<"En almacen";
}

