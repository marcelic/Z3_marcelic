#include <iostream>
#include<ctime>
#include<windows.h>
#include "red_pokazivac.h"
//#include "red_polje.h"

using namespace std;

red *novi_pomocni_red=new red;
klijent *pom=new klijent;
int N;

struct n_cetvorki{
  int ai_ulazak, bi_zadrzavanje, ci_prioritet, di_transakcija;
  };

n_cetvorki *elementi;

void generiranje_niza(red *Q){
     cout<<"Unesite N za generiranje podataka o osobama: ";
     cin>>N;
     elementi=new n_cetvorki[N];
     srand((time(0)));
     rand();
     for(int i=0;  i<N; i++){
             elementi[i].ai_ulazak=rand()%401+100;
             elementi[i].bi_zadrzavanje=rand()%401+100;
             do{
                elementi[i].ci_prioritet=rand()%6+1;
                elementi[i].di_transakcija=rand()%4+1;
                }while(elementi[i].ci_prioritet==6&&elementi[i].di_transakcija==4);
                }
             }

void ispis_podataka(klijent *pom){
     cout << "\n=======================================\n";
     cout << "Podaci o osobi\n";
     cout << "=========================================\n";
     cout << "Ime klijenta= "<< pom->ime<< endl;
     cout << "Prezime klijenta= "<< pom->prezime<< endl;
     cout << "Godine= "<< pom->godina<< endl;
     cout << "Stanje na tekucem racunu= "<< pom->stanje_tekuci<< endl;
     cout << "Stanje na deviznom racunu= "<< pom->stanje_devizni<< endl;
     cout << "Valuta deviznog racuna= "<< pom->valuta<< endl;
     cout << "Vrijeme ulaska klijenta= "<< pom->ai_ulazak<< endl;
     cout << "Trajanje transakcije= "<< pom->bi_zadrzavanje<< endl;
     cout << "Prioritet= "<< pom->ci_prioritet<< endl;
     cout << "Vrsta transakcije= "<< pom->di_transakcija<< endl<< endl;
     }

void dodavanje_zapisa(red *Q){
     for(int i=0 ;i<N; i++){
             klijent *pomak=new klijent;
             cout << "Unesite ime klijenta= ";
             cin >> pomak->ime;
             cout << "Unesite prezime klijenta= ";
             cin >> pomak->prezime;
             cout << "Unesite koliko klijent ima godina= ";
             cin >> pomak->godina;
             cout << "Stanje na tekucem racunu= ";
             cin >> pomak->stanje_tekuci;
             cout << "Stanje na deviznom racunu= ";
             cin >> pomak->stanje_devizni;
             cout << "Valuta deviznog racuna= ";
             cin >> pomak->valuta;
             pomak->ai_ulazak=elementi[i].ai_ulazak;
             pomak->bi_zadrzavanje=elementi[i].bi_zadrzavanje;
             pomak->ci_prioritet=elementi[i].ci_prioritet;
             pomak->di_transakcija=elementi[i].di_transakcija;
             EnQueueQ(Q, pomak);
             }
             klijent n_cetvorki[N];
             pom=new klijent;
             for(int i=0; i<N; i++){
                     pom=FrontQ(Q);
                     memcpy(&n_cetvorki[i],pom,sizeof(klijent));
                     DeQueueQ(Q);
                     }
             for(int i = 1; i < N; i++) {
                     int j=i-1;
                     int pom=n_cetvorki[i].ci_prioritet;
                     klijent pom2=n_cetvorki[i];
                     while(j>=0 && n_cetvorki[j].ci_prioritet>pom){
                                n_cetvorki[j+1]=n_cetvorki[j--];
                                n_cetvorki[j+1]=pom2;
                                }
                     }
             for(int i=0; i<N; i++){
                     klijent *novi=new klijent;
                     if(n_cetvorki[i].stanje_devizni>10000)ispis_podataka(&n_cetvorki[i]);
                     else{
                          memcpy(novi,&n_cetvorki[i],sizeof(klijent));
                          EnQueueQ(Q,novi);
                          }
                     }
             }

void brze_transakcije(red *Q){
     red stari[N];
     red broj[N];
     int brojac_stari=0;
     int brojac_broj=0;
     pom=new klijent;
     klijent *novi=new klijent;
     for(int i=0; i<N; i++){
             novi=FrontQ(Q);
             DeQueueQ(Q);
             if(novi->di_transakcija==3){
                                         memcpy(&broj[brojac_broj],novi,sizeof(klijent));
                                         brojac_broj++;
                                         }
                                         else {
                                              memcpy(&stari[brojac_stari],novi,sizeof(klijent));
                                              brojac_stari++;
                                              }
                                         }
             for(int i=0; i<brojac_stari; i++){
                     novi=new klijent;
                     memcpy(novi,&stari[i],sizeof(klijent));
                     EnQueueQ(Q,novi);
                     }
             cout << "\n===========================\n";
             cout << "RED STARIH TRANSAKCIJA\n";
             cout << "=============================\n";
             for(int i=0; i<brojac_stari; i++){
                     pom=new klijent;
                     memcpy(pom,&stari[i],sizeof(klijent));
                     ispis_podataka(pom);
                     }
             cout << "\n============================\n";
             cout << "RED BRZIH TRANSAKCIJA\n";
             cout << "==============================\n";
             for(int i=0; i<brojac_broj; i++){
                     memcpy(pom,&broj[i],sizeof(klijent));
                     ispis_podataka(pom);
                     }
             }

void brisanje_vip(red *Q){
     klijent *novi=new klijent;
     klijent n_cetvorki[N];
     int brojac_starije_osobe=0;
     for(int i=0; i<N; i++){
             novi=FrontQ(Q);
             DeQueueQ(Q);
             memcpy(&n_cetvorki[i],novi,sizeof(klijent));
             }
     InitQ(Q);
     for(int i=0; i<N; i++){
             memcpy(novi,&n_cetvorki[i],sizeof(klijent));
             if(novi->ci_prioritet==4&&(2012-novi->godina)<30&&novi->di_transakcija==1&&novi->stanje_tekuci<100){
                                                                                                                 ispis_podataka(novi);
                                                                                                                 }
             else if(novi->ci_prioritet==1&&novi->di_transakcija==2&&novi->stanje_tekuci>5000){
                  ispis_podataka(novi);
                  }
                  else {
                       brojac_starije_osobe++;
                       EnQueueQ(Q,novi);
                       }
                  }
             red stari_red[brojac_starije_osobe];
             cout << "STARI RED\n";
             for(int i=0; i<brojac_starije_osobe; i++){
                     memcpy(novi,&n_cetvorki[i],sizeof(klijent));
                     ispis_podataka(novi);
                     }
             }

void novi_salter(int sedamdeset,int trenutna_pozicija,red *Q){
     if(IsEmptyQ(Q)==true)
     return;
     klijent *p=new klijent;
     if(trenutna_pozicija<sedamdeset){
                                      p=FrontQ(Q);
                                      DeQueueQ(Q);
                                      trenutna_pozicija++;
                                      novi_salter(sedamdeset,trenutna_pozicija,Q);
                                      }
                                      else {
                                           while(IsEmptyQ(Q)==false){
                                                                     system("pause");
                                                                     klijent *d=new klijent;
                                                                     d=FrontQ(Q);
                                                                     DeQueueQ(Q);
                                                                     ispis_podataka(d);
                                                                     trenutna_pozicija++;
                                                                     EnQueueQ(novi_pomocni_red,d);
                                                                     }
                                           return;
                                      }
                                      EnQueueQ(Q,p);
                                      }

void ispis_stanja(red *Q){
     if(IsEmptyQ(Q)==true)
     return;
     klijent *p=new klijent;
     p=FrontQ(Q);
     DeQueueQ(Q);
     ispis_stanja(Q);
     EnQueueQ(Q,p);
     ispis_podataka(p);
     }

int main(){
    red *Q=new red;
    InitQ(Q);
    InitQ(novi_pomocni_red);
    int izbor;
    do{
        cout << "1. Generiranje niza\n";
        cout << "2. Dodavanje zapisa o klijentima banke\n";
        cout << "3. Brze transakcije\n";
        cout << "4. Brisanje VIP klijenata\n";
        cout << "5. Otvaranje novog saltera\n";
        cout << "6. Izlaz iz programa\n";
        cout << "\n Vas izbor je: \n";
        cin>>izbor;
        system("cls");
        switch(izbor){
                      case 1:
                           generiranje_niza(Q);
                           break;
                      case 2:
                           dodavanje_zapisa(Q);
                           break;
                      case 3:
                           brze_transakcije(Q);
                           break;
                      case 4:
                           brisanje_vip(Q);
                           break;
                      case 5:
                           int sedamdeset=N*0.7;
                           cout << "Sedamdeset= "<<sedamdeset<<endl;
                           cout << "Ispis pomocnog reda\n";
                           novi_salter(sedamdeset,0,Q);
                           cout << "STANJE GLAVNOG REDA\n";
                           ispis_stanja(Q);
                           cout << "ISPIS NOVOG REDA\n";
                           ispis_stanja(novi_pomocni_red); 
                           break;
                      }
        }while(izbor!=6);
        system("pause");
        return 0;
}
