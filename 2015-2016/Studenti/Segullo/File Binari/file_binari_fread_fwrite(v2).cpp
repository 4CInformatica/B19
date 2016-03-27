/**
Davide Segullo 25/03/2016

Utilizzo di fwrite e fread per la gestione di un file binario.

Inserimento e stampa di dati relativi al file "esempio1.dat".
**/
#include <iostream>
#include <fstream>

using namespace std;

struct Dati{
    char nome[20];
    char cognome[20];
    char eta[5];
};

struct Dati dati;
struct Dati output;

void save()
{
FILE *fi;

fi=fopen("esempio1.dat","a+b");

cout<<"Inserire nome,cognome ed eta': ";
cin>>dati.nome>>dati.cognome>>dati.eta;

fwrite(&dati,sizeof(struct Dati),1,fi);

fclose(fi);
}

void load()
{
FILE *fi;
fi=fopen("esempio1.dat","rb");

cout<<"--------------------------"<<endl;
cout<<"\tSTAMPA DATI"<<endl;
while(true){
fread(&output,sizeof(struct Dati),1,fi);

if(feof(fi)) break;

cout<<endl<<"Nome: "<<output.nome<<endl;
cout<<"Cognome: "<<output.cognome<<endl;
cout<<"Eta': "<<output.eta<<endl;
}
cout<<"--------------------------"<<endl;

fclose(fi);
}

void open(){
FILE *fi;
fi= fopen("esempio1.dat","wb");
if (fi==NULL) perror("Error opening file fi");
cout <<"creazione file binario riuscita "<<endl;
fclose(fi);
}

int main()
{
int scelta;

    do{
        cout<<endl<<"1.Crea file"<<endl;
        cout<<"2.Inserisci"<<endl;
        cout<<"3.Stampa"<<endl;
        cin>>scelta;

  switch(scelta){
    case 1:
        open();
        break;
    case 2:
        save();
        break;
    case 3:
        load();
        break;

        }

    }
    while(scelta!=0);

return 0;
}
