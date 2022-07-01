#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

void escribir();

int main(){
	escribir();
	
	
	return 0;	
}


void escribir(){
	ofstream archivo;
	archivo.open("prueba.txt",ios::out);	//abrira archivo
	
	if(archivo.fail()){
		
		cout<<"Nose pudo abrir el archivo";
		exit(1);
	}
	archivo<<"Hola mrd";
	archivo.close();
}
