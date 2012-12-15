#include <iostream>

using namespace std;

struct klijent{
  char ime[40],prezime[40],valuta[30];
  int godina,ai_ulazak,bi_zadrzavanje,ci_prioritet,di_transakcija;
  float stanje_tekuci,stanje_devizni;
  };

struct red{
       int front,rear;
       klijent *osobe[10000];
       };

void EnQueueQ(red *element, klijent *osoba){
     int zadnja_pozicija=element->rear;
     zadnja_pozicija=AddOne(zadnja_pozicija);
     element->osobe[zadnja_pozicija]=osoba;
     element->rear=zadnja_pozicija;
     }
     
klijent *FrontQ(red *element){
        return element->osobe[element->front];
        }

void DeQueueQ(red *element){
     element->front=AddOne(element->front);
     }

void InitQ(red *element){
     element->front=0;
     element->rear=9999;
     }

bool IsEmpty(red *element){
     if(AdOne(element->rear)==element->front)return true;
     else return false;
     }
     
int AddOne(int rear){
    rear=(rear+1)%10000;
    return rear;
    }
