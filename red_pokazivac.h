#include <iostream>

using namespace std;

struct klijent{
  char ime[40],prezime[40],valuta[30];
  int godina,ai_ulazak,bi_zadrzavanje,ci_prioritet,di_transakcija;
  float stanje_tekuci,stanje_devizni;
  klijent *sljedeci;
  };

struct red{
       klijent *front, *rear;
       };

void EnQueueQ(red *element,klijent *osoba){
     element->rear->sljedeci=osoba;
     element->rear=osoba;
     osoba->sljedeci=NULL;
     }
     
klijent *FrontQ(red *element){
        return element->front->sljedeci;
        }

void DeQueueQ(red *element){
     klijent *pomocni=element->front;
     element->front=pomocni->sljedeci;
     delete pomocni;
     }

void InitQ(red *element){
     klijent *glava=new klijent;
     glava->sljedeci=NULL;
     element->front=glava;
     element->rear=glava;
     }

bool IsEmptyQ(red *element){
     if(element->rear==element->front)return true;
     else return false;
     }
