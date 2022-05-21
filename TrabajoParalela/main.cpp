#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string.h>
#include <math.h>
#define pruebas "pruebas.csv"

using namespace std;

            
int main(){
    ifstream archivo(pruebas);
    fstream CreateFile("resultado.csv",ios::out);
    CreateFile<<"ID;Correctas;Incorrectas;Omitidas;Puntaje;Nota"<<endl;
    string linea;
    char delimitador = ';';
    //Leer Primer linea para descartarla
    getline(archivo,linea);
    cout<< "Integrantes del Grupo"<<endl<< "Andrés Velasquez"<<endl<< "Camilo Navas"<<endl;
    string buenas[]= {"\"A\"","\"E\"","\"C\"","\"B\"","\"B\"","\"D\"","\"A\"","\"B\"","\"E\"","\"C\"","\"B\"","\"D\""};
    while(getline(archivo,linea)){
        string Resultados[6];
        stringstream stream (linea);   //Convertir cadena en un stream
        string alumno, p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,pr1;
        float correctas=0, malas=0, omitidas=0;
        float puntaje=0;
        float nota=0;
        getline(stream,alumno,delimitador);
        getline(stream,p1,delimitador);
        getline(stream,p2,delimitador);
        getline(stream,p3,delimitador);
        getline(stream,p4,delimitador);
        getline(stream,p5,delimitador);
        getline(stream,p6,delimitador);
        getline(stream,p7,delimitador);
        getline(stream,p8,delimitador);
        getline(stream,p9,delimitador);
        getline(stream,p10,delimitador);
        getline(stream,p11,delimitador);
        getline(stream,p12,delimitador);
        string respuestas[12]={p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12};
        for (int x=0;x<12;x++){
            if (buenas[x]==respuestas[x])
                correctas+=1;
            else{
                if (respuestas[x]== "\"-\"")
                    omitidas+=1;
                else
                    malas+=1;
            }
                
        }
        puntaje= correctas*0.5 - malas*0.12;
        nota= 1+puntaje;
        nota= roundf(nota*10)/10;
        CreateFile<<alumno<<";"<<correctas<<";"<<malas<<";"<<omitidas<<";"<<puntaje<<";"<<nota<<endl;
    }      
    archivo.close();
    
    
    return 0;
}