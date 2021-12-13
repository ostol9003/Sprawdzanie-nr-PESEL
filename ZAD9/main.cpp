//
//  main.cpp
//  ZAD9
//
//  Created by Marcin Ostolski on 13/12/2021.
//

#include<iostream>
using namespace std;

struct osoba
{
    string imie;
    string nazwisko;
    string plec;
    long pesel;
    string x;
    
              
}osoby[10];

void pdanych (int l)
{
        cout<<"Podaj imie :"<<endl;
        getline(cin,osoby[l].imie);
        cout<<"Podaj nazwisko :"<<endl;
        getline(cin,osoby[l].nazwisko);
        cout<<"Podaj pesel :"<<endl;
        cin>>osoby[l].pesel;
        cin.ignore();
}

string sprpesel(long pesel,int i)
{
    int p[11];
    
    string napis = to_string(pesel);
    int ile = napis.length();
    if (ile!=11)
    osoby[i].x="Wprowadzony PESEL jest za krotki!";
    
    else
    {
        string napis = to_string(pesel);
        for (int l=0;l<11;l++)
            {
            char znak = napis[l];
            p[l] = znak;
            }
           //sprawdzamy pesel
    int spr=p[0]*1+p[1]*3+p[2]*7+p[3]*9+p[4]*1+p[5]*3+p[6]*7+p[7]*9+p[8]*1+p[9]*3+p[10]*1;
    
    if (spr % 10==0)
    {
        osoby[i].x="Wprowadzony PESEL jest poprawny.";
            if (p[9]%2==0)
                osoby[i].plec="Kobieta";
            else osoby[i].plec="Mezczyzna";
    }
    
    else
        osoby[i].x="Wprowadzony PESEL jest niepoprawny!";
        
    
    }
    return osoby[i].x, osoby[i].plec;
    
}



int main()
{
    int l;
    char odp;
    l=0;
    cout<<"Witam! Program pobiera i sprawdza:\n- poprawnosc wprowadzonego numeru PESEL\n- plec na jego podstawie"<<endl;
    
    
    //Wczytanie danych
            do
            {
            pdanych(l);
        
            l++;
                
            cout<<"Czy chcesz dodac kolejna osobe? T/N"<<endl;
            cin>>odp;
                cin.ignore();
            }while(odp=='T' or odp=='t');
    
    //sprawdzenie nr PESEL
    
            for (int i=0;i<l;i++)
            {
                sprpesel(osoby[i].pesel,i);
            }
    
    //Wyswietlenie informacji
    
            cout<<"Liczba wprowadzonych osob - "<<l<<endl;
            for (int i=0;i<l;i++)
            {
            cout<<"Imie : "<<osoby[i].imie<<endl;
            cout<<"Nazwisko : "<<osoby[i].nazwisko<<endl;
            cout<<osoby[i].x<<endl;
            cout<<"Plec: "<<osoby[i].plec<<endl<<endl<<endl;
            }
        
}
