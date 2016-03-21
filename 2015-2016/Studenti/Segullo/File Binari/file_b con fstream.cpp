#include <iostream>
#include <fstream>
using namespace std;

void crea(){

    ofstream output;
    output.open("Bin.dat",ios::out|ios::binary);
    output.close();

}

void inserisci(){
    string nome,cognome;
    ofstream output;
    cout<<endl<<"Inserisci nome e cognome"<<endl;
    cin>>nome>>cognome;
    output.open("Bin.dat",ios::app|ios::binary);
    output<<nome<<" "<<cognome<<endl;
    output.close();

}

void stampa(){
    ifstream input;
    string n;
    input.open("Bin.dat",ios::in|ios::binary);
  //  input.seekg(0,ios::beg);
    while(true){
        input>>n;
        if(input.eof()) break;
        cout<<n;
    }
    input.close();

}

int main(){

    int scelta;


    do{
    cout<<endl<<"1. crea file 2.inserisci 3.stampa"<<endl;
    cin>>scelta;

    switch(scelta){

  case 1:
    crea();
    break;

  case 2:
    inserisci();
    break;

  case 3:
    stampa();
    break;

      }

    }
    while(scelta!=0);


    return 0;
}
