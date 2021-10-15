#ifndef SORTOWANIA_H_INCLUDED
#define SORTOWANIA_H_INCLUDED

using namespace std;

void sortowanieBabelkowe(int* tab, int n, int tryb)
{
    int i , j, p;
    i  = n - 1 ;
    while(i > 0)
    {
        j = 0;
        p = 1;
        while(j < i)
        {
            if(tab[j] < tab[j + 1] && tryb == 1)
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp ;
            }
            else if (tab[j] > tab[j + 1] && tryb == 2)
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp ;
            }
            p = 0 ;
            j = j + 1;
        }
        if(p == 1)
        {
            break;
        }
        i-- ;
    }
}
void sortowaniePrzezWybor(int* tab, int n, int tryb)
{
    int i , ind, j  ;
    i = n - 1;
    while(i > 0)
    {
        ind = 0;
        j = 1 ;
        while(j <= i)
        {
            if(tab[j] < tab[ind] && tryb == 1)
            {
                ind = j;
            }
            else if(tab[j] > tab[ind] && tryb == 2)
            {
                ind = j ;
            }
            j++ ;
        }
        swap(tab[i] , tab[ind]);
        i-- ;
    }
}
void sortowaniePrzezWstawianie(int* tab, int n, int tryb)
{
    int  i , j ,temp;
    i = n - 2;
    while(i >= 0)
    {
        j = i;
        if(tryb == 2)
        {
            temp = tab[j];
            while(temp > tab[j + 1] && j < n - 1)
            {
                tab[j] = tab[j + 1];
                j++;
            }
        tab[j] = temp;
        }
        if(tryb == 1)
        {
            temp = tab[j];
            while(temp < tab[j + 1] && j < n - 1)
            {
                tab[j] = tab[j + 1];
                j++;
            }
        tab[j] = temp;
        }
        i--;
    }

}
void sortowanieBabelkowe2D(int** tab, int w, int k, int tryb, int nrKol)
{

    int i , j ;
    i  = w - 1 ;
    while(i > 0)
    {

        j = 0;
        while(j < i)
        {
            if(tab[j][nrKol] > tab[j + 1 ][nrKol] && tryb == 2)
            {

                for(int z = 0 ; z < k ; z++)
                {

                    swap(tab[j + 1][z],tab[j][z]);

                }

            }
            if(tab[j][nrKol] < tab[j + 1 ][nrKol] && tryb == 1)
            {

                for(int z = 0 ; z < k ; z++)
                {

                    swap(tab[j + 1][z],tab[j][z]);

                }

            }
            j++;
        }
        i--;

    }


}
void sortowanieSzybkie(int *x, int lewy, int  prawy)
{
    int srodek = (int)(lewy + prawy)/2;
    int pivot = x[srodek];
    x[srodek] = x[prawy];
    int granica = lewy;
    int i = lewy;
    while(i < prawy)
    {
        if(x[i] < pivot)
        {
            swap(x[granica] , x[i]);
             granica++ ;
        }

        i++ ;
    }
    x[prawy] = x[granica];
    x[granica] = pivot;
    if(lewy < granica -1 )
    {
        sortowanieSzybkie(x , lewy ,granica - 1);
    }
    if(granica +1 < prawy)
    {
        sortowanieSzybkie(x , granica + 1 ,prawy);
    }
}
#endif // SORTOWANIA_H_INCLUDED
