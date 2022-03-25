#include <iostream>
#include <stack>
#include <iomanip>
#include <iterator>
#include <cmath>
#include <string>
#include <list>
#include <cstring>
#include <sstream>
#include <chrono>
#include <vector>
#include <fstream>
#include "input.h"

using namespace std;



class MyBag {
private:
    int* array;
    int size;
    
public:
    
    MyBag()
    {
        array = nullptr;
        size = 0;
    }
    MyBag(int* a, int newSize)
    {
        size = newSize;
        array = new int[size];

        for (int i = 0; i < size; i++)
            array[i] = a[i];
    }
    ~MyBag()
    {
        delete[] array;
    }

    void display() const
    {
        cout << endl << "Displaying array: \n";

        for (int i = 0; i < size; i++)
            cout << array[i] << '\n';
        
    }

    void sortArray()
    {
        cout << endl << "The sorted array is: \n";

        sort(array, array + size);
    }

     void insert()
    {
         int newInt = inputInteger("Enter new integer: ");
         for (int i = 0; i < newInt; i++)
         {
             
         }
         
    
    }

     void clear()
     {
         size = 0;
         cout << endl << "The array has been cleared. \n";
    }

     

};

int nonTemplateMenuOption()

{
    cout << endl << "1> Non-template MyBag of integers";
    cout << endl << "==========================================";
    cout << endl << "1 > clear";
    cout << endl << "2 > insert";
    cout << endl << "3 > search";
    cout << endl << "4 > remove";
    cout << endl << "5 > sort";
    cout << endl << "6 > display";

    cout << endl << "==========================================";
    cout << endl << "0. Exit";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 6);
    cout << endl << endl << endl;
    return options;
}




void main()
{
    
   // vector<int> vectorOfInts;
    MyBag h;
    
    do
    {
        switch (nonTemplateMenuOption())
        {
        case 0: return; break;
               case 1: h.clear(); break;
               case 2:  h.insert(); break;
             //  case 3: search(); break;
             //  case 4: remove(); break;
               case 5: h.sortArray(); break;
               case 6: h.display(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}
