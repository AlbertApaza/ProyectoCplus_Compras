#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Usuario
{
    string Nombre;
    int Dni;
    string Direccion;
    string Pais;
    int telefono;
    bool sexo;
    int edad;
};

Usuario A[1000];
int n;



void Registrar(Usuario A[]);
void AgregarProductos();
void PagCompras();



int main(){

    int op;

    do
    {
        system("cls");
        cout<<" ****************************** MENU ***********************************"<<endl;
        cout<<"   Que desea hacer?                                                     "<<endl;
        cout<<"   1. Registrarse                                                       "<<endl;
        cout<<"   2. Agregar productos                                                 "<<endl;
        cout<<"   0. Salir                                                             "<<endl;
        cout<<" ***********************************************************************"<<endl;
        cout<<endl;
        cout<<" Ingrese la opcion: "; cin>>op;

        switch (op)
        {
        case 1:
        Registrar(A[]);
            break;

        case 2:
       AgregarProductos();
            break;

        case 3:
        PagCompras();
            break;

        case 0:
            cout<<"Ejecucion Terminada"<<endl;
            break;      
        
        default:
            cout<<"Ingrese un numero correcto"<<endl;
            break;
        }
    } while (op != 0);
}

void Registrar(Usuario A[]){
    


}
void AgregarProductos(){
    
}
void PagCompras(){
    
}
