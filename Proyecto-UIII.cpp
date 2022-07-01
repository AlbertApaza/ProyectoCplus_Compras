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
    string sexo;
    int edad;
};

struct Producto
{
    string Producto;
    string Tipo;
    int Precio;
    string Marca;
};


Usuario A[1000];
Producto C[1000];
int n = 0;
int p = 0;



void Registrar(Usuario A[]);
void AgregarProductos(Producto C[]);
void PagCompras(Usuario A[], Producto C[]);



int main(){

    int op;

    do
    {
        system("cls");
        cout<<" ****************************** MENU ***********************************"<<endl;
        cout<<"   Que desea hacer?                                                     "<<endl;
        cout<<"   1. Registrarse                                                       "<<endl;
        cout<<"   2. Agregar productos                                                 "<<endl;
        cout<<"   3. Pagina de Compras                                                 "<<endl;
        cout<<"   0. Salir                                                             "<<endl;
        cout<<" ***********************************************************************"<<endl;
        cout<<endl;
        cout<<" Ingrese la opcion: "; cin>>op;

        switch (op)
        {
        case 1:
        Registrar(A);
            break;

        case 2:
        AgregarProductos(C);
            break;

        case 3:
        PagCompras(A, C);
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
    system("cls");
    cout<<"Ingrese su edad: "; cin>>A[n].edad;
    if (A[n].edad>=18)
    {
        cout<<"Ingrese su Nommbre:      "; fflush(stdin); getline(cin, A[n].Nombre);
        cout<<"Ingrese su Dni:          "; cin>>A[n].Dni;
        cout<<"Ingrese su Pais:         "; fflush(stdin); getline(cin, A[n].Pais);
        cout<<"Ingrese su Direccion:    "; fflush(stdin); getline(cin, A[n].Direccion);
        cout<<"Ingrese su telefono:     "; cin>>A[n].telefono;
        cout<<"Ingrese su sexo:         ", cin>>A[n].sexo;
        n++;
        
        ofstream archivo;
        archivo.open("Clientes.txt");
        archivo<<"Clientes: "<<endl;
        archivo<<"======================"<<endl;
        for(int i=0; i<n ;i++){
        archivo<<"Nombre:       "<<A[i].Dni<<endl;
        archivo<<"Pais:         "<<A[i].Pais<<endl;
        archivo<<"Direccion:    "<<A[i].Direccion<<endl;
        archivo<<"Telefono:     "<<A[i].telefono<<endl;
        archivo<<"Sexo:         "<<A[i].sexo<<endl;
        archivo<<"Edad:         "<<A[i].edad<<endl;
        archivo<<"======================"endl;
        }
        archivo.close();

    }
    
    else
    {
        cout<<"Debe ser mayor de edad para poder registrarse"<<endl;
        system("pause");
    }
}



void AgregarProductos(Producto C[]){
    cout<<"***************************** Agregar Producto al Inventario *****************************"<<endl;
    cout<<endl;
    cout<<"Agregue el producto: "; fflush(stdin); getline(cin, C[p].Producto);
    cout<<"Ingrese el tipo de Producto (ropa, electronico, libros): "; fflush(stdin); getline(cin, C[p].Tipo);
    cout<<"Ingrese el precio: "; cin>>C[p].Precio;
    cout<<"Ingrese la marca: "; fflush(stdin); getline(cin, C[p].Marca);
    p++;
}




void PagCompras(Usuario A[], Producto C[]){
    if (n!=0)
    {
    cout<<"Bienvenido "<<A[n].Nombre<<endl;
    cout<<endl;
    cout<<"Lista de Productos:"<<endl;
    cout<<endl;
    for (int i = 0; i < p; i++)
    {
        cout<<"===================================="<<endl;
        cout<<"Codigo de Producto: "<<i<<endl;
        cout<<"Producto: "<<C[i].Producto<<endl;
        cout<<"Tipo de Producto: "<<C[i].Tipo<<endl;
        cout<<"Precio del Producto: "<<C[i].Precio<<endl;
        cout<<"Marca del Producto"<<C[i].Marca<<endl;
    }
    
    }

    else
    {
        cout<<"Primero registrese"<<endl;
        system("pause");
    }  
}

