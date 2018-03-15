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

int main()
{
srand( time( NULL ) );
int *tab = CreateTab(tab, 10);
tab=WorstTabToSort(tab,10);
showTab(tab,10);

    return 0;
}
