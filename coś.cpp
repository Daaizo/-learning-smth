#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};
void stworzTabliceStudentow(student *&tab, int* );
void wczytajStudentow(student*&tab, int n);
void usunTabliceStudentow(student *&tab);
void wyswietlStudentow(student* tab, int n1 ,int n2);
int podzial2czesci(student*&tab , int rozmiar ,int granica);
int podzial3czesci(student*&tab , int rozmiar ,int granica2 , int *wartosc_2); // granica 2 tu nic nie robi jak cos

int main()
{
    int choice = 0 ;
    int rozmiar_tab = 0 ;
    student* tab = nullptr;
    while(choice != 5)
    {
        cout << "\nMENU\n1. Zadanie 4.1 \n2. Zadanie 4.2 \n3. Zadanie 4.3 \n5. Wyjscie\n" ;
        cout << "\nPodaj swoj wybor " << endl;
        cin >> choice ;
        switch(choice)
        {
        case(1):
            {


                stworzTabliceStudentow(tab , &rozmiar_tab);
                cout << rozmiar_tab;
                wczytajStudentow(tab ,rozmiar_tab);
                wyswietlStudentow(tab, 0 ,rozmiar_tab);
                break;
            }
        case(2):
            {
                int r = podzial2czesci(tab ,rozmiar_tab ,10);
                cout << "\n\nstudenci z punktami <= 10 \n\n";
                wyswietlStudentow(tab, 0  ,r);
                cout << "\n\nstudenci z punktami > 10 \n\n";
                wyswietlStudentow(tab, r  ,rozmiar_tab);
                break;
            }
        case(3):
            {
                int wartosc2 = 0 ;
                //int granica =
                int h = podzial3czesci(tab, rozmiar_tab ,1 ,&wartosc2);
                cout << "\n\nstudenci z punktami podzielnymi przez 3  \n\n";
                wyswietlStudentow(tab, 0  ,h + 1 );
                cout << "\nstudenci z punktami podzielnymi przez 3 z reszta 2\n" ;
                wyswietlStudentow(tab, h +1   ,wartosc2 );
                cout << "\nstudenci z punktami podzielnymi przez 3 z reszta 1\n" ;
                wyswietlStudentow(tab, wartosc2,rozmiar_tab);
                break;
            }
        case(5):
            {
                cout << "wychodzenie" ;
                break;
            }
        default :
            {
                cout << "bledny numer" ;

            }
        }
    }
    usunTabliceStudentow(tab);
    return 0;
}


void stworzTabliceStudentow(student *&tab  ,int *rozmiar)
{
    int liczbaStudentow;
    string sciezka;
    ifstream plik;
    sciezka="studenci.csv";
    plik.open(sciezka);
    plik >> liczbaStudentow;
    tab = new student[liczbaStudentow];
    *rozmiar = liczbaStudentow;
    plik.close();
}
void wczytajStudentow(student*&tab, int n)
{
    string sciezka,linia,pomoc;
    ifstream plik;
    char sredniki;
    sciezka="studenci.csv";
    plik.open(sciezka);

    for(int i = 0; i < 4; i++)
    {
        plik >> sredniki;
    }
    for(int i=0; i<n; i++)
    {
        plik>>linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        getline(ss, pomoc);
        tab[i].punkty=atoi(pomoc.c_str());
    }
    plik.close();
}
void wyswietlStudentow(student* tab, int n1 ,int n2)
{
    cout << "imie " << " nazwisko" << " punkty" <<  endl;
    for(int i = n1 ;i < n2 ; i++)
    {
        //cout << "imie = "  << tab[i].imie << " nazwisko = " << tab[i].nazwisko << " punkty = " <<tab[i].punkty << endl;
        cout << tab[i].imie << " " << tab[i].nazwisko << " " <<tab[i].punkty << endl;
    }
}
int podzial2czesci(student*&tab, int rozmiar ,int granica)
{
    int i = 0 ,j = rozmiar -1 ;
    while(i < j)
    {
        while((tab[i].punkty <= granica )&& (i < j))
        {
            i++;
        }
         while((tab[j].punkty > granica )&& (i < j))
        {
            j--;
        }
        if(i < j)
        {
            swap(tab[i] , tab[j]);
            i++;
            j--;
        }

    }
    if(tab[i].punkty <= granica)
    {
        return i + 1;
    }
    else return i;
}
int podzial3czesci(student*&tab , int rozmiar ,int granica2 , int *wartosc_2)
{
    int i = -1, j = 0, k = rozmiar ;
    while(j < k)
    {
        if (tab[j].punkty %3 == 0)
        {
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else
        {
            if( tab[j].punkty %3 == 1 )
            {
                k--;
                swap(tab[k], tab[j]);
            }
            else if (tab[j].punkty %3 == 2) j++;
        }
    }
    *wartosc_2 = k;
    return i ;
}

void usunTabliceStudentow(student *&tab)
{
    delete [] tab;

}
