#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

void showTab(int *tab, int tabsize)
{
    for(int i=0;i<tabsize;i++)
        std::cout<<tab[i]<<std::endl;
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

void Bubble_Sort(int *tab, int tabsize)
{
    std::cout<<"Bubble_Sort"<<std::endl;
   bool swapped=true;
   int i=0;
   while((swapped==true)&&(i<tabsize-1))
   {
     swapped = false;
     for (int j=0;j<tabsize-i-1;j++)
     {
        if (tab[j]>tab[j+1])
        {
           std::swap(tab[j], tab[j+1]);
           swapped = true;
        }
     }
    i++;
   }
}


void  Insertion_Sort(int *tab, int tabsize)
{
    std::cout<<"Insertion_Sort"<<std::endl;
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



void Selection_Sort(int *tab, int tabsize)
{
    std::cout<<"Selection_Sort"<<std::endl;
    int lowest;
    int index;
    for(int i=0;i<tabsize;i++)
    {
        lowest=tab[i];
        index=i;
        for(int j=i;j<tabsize;j++)
        {
            if(lowest>tab[j])
            {
                lowest=tab[j];
                index=j;
            }
        }
        std::swap(tab[i], tab[index]);
    }
}

void Select_Sorting(int *tab, int tabsize)
{
    int choice;
    std::cout<<std::endl<<"Your choice:";
    std::cin>>choice;
    system("cls");
    std::cout<<"Your choice:"<<choice<<std::endl;
    switch(choice)
    {
    case 1:
        Selection_Sort(tab,tabsize);
        break;

    case 2:
        Insertion_Sort(tab,tabsize);
        break;

    case 3:
        Bubble_Sort(tab,tabsize);
        break;

    default:
        std::cout<<"Wrong input!"<<std::endl;
        delete []tab;
        exit(0);
        break;
    }
        showTab(tab,tabsize);
}

void ConsoleInterface()
{
    std::cout<<"Basic sorting algorithm..."<<std::endl;
    std::cout<<"Choose algorithm number:"<<std::endl<<std::endl;
    std::cout<<"1 - Selection_Sort "<<std::endl;
    std::cout<<"2 - Insertion_Sort  "<<std::endl;
    std::cout<<"3 - Bubble_Sort  "<<std::endl;
}

int main()
{
    srand( time( NULL ) );
    int tabsize = rand() %50;
    int *tab = CreateTab(tab, tabsize);         //Create random tab
    tab=WorstTabToSort(tab, tabsize);          //Comment this to get random tab or uncomment to get worst tab to sort
    ConsoleInterface();
    Select_Sorting(tab,tabsize);

    delete []tab;
    return 0;
}
