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
    int Codigo;
};

struct Compra
{
    string ProductoComprado;
    string TipoComprado;
    int PrecioComprado;
    string MarcaComprado;
    int CodigoComprado;
};


Usuario A[1000];
Producto C[1000];
Compra B[1000];
int n = 0;
int p = 0;
int h = 0;
int i = 0;
char eleccion;
int CodigoProducto=0;
string AuxProducto, AuxTipo, AuxMarca;
int AuxPrecio, AuxCodigo;
int AuxCompra = 0;
int AuxCompraIGV = 0;



void Registrar(Usuario A[]);
void AgregarProductos(Producto C[]);
void PagCompras(Usuario A[], Producto C[]);
void VerRecibo(Usuario A[], Compra B[]);



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
        cout<<"   4. Procesar su Recibo                                                "<<endl;
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
        
        case 4:
            VerRecibo(A, B);
            break;

        case 0:
            cout<<endl;
            cout<<" Ejecucion Terminada"<<endl;
            break;      
        
        default:
            cout<<endl;
            cout<<" Ingrese un numero correcto"<<endl;
            system("pause");
            break;
        }
    } while (op != 0);
}

void Registrar(Usuario A[]){                    //Registra usuario y crea un archivo.
    system("cls");
    cout<<"Ingrese su edad:       "; cin>>A[n].edad;
    if (A[n].edad>=18)
    {
        cout<<endl;
        cout<<"****Ingrese sus datos****"<<endl;
        cout<<"Nombre:       "; fflush(stdin); getline(cin, A[n].Nombre);
        cout<<"Sexo:         ", cin>>A[n].sexo;
        cout<<"DNI:          "; cin>>A[n].Dni;
        cout<<"Pais:         "; fflush(stdin); getline(cin, A[n].Pais);
        cout<<"Direccion:    "; fflush(stdin); getline(cin, A[n].Direccion);
        cout<<"Telefono:     "; cin>>A[n].telefono;
        n++;
        
        ofstream archivo;
        archivo.open("Clientes.txt");
        archivo<<"Clientes: "<<endl;
        archivo<<"======================"<<endl;
        for(int i=0; i<n ;i++){
        archivo<<"Nombre:       "<<A[i].Nombre<<endl;
        archivo<<"Pais:         "<<A[i].Pais<<endl;
        archivo<<"DNI:          "<<A[i].Dni<<endl;
        archivo<<"Direccion:    "<<A[i].Direccion<<endl;
        archivo<<"Telefono:     "<<A[i].telefono<<endl;
        archivo<<"Sexo:         "<<A[i].sexo<<endl;
        archivo<<"Edad:         "<<A[i].edad<<endl;
        archivo<<"======================"<<endl;
        archivo<<" \n "<<endl;
        }
        archivo.close();
    }
    
    else
    {
        cout<<" Debe ser mayor de edad para poder registrarse"<<endl;
        system("pause");
    }
}



void AgregarProductos(Producto C[]){        //Agrega productos y crea un archivo.
    system("cls");
    cout<<" \n "<<endl;
    cout<<"=========Agregar Producto al Inventario========="<<endl;
    cout<<" \n "<<endl;
    cout<<" Agregue el producto             : "; fflush(stdin); getline(cin, C[p].Producto);
    cout<<" Tipo(ropa/electronico/libros)   : "; fflush(stdin); getline(cin, C[p].Tipo);
    cout<<" Ingrese el precio               : S/."; cin>>C[p].Precio;
    cout<<" Ingrese la marca                : "; fflush(stdin); getline(cin, C[p].Marca);
    cout<<" Ingrese el codigo del Producto  : "; cin>>C[p].Codigo;
    p++;        

    ofstream archivop;
    archivop.open("Productos.txt");
    archivop<<"Productos: "<<endl;
    archivop<<"================================"<<endl;
    for(int i = 0; i < p ;i++){
    archivop<<" Codigo del Producto    : "<<C[i].Codigo<<endl;
    archivop<<" Producto				: "<<C[i].Producto<<endl;
    archivop<<" Tipo de Producto		: "<<C[i].Tipo<<endl;
    archivop<<" Precio del Producto	: S/."<<C[i].Precio<<endl;
    archivop<<" Marca del Producto	    : "<<C[i].Marca<<endl;
    archivop<<"================================"<<endl;
    }
    archivop.close();

    }




void PagCompras(Usuario A[], Producto C[]){
if (n!=0)
{
   system("cls");
   for (int i = 0; i <= n; i++)
    {
        if (i==n-1)
        {
            cout<<" Bienvenido "<<A[i].Nombre<<endl;
        }
    }
    cout<<endl;
    cout<<" Lista de Productos:"<<endl;
    cout<<endl;
    for (int i = 0; i < p; i++)
    {
        cout<<"===================================="<<endl;
        cout<<" Codigo de Producto       : "<<C[i].Codigo<<endl;
        cout<<" Producto                 : "<<C[i].Producto<<endl;
        cout<<" Tipo de Producto         : "<<C[i].Tipo<<endl;
        cout<<" Precio del Producto      : "<<C[i].Precio<<endl;
        cout<<" Marca del Producto       : "<<C[i].Marca<<endl;
    }
    cout<<endl;

    do
    {
        cout<<"Ingrese el codigo del producto que desea comprar: "; cin>>CodigoProducto;
        for (int i = 0; i < p; i++)
        {
            if (CodigoProducto==C[i].Codigo)
            {
                AuxProducto=C[i].Producto;
                AuxTipo=C[i].Tipo;
                AuxPrecio=C[i].Precio;
                AuxMarca=C[i].Marca;
                h++;
            }
        }

        //i++
        B[i].ProductoComprado=AuxProducto;
        B[i].TipoComprado=AuxTipo;
        B[i].PrecioComprado=AuxPrecio;
        B[i].MarcaComprado=AuxMarca;
        i++;

        cout<<"Desea comprar otro producto? (S/N): "; cin>>eleccion;
    } while (eleccion!='N' and eleccion!='n');

    system("cls");
    cout<<" Productos Comprados----------------"<<endl;
    if (h>0)
    {
        for (int i = 0; i < h; i++){
        cout<<"===================================="<<endl;
        cout<<" Producto                 : "<<B[i].ProductoComprado<<endl;
        cout<<" Tipo de Producto         : "<<B[i].TipoComprado<<endl;
        cout<<" Precio del Producto      : "<<B[i].PrecioComprado<<endl;
        cout<<" Marca del Producto       : "<<B[i].MarcaComprado<<endl;
        AuxCompra = AuxCompra + B[i].PrecioComprado;
        }
    }
    AuxCompraIGV = float(AuxCompra*1.18);
    cout<<"===================================="<<endl;
    cout<<"Total a Pagar (IGV incluido):    S/."<<AuxCompraIGV<<endl;
    cout<<endl;
    system("pause");
    }

    else
    {
        cout<<" Primero registrese"<<endl;
        system("pause");
    }
}


void VerRecibo(Usuario A[], Compra B[]){
if (h>0)
{
    ofstream archivoR;
    archivoR.open("Recibo.txt");

    archivoR<<" ========== CLIENTE ============="<<endl;
    for (int i = 0; i < n; i++)
    {
        if (i==n-1)
        {
        archivoR<<" Nombre:       "<<A[i].Nombre<<endl;
        archivoR<<" Pais:         "<<A[i].Pais<<endl;
        archivoR<<" Direccion:    "<<A[i].Direccion<<endl;
        archivoR<<" Telefono:     "<<A[i].telefono<<endl;
        }
    }
     archivoR<<endl;
    archivoR<<" ================================"<<endl;
    archivoR<<"       PRODUCTOS COMPRADOS      "<<endl;
    archivoR<<" ================================"<<endl;
    for(int i = 0; i < h ;i++){
    archivoR<<" Producto                 : "<<B[i].ProductoComprado<<endl;
    archivoR<<" Tipo de Producto         : "<<B[i].TipoComprado<<endl;
    archivoR<<" Precio del Producto      : "<<B[i].PrecioComprado<<endl;
    archivoR<<" Marca del Producto       : "<<B[i].MarcaComprado<<endl;
    archivoR<<" ================================"<<endl;
    }
    archivoR.close();
}
else
{
    cout<<" Primero debe de realizar una compra"<<endl;
    system("pause");
}
}
