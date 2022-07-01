#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
string linea;


int main(){
	
	ifstream archivo("documento.txt");
	getline(archivo,linea);
	cout<<linea<<	
	
	return 0;
}

