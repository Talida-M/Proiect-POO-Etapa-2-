#pragma once
#include <iostream>
#include <string.h>
#include <vector>
#include "clasa_orfelinat.h"
#include "clasa_Orfani.h"
#include "clasa_Jucarii.h"
using namespace std;

class IstoricOrfelinat:public Orfelinat{
private:
   string nume_actual="X";
   vector<string> listaSponsori{"Pozzoli Gabrielle", "Han Suzy","Gabani Paul","Stojovska Sarah", "Sincai Gheorghe", "Modor Patrick"};
   vector<string> lista_denumiriVechi{"Miss Peregrine","Alice in Wonderland", "Wonderland"};
public:
    void setnume_actual(string nume_actual){this->nume_actual=nume_actual;}
    string getnume_actual(){return this->nume_actual;}
    void setlistaSponsori(vector<string> listaSponsori) { this->listaSponsori = move(listaSponsori); }
    vector<string> getlistaSponsori() { return listaSponsori; }
    void setlistadenumiri(vector<string> lista_denumiriVechi) { this->lista_denumiriVechi = move(lista_denumiriVechi); }
    vector<string> getlista_denumiriVechi() { return lista_denumiriVechi; }
    IstoricOrfelinat();
    ~IstoricOrfelinat(){}
    IstoricOrfelinat(const IstoricOrfelinat& istoric);
    IstoricOrfelinat &operator=(const IstoricOrfelinat& ist);
    virtual istream& CitireV(istream& in);
    virtual ostream& AfisareV(ostream& out)const;
    IstoricOrfelinat(int nr_camere, int angajati,float venit_alocat, string nume_actual,vector<string> listaSponsori, vector<string> lista_denumiriVechi):Orfelinat(nr_camere,angajati,venit_alocat){
        this->nume_actual=nume_actual;
        this->listaSponsori=listaSponsori;
        this->lista_denumiriVechi=lista_denumiriVechi;
    }

    void Istoric ( string nume_actual,vector<string> listaSponsori,vector<string> lista_denumiriVechi){
        cout<<"\n \t Bun venit la Centrul de Plasament "<<nume_actual<<", locul in care dorinta de a gasi o casa potrivita pentru copii nostri \n  priveaza, mai presus de orice.  Din dorinta de a oferi acestor micuti un loc in care sa poata spune, speram noi pentru \t un timp nu  foarte lung, acasa, in anul 1995,am creat acest castel de poveste.Pe parcursul acestor ani, \n  acest minunat loc a purtat mai multe denumiri de poveste, precum: \n";
         for(auto i=lista_denumiriVechi.begin();i<lista_denumiriVechi.end();i++){
            cout<<"\n o"<<*i<<"\n ";
        }
         cout<<"\n \t Iubirea pentru oameni si dorinta de a schimba in bine lumea este ceea ce ne ghideaza si incercam sa o insuflam   si minunatilor nostri copii.  \n \t Asadar, pentru a putea contribui si tu la scrierea unei povesti, pe langa sfatul nostru de a adopta, puteti de   asemenea deveni sponsorii nostri  si a aduce astfel mai multe zambete. In prezent pe lista noastra de sponsori\n se afla: \t \n ";
         for(auto i=listaSponsori.begin();i<listaSponsori.end();i++){
            cout<<"\n o"<<*i<<"\n ";}
        cout<<"\n \t Orice suma este foarte importanta! Exista si unele beneficii de care puteti beneficia cu cat donatia este mai \n  mare, una dintre ele fiind sansa de a putea schimba numele acestui loc, daca va simtiti inspirat.\t  \n  ";
        cout<<"\n  Ati dori sa va aflati pe lista sponsorilor nostri? da/nu: \n";
        string raspuns;
        cin>>raspuns;
        if (raspuns=="da"){
            cout<<"\n \t Ne bucuram ca ati ales sa faceti parte din lista sponsorilor nostri, completati aici nume dvs \t \n";
            string nume;
            cin>>nume;
            listaSponsori.push_back(nume);
            cout<<"\n Noua lista actualizata: ";
            for(auto i=listaSponsori.begin();i<listaSponsori.end();i++){
            cout<<"\n o"<<*i<<"\n ";}
            cout<<"\n Faceti o donatie(numerar): ";
            int donatie;
            cin>>donatie;
            if (donatie>=3000){
                cout<<"\n Va multumim pentru donatie, suma dvs va ajuta iubitii nostri copii, iar datorita sumei donate puteti daca doriti sa \n schimbati numele orfelinatului nostru. \n DORITI? da/nu \n";
                string raspuns1;
                cin>>raspuns1;
                if(raspuns1=="da"){
                    cout<<"Introduceti numele dorit: ";
                    string nume_dorit;
                    cin>>nume_dorit;
                    lista_denumiriVechi.push_back(nume_actual);
                    nume_actual=nume_dorit;
                    cout<<"\n Lista cu denumiri vechi s-a actualizat:\n ";
                     for(auto j=lista_denumiriVechi.begin();j<lista_denumiriVechi.end();j++){
                        cout<<"\n o"<<*j<<"\n ";
                    }
                }
                else
                    cout<<"\n Va multumim pentru donatie, suma dvs va ajuta iubitii nostri copii. Intelegem ca nu ati avut inspiratia sa schimbati denumirea acestui loc. \n";
        }
        else
            cout<<"\n Va multumim pentru donatie, suma dvs va ajuta iubitii nostri copii. De data aceasta nu ati primit niciun avantaj, dar tot ceea ce conteaza este binele facut!! \n";

        }
        else
            cout<<"\n Ne bucuram pentru timpul acordat, speram sa ne mai vizitati!! \n";
    }
};
