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
    int options = inputInteger("Options: ", 0, 4);
    cout << endl << endl << endl;
    return options;
}

void main()
{
    
    do
    {
        switch (nonTemplateMenuOption())
        {
        case 0: return; break;
     //   case 1: clear(); break;
     //   case 2: insert(); break;
      //  case 3: search(); break;
      //  case 4: remove(); break;
      //  case 5: sort(); break;
       // case 6: display(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}

void clear()
{

}
void insert()
{

}
void search()
{

}
void remove()
{

}
void sort()
{

}
void display()
{

}
