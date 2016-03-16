//Creazione di un albero binario (indicando tutto il percorso dei nodi
// se a destra o a sinistra e visita in ordine anticipato

#include <iostream>
#include <string>
using namespace std;

struct elem{
        char c;
        elem *SS;
        elem *SD;
               };


 class balbero {
      elem *SS, *SD;

  public:
      balbero() {

                }

 elem *albBin()                 //creazione albero binario
  {
  elem *p=NULL;
  char x;
  do {
    cout<<"inserisci carattere, 0 per uscire "<<endl;
    cin>> x;
    if(x!='0') p=creaNodo(p,x);
    cout<<" albero............. radice"<<p<<endl;
   }while(x!='0');

   return p;       //restituisce radice
  }


 elem *creaNodo(elem *p, char n)
    {char sc;
      if(p==NULL) { p=new(elem);
                    p->c=n;
                    p->SS=NULL;
                    p->SD=NULL;
                      }
        else {  cout<<"a dx o a sx? (s/d) "<<endl;
                cin>>sc;
                if(sc=='s') p->SS= creaNodo(p->SS,n);
                else    p->SD= creaNodo(p->SD,n);}
   cout<<"crea .......nodo"<<p<<endl;
   cout<<"sottoalb sx..."<<p->SS<<endl;cout<<"sottoalb dx ..."<<p->SD<<endl;
   return p;                       //puntatore alla radice
    }

    void anticipato(elem *p)
    {
        if(p!=NULL) {
            cout <<p->c<<endl;
            anticipato(p->SS);      //sotto albero sinistro
            anticipato(p->SD);      //sotto albero destro
        }
    }

     };

 int main(){
 //
 elem *radice; //puntatore radice
 balbero bal;
 radice= bal.albBin();  //creazione albero binario
 cout<<"visita in ordine anticipato  "<<endl;
 cout<<" radice ............"<<radice<<endl;
  bal.anticipato(radice);
 //
   return (0);
  }


