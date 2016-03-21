//GESTIONE FILE BINARIO DI RECORD


#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct Persona {
   char nome[20], cognome[20], eta[20];
};


int main()
{
FILE *fi;

Persona Pers;
int scelta, n, NumRec;
do{
cout<<"scelta 1.crea file binario- 2. inserisce dati alla fine - 3. visualizza dati "<<endl;
cout<<" 4. modifica dati 0. uscita "<<endl;
 cin>>scelta;
switch(scelta) {
   case 1:
          fi=fopen("esempio1.dat","wb");
          if (fi==NULL){
                perror("Error opening file fi");
                return(1);
                }
          cout <<"creazione file binario riuscita "<<endl;
          fclose(fi);
          break;
   case 2://Inserimento cambiato per adattarlo al sistema di stampa con fscanff e fprintf
          fi=fopen("esempio1.dat","ab");
          if (fi==NULL){
                perror("Error opening file fi");
                return(1);
                }

          cout<<"inserisci nome, cognome, eta' "<<endl;
          cin>>Pers.nome>>Pers.cognome>>Pers.eta;
          fprintf(fi,"%s %s %s \n",Pers.nome,Pers.cognome,Pers.eta);
          fclose(fi);
          break;

   case 3://Stampa risolta
          fi=fopen("esempio1.dat","rb");
          if (fi==NULL){
                perror("Error opening file fi");
                return(1);
                }

            while(true){
            fscanf(fi,"%s %s %s",Pers.nome,Pers.cognome,Pers.eta);
            if(feof(fi)) break;
            printf("Nome: %s Cognome:%s eta:%s \n",Pers.nome,Pers.cognome,Pers.eta);
            }

          fclose(fi);
          break;

   case 4://nessuna modifica eseguita
          fi=fopen("esempio1.dat","rb+");

          if (fi==NULL){
                perror("Error opening file fi");
                return(1);
          }

          cout <<"numero record da variare - 0 per finire "; cin>>n;

          while (n>0) {

            fseek(fi,0, SEEK_END);

            NumRec=ftell(fi)/sizeof(Persona);

            cout<<"numero byte "<<ftell(fi)<<" numero record "<<NumRec<<endl;

            if(n>NumRec)
                cout<<"record inesistente, il max e' "<<NumRec<<endl;
            else {
              fseek(fi,(n-1)*sizeof(Persona),SEEK_SET);
              fread(&Pers,sizeof(Persona),1,fi);
              cout <<Pers.nome<<" "<<Pers.cognome<<" "<<Pers.eta<<endl;
              cout<<"inserire nuova eta' "<<endl; cin>>Pers.eta;
              fseek(fi, -sizeof(Persona),SEEK_CUR);
              fwrite(&Pers,sizeof(Persona),1,fi);

            }

            cout <<"numero record da variare - 0 per finire "; cin>>n;
          }
          fclose(fi);
          break;
}

}while(scelta!=0);

return 0;
}
