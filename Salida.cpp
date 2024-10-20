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

    people x;
    int y;
    cout<<"Indique el numero de registro que quiere visualizar: ";
    cin>>y;

    fstream FILE("./archivo.bin",ios::in| ios::binary);

    FILE.seekg(sizeof(people) * y, ios::beg);
    cout<<"Posicion: "<<FILE.tellg()<<endl;

    FILE.read(reinterpret_cast<char *>(&x), sizeof(people));

    cout<<"Datos del resgisto "<<y<<": "<<x.id<<" "<<x.nombre<<" "<<x.ci<<" "<<x.edad<<" "<<x.peso<<" "<<x.altura<<" "<<x.genero<<endl; 

    FILE.close();
    return 0;
}