#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct people{
    int id;
    char nombre[100];
    int ci;
    int edad;
    float peso;
    float altura;
    char genero[2];
};

int main(){

    people p;

    int x;
    cout<<"Cuantos datos va a ingresar?"<<endl;
    cin>>x;

    fstream FILE("./archivo.bin",ios::out| ios::binary);
    
    while(x>0){

    cout<<"Ingrese los datos siguientes: "<<endl;
    cout<<"ID del registro: ";
    cin>>p.id;
    cout<<"Nombre: ";
    cin>>p.nombre;
    cout<<"Cedula: ";
    cin>>p.ci;
    cout<<"Edad: ";
    cin>>p.edad;
    cout<<"Peso: ";
    cin>>p.peso;
    cout<<"Altura: ";
    cin>>p.altura;
    cout<<"Genero: ";
    cin>>p.genero;

    FILE.write(reinterpret_cast<char *>(&p), sizeof(people));

    x--;
    }

    FILE.close();
    return 0;
}