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


template <class T>
class MyBag {
private:
    T* array;
    int size;
    int index;
public:
    MyBag()
    {
        array = new T[10];
        size = 0;
        index = 0;
    }
    MyBag(T* a, int newSize)
    {
        size = newSize;
        array = new T[10];

        for (int i = 0; i < size; i++)
            array[i] = a[i];
    }
    ~MyBag()
    {
        delete[] array;
    }

    //Precondition: user input to display array
    //Postcondition: displays current array setup

    void display()
    {
        cout << endl << "Displaying array: \n";

        for (int i = 0; i < size; i++)
            cout << array[i] << '\n';


    }

    //Precondition: user input to enter new integer into array
    //Postcondition: places an integer, then adds to the dynamic array size
    void insert()
    {
        T num = { inputDouble("Enter new integer into array: ") };
        array[index] = num;
        index++;
        size++;
    }

    //Precondition: user input to remove a certain array
    //Postcondition: removes the array, and subtracts to the dynamic array
    void remove()
    {

        int remove = { inputInteger("Enter position to remove: ") };

        for (int i = remove; i < size - 1; i++)
        {
            array[i] = array[i + 1];
        }
        array[index - 1] = {};
        size--;
    }
    //Precondition: user input to search an integer 
    //Postcondition: displays the integer found at specific index
    void search()
    {
        int SearchArray = inputInteger("Search: ");
        for (int i = 0; i < size; i++) {
            if (array[i] == SearchArray) {
                cout << "Element found at index " << i;
            }
        }

    }

    //Precondition: user input to sort current array
    //Postcondition: sorts array then displays sorted array
    void sortArray()
    {
        cout << endl << "The sorted array is: \n";

        sort(array, array + size);
        for (int i = 0; i < size; i++)
            cout << array[i] << '\n';
    }


    //Precondition: user input to clear the array
    //Postcondition: clears the array
    void clear()
    {
        size = 0;
        cout << endl << "The array has been cleared. \n";
    }



};

//precondition: none
//postcondition: displays the Double Template Class MyBag menu
int TemplateClassMenuOption()

{
    cout << endl << "1> Template MyBag of double";
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



//precondition: none
//postcondition: chooses menu for the Double Template Class MyBag menu
void TemplateMyBag()
{
    MyBag<double> h;
    do
    {
        switch (TemplateClassMenuOption())
        {
        case 0: return; break;
        case 1: h.clear(); break;
        case 2: h.insert(); break;
        case 3: h.search(); break;
        case 4: h.remove(); break;
        case 5: h.sortArray(); break;
        case 6: h.display(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}
