#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <random>

using namespace std;
char insertarLetra(){
    char letra=' ';
    do{
       cout<<"inserte una letra: ";
        cin>>letra;
    } while (letra==' ');
    
    return letra;
}

void interface(int cantidad,string palabra){
    int puntaje=0;
    vector<string> players;
    string gamePalabra="";
    string tempPalabra="";
    string userName="";
    int intentos=5;
    char res;
    int count=0;
    bool encontrar=false;
    for (int i = 0; i < cantidad; i++){
        gamePalabra+="_";
    }
    
    cout<<gamePalabra<<endl;
    cout<<palabra<<endl;
   
    do{
        count=0;
        res= insertarLetra();
        tempPalabra=gamePalabra;
        for (int i = 0; i < palabra.length(); i++){
            if(res==palabra[i]){
                gamePalabra[i]=res;
                encontrar=true;
                puntaje+=50;
            }
        }
        if (tempPalabra==gamePalabra){
            intentos--;
            puntaje-=10;
            tempPalabra=gamePalabra;
        }
        
        cout<<gamePalabra<<endl;
        for (auto l : gamePalabra){
            if(l!='_'){
                count+=1;
            }
        }
        cout<<count<<endl;
        cout<<"intentos restantes: "<<intentos<<endl;
    } while (count!=palabra.length()&&intentos>0);

    
    do {
        cout<<"ingrese su usuario: ";
        cin>>userName;
        ofstream doc1("puntajes.txt",ios::app);
        string line;
        doc1 << userName<<"\t"<<puntaje<<endl; 
        
        doc1.close();
        
    } while (userName=="");
    
    cout<<"palabra completada!!"<<endl;
}

int main(int argc, char const *argv[]){
    srand(time(NULL));
    
    vector<string> palabras;
    int indicePalabra=0 + rand() % (size(palabras) +1 - 0);
    ifstream doc("verbos.txt");
    string line;
    if (doc.is_open()){
        while (getline(doc, line)){
            palabras.push_back(line);
        }
    }
    doc.close();
    interface(palabras[indicePalabra].length(),palabras[indicePalabra]);
    return 0;
}
