//GESTIONE FILE BINARIO DI RECORD

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Dati{
    string nome;
    string cognome;
    int eta;
};

struct Dati dati[2];
struct Dati output[2];

void save()
{
FILE *fi;
fi=fopen("esempio1.dat","ab");
fwrite(dati,sizeof(dati),2,fi);
fclose(fi);
}

void load()
{
FILE *fi;
fi=fopen("esempio1.dat","rb");

if(fi==NULL) {perror("Errore scrittura");}

if(fi != NULL){
    //for(int i=0;i<2;i++)
        fread(output,sizeof(struct Dati),2,fi);
   // }
}
else cout<<"Errore Load"<<endl;

fclose(fi);
}


int main()
{
FILE *fi;

          //Apertura
          fi= fopen("esempio1.dat","wb");
          if (fi==NULL){perror("Error opening file fi"); return(1);}
          cout <<"creazione file binario riuscita "<<endl;
          fclose(fi);

          //Inserisci
          cout<<"Inserisci nome, cognome , eta: ";
          cin>>dati[0].nome>>dati[0].cognome>>dati[0].eta;
          cout<<"Inserisci nome, cognome , eta: ";
          cin>>dati[1].nome>>dati[1].cognome>>dati[1].eta;
          save();



            output[1].nome="vuoto";
            output[1].cognome="vuoto";
            output[1].eta=0;


          //Stampa
          load();


           cout<<"Nome: "<<output[0].nome<<endl;
           cout<<"Cognome: "<<output[0].cognome<<endl;
           cout<<"Eta: "<<output[0].eta<<endl;

           cout<<"Nome: "<<output[1].nome<<endl;
           cout<<"Cognome: "<<output[1].cognome<<endl;
           cout<<"Eta: "<<output[1].eta<<endl;


return 0;
}
