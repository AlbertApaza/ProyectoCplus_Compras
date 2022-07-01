#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<cstdlib>
#include<windows.h>
#include<string.h>
#include<cstring>
#define MAX 9999
using namespace std;

struct producto{
	int codigo;
	char descripcion[MAX],accionFarmacologica[MAX],marca[MAX],vencimiento[MAX],presentacion[MAX],laboratorio[MAX];
	int cantidad;
};
