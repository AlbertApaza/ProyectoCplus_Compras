//PRESENTACION https://docs.google.com/presentation/d/1MqfBnT2mlmlGOt0NyxwSJRrurf1-4aShk8fjFW7awa4/edit?usp=sharing
//DOCUMENTO https://docs.google.com/document/d/1UJVcF2Toz8wkqChIGKUo6YXZUAWi0L8kiiAOKw6wuo4/edit?usp=sharing
#include <iostream>
#include <cstdlib>
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
    int demora = 0;
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

char PaisOriginario;
char op3;

//Ordenar Alfabeticamente Producto
string AuxProductoAlfa, AuxTipoAlfa, AuxMarcaAlfa;
int AuxPrecioAlfa, AuxCodigoAlfa;

//BuscarProducto
int dato;

//ADMIN
string AdminNombre;
int AdminContra;

//USUARIO
char op2;


void Registrar(Usuario A[]);
void AgregarProductos(Producto C[]);
void PagCompras(Usuario A[], Producto C[]);
void VerRecibo(Usuario A[], Compra B[]);
void BuscarProducto(Producto C[]);



int main(){

    int op;

    do
    {
        system("cls");
        cout<<" ****************************** MENU ***********************************"<<endl;
        cout<<"   1. ADMIN                                                             "<<endl;
        cout<<"   2. USUARIO                                                           "<<endl;
        cout<<"   0. Salir                                                             "<<endl;
        cout<<" ***********************************************************************"<<endl;
        cout<<endl;
        cout<<" Ingrese la opcion: "; cin>>op;

        switch (op)
        {
        case 1:
            system("cls");
            cout<<"----------------- Registrese -----------------"<<endl;
            cout<<"Ingrese el Usuario:     "; cin>>AdminNombre;
            cout<<"Ingrese la Contrasena:  "; cin>>AdminContra;
            if (AdminNombre=="ADMIN")
            {
                if (AdminContra==123456)
                {   
                    cout<<endl;
                    cout<<"Usuario y Contrasena correctos"<<endl;
                    cout<<endl;
                    system("pause");

                    AgregarProductos(C);  //Agrega productos y crea un archivo.
                }
            }
            else
            {
                cout<<endl;
                cout<<"Ingrese datos correctos"<<endl;
                system("pause");
            }
            break;
        
        case 2:
            do
            {
                system("cls");
                cout<<" ****************************** MENU ***********************************"<<endl;
                cout<<"   A. Registrarse                                                       "<<endl;
                cout<<"   B. Pagina de Compras                                                 "<<endl;
                cout<<"   C. Buscar Producto                                                   "<<endl;
                cout<<"   D. Procesar Recibo                                                   "<<endl;
                cout<<"   Z. Retoceder                                                         "<<endl;
                cout<<" ***********************************************************************"<<endl;
                cout<<endl;
                cout<<" Ingrese la opcion: "; cin>>op2;
                switch (op2)
                {
                case 'A':
                    Registrar(A);
                    break;

                case 'B':
                    PagCompras(A, C);
                    break;

                case 'C':
                    BuscarProducto(C);
                    break;

                case 'D':
                    VerRecibo(A, B);
                    break;
                
                case 'Z':
                    cout<<endl;
                    cout<<" Retrocediendo..."<<endl;
                    system("pause");
                    break;
                
                default:
                    cout<<endl;
                    cout<<" Ingrese una opcion correcta"<<endl;
                    system("pause");
                    break;
                }
            } while (op2!='Z');
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
        cout<<"Paises Disponibles: "<<endl;
        cout<<"     Peru        = P"<<endl;
        cout<<"     Colombia    = C"<<endl;
        cout<<"     Ecuador     = E"<<endl;
        cout<<"     Bolivia     = B"<<endl;
        cout<<"     Argentina   = A"<<endl;
        cout<<endl;
        cout<<"Ingrese su Pais:    "; cin>>PaisOriginario;
        switch (PaisOriginario)
        {
        case 'P':
            A[n].Pais="Peru";
            A[n].demora=6;
            break;
        
        case 'C':
            A[n].Pais="Colombia";
            A[n].demora=10;
            break;
        
        case 'E':
            A[n].Pais="Ecuador";
            A[n].demora=9;
            break;

        case 'B':
            A[n].Pais="Bolivia";
            A[n].demora=11;
            break;

        case 'A':
            A[n].Pais="Argentina";
            A[n].demora=15;
            break;

        default:
            cout<<"Aun no contamos con envios a su Pais"<<endl;
            break;
        }
        cout<<"DNI:          "; cin>>A[n].Dni;
        cout<<"Direccion:    "; fflush(stdin); getline(cin, A[n].Direccion);
        cout<<"Telefono:     "; cin>>A[n].telefono;
        cout<<"Sexo:         ", cin>>A[n].sexo;
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
        do
        {
            system("cls");
            cout<<"======== Agregar Producto al Inventario ========"<<endl;
            cout<<endl;
            cout<<" Agregue el producto             : "; fflush(stdin); getline(cin, C[p].Producto);
            cout<<" Tipo(ropa/electronico/libros)   : "; fflush(stdin); getline(cin, C[p].Tipo);
            cout<<" Ingrese el precio               : S/."; cin>>C[p].Precio;
            cout<<" Ingrese la marca                : "; fflush(stdin); getline(cin, C[p].Marca);
            cout<<" Ingrese el codigo del Producto  : "; cin>>C[p].Codigo;
            p++;
            cout<<endl;
            cout<<"Desea agregar otro producto? (S/N): "; cin>>op3;
        } while (op3 == 'S' || op3 == 's');


    //Ordenar Alfabeticamente
	for (int i=0;i<p;i++)
	{
		for(int j=0;j<p;j++)
		{
			if(C[j].Producto>C[j+1].Producto)
			{   
                //Producto
				AuxProductoAlfa=C[j].Producto;
				C[j].Producto=C[j+1].Producto;
				C[j+1].Producto=AuxProductoAlfa;

                //Tipo
				AuxTipoAlfa=C[j].Tipo;
				C[j].Tipo=C[j+1].Tipo;
				C[j+1].Tipo=AuxTipoAlfa;

                //Precio
				AuxPrecioAlfa=C[j].Precio;
				C[j].Precio=C[j+1].Precio;
				C[j+1].Precio=AuxPrecioAlfa;

                //Marca
				AuxMarcaAlfa=C[j].Marca;
				C[j].Marca=C[j+1].Marca;
				C[j+1].Marca=AuxMarcaAlfa;

                //Codigo de Producto
				AuxCodigoAlfa=C[j].Codigo;
				C[j].Codigo=C[j+1].Codigo;
				C[j+1].Codigo=AuxCodigoAlfa;
			}
		}
	}
        ofstream archivop;
        archivop.open("Productos.txt");
        archivop<<"Productos: "<<endl;
        archivop<<"================================"<<endl;
        for(int i = 0; i < p ;i++){
        archivop<<" Codigo del Producto     : "<<C[i+1].Codigo<<endl;
        archivop<<" Producto				: "<<C[i+1].Producto<<endl;
        archivop<<" Tipo de Producto		: "<<C[i+1].Tipo<<endl;
        archivop<<" Precio del Producto	: S/."<<C[i+1].Precio<<endl;
        archivop<<" Marca del Producto	    : "<<C[i+1].Marca<<endl;
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
        cout<<" Codigo de Producto       : "<<C[i+1].Codigo<<endl;
        cout<<" Producto                 : "<<C[i+1].Producto<<endl;
        cout<<" Tipo de Producto         : "<<C[i+1].Tipo<<endl;
        cout<<" Precio del Producto      : "<<C[i+1].Precio<<endl;
        cout<<" Marca del Producto       : "<<C[i+1].Marca<<endl;
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
    for (int i = 0; i <= n; i++)
        {
            if (i==n-1)
            {
                cout<<"Tiempo estimado de demora: "<<A[i].demora<<" dias"<<endl;
            }
        }
    cout<<endl;
    system("pause");
    }

    else
    {
        cout<<" Primero registrese"<<endl;
        system("pause");
    }
}

//Secuencial Desordenado
void BuscarProducto(Producto C[]){
    system("cls");
    int pos, i;
    cout<<"============= BUSCAR PRODUCTO ============="<<endl;
    cout<<endl;
    cout<<"Ingrese el codigo del producto que desea buscar: "; cin>>dato;
    pos = 0;
    i = 1;
    while (i <= p and C[i].Codigo != dato)
    {
        i = i + 1;
    }
    
    if (i <= p)
    {
        pos = i;
    }
    cout<<"El producto que busca es el numero "<<pos<<" en nuestro catalogo"<<endl;
    for (int i = 0; i < p; i++)
    {
        if (pos==i)
        {
            cout<<"===================================="<<endl;
            cout<<" Codigo de Producto       : "<<C[i].Codigo<<endl;
            cout<<" Producto                 : "<<C[i].Producto<<endl;
            cout<<" Tipo de Producto         : "<<C[i].Tipo<<endl;
            cout<<" Precio del Producto      : "<<C[i].Precio<<endl;
            cout<<" Marca del Producto       : "<<C[i].Marca<<endl;
        }
    }
    cout<<endl;
    system("pause");
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
    archivoR<<endl;
    archivoR<<"Total a Pagar (IGV incluido):    S/."<<AuxCompraIGV<<endl;
    archivoR<<endl;

    for (int i = 0; i < n; i++)
    {
        if (i==n-1)
        {
            archivoR<<"Tiempo estimado de demora: "<<A[i].demora<<" dias"<<endl;
        }
    }
    archivoR.close();
}
else
{
    cout<<" Primero debe de realizar una compra"<<endl;
    system("pause");
}
}