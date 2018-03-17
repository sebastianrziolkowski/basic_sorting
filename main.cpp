#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void showTab(int *tab, int tabsize)
{
    for(int i=0;i<tabsize;i++)
        cout<<tab[i]<<endl;
}

int* CreateTab(int *tab, int tabsize)
{
    tab = new int[tabsize];
    for(int i=0;i<tabsize;i++)
        tab[i]=rand() % 100;

    return tab;
}


int* WorstTabToSort(int *tab, int tabsize)
{
    for(int i=0;i<tabsize;i++)
        tab[i]=tabsize-i;

    return tab;
}

void BubbleSort(int *tab, int tabsize)
{
   bool swapped=true;
   int i=0;
   while((swapped==true)&&(i<tabsize-1))
   {
     swapped = false;
     for (int j=0;j<tabsize-i-1;j++)
     {
        if (tab[j]>tab[j+1])
        {
           swap(tab[j], tab[j+1]);
           swapped = true;
        }
     }
    i++;
   }
}


void  Insertion_Sort(int *tab, int tabsize)
{
    int temp=0;
    int x=0;
    for(int i=1;i<tabsize;i++)
    {
        x=i;
        temp=tab[i];
        while((x>0)&&(tab[x-1]>temp))
        {
            tab[x]=tab[x-1];
            x--;
        }
        tab[x]=temp;
    }
}



int main()
{
    int tabsize = 10;
    srand( time( NULL ) );
    int *tab = CreateTab(tab, tabsize);
    tab=WorstTabToSort(tab, tabsize);
    BubbleSort(tab, tabsize);
    showTab(tab, tabsize);

    return 0;
}
