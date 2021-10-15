#ifndef TABLICE_H_INCLUDED
#define TABLICE_H_INCLUDED
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <iomanip>
#include <string>
void przydzielPamiec1D(int *&tab, int rozmiar)
{
    tab = new int[rozmiar];
}
void przydzielPamiec2D(int **&tab, int wiersze, int kolumny)
{
    tab = new int*[wiersze];
    for(int i = 0 ; i < wiersze ; i++)
    {
        tab[i] = new int[kolumny];
    }
}
void wypelnijTablice1D(int *tab, int rozmiar, int zakres_od, int zakres_do)
{
    srand(time(NULL));
    for(int i = 0 ; i < rozmiar ; i++)
	{
		int liczba = rand()%(zakres_do-zakres_od+1)+zakres_od;
		tab[i] = liczba;
	}
}
void wypelnijTablice2D(int **tab, int wiersze, int kolumny, int zakres_od, int zakres_do)
{
    srand(time(NULL));
    for(int i = 0 ; i < wiersze ; i++)
	{
	    for(int j = 0 ; j < kolumny ; j++)
        {
            int liczba = rand()%(zakres_do-zakres_od+1)+zakres_od;
            tab[i][j] = liczba;
        }
	}
}
void usunTablice1D(int *&tab)
{
    delete [] tab ;
}
void usunTablice2D(int **&tab, int wiersze)
{
    for(int i = 0 ; i < wiersze ;i++)
    {
        delete [] tab[i];
    }
    delete [] tab;
}
void wyswietl1D(int* tab, int rozmiar , std::string napis)
{
    std::cout << "\ntab " << napis << std::endl;
    for(int i = 0 ; i < rozmiar ;i++)
    {
        std::cout << tab[i] << " " ;
    }
}
void wyswietl2D(int** tab, int wiersze, int kolumny , std::string napis)
{
    std::cout <<"\ntab 2d " << napis << std::endl ;
    for(int i = 0 ; i < wiersze ; i++)
    {
        //std::cout << "wiersz nr " << i + 1  << std::endl;
        for(int j = 0 ; j < kolumny ; j++)
        {
            std::cout << std::setw(6) << tab[i][j] << " " ;
        }
        std::cout << std::endl;
    }
}
#endif // TABLICE_H_INCLUDED
