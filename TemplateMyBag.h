#pragma once

template <class T>
class MyBag {
private:
    vector<T>  array;
public:
    
    //constuctor
    MyBag()
    {
         array.clear();
    }

    //copy constuctor
    MyBag(vector<T> a)
    {
        for (int i = 0; i <  array.size(); i++)
             array[i] = a[i];
    }

    //Precondition: none
    //Postcondition: returns the size of the array
    const int getSize()
    {
        return  array.size();
    }

    //Precondition: an int to serve as an index
    //Postcondition: returns an elemment 
    const T getelement(int i)
    {
        return  array[i];
    }

    //Precondition: none
    //Postcondition: displays current array setup
    const void display()
    {
        if ( array.size() == 0)
        {
            cout << "My Bag is empty. " << endl;
            return;
        }
        cout << endl << "Displaying array: \n";

        for (int i = 0; i <  array.size(); i++)
            cout <<  array[i] << '\n';
    }

    //Precondition: user input to enter new integer into array
    //Postcondition: places an integer, then adds to the dynamic array size
    void insertElement(T num)
    {
         array.push_back(num);
    }

    //Precondition: user input to remove a certain array
    //Postcondition: removes the array, and subtracts to the dynamic array
    void removeElementAtIndex(int index)
    {
         array.erase( array.begin() + index);
    }

    //Precondition: user input to remove a certain array
    //Postcondition: removes the array, and subtracts to the dynamic array
    void removeElementAtValue(T value)
    {
        bool found = false;
        for (int i = 0; i <  array.size(); i++)
        {
            if ( array[i] == value)
            {
                found = true;
                cout << "Element " <<  array[i] << " erased at index " << i << endl;
                 array.erase( array.begin() + i);
            }
        }

        if (found == false)
            cout << value << " was not found in Mybag." << endl;
    }

    //Precondition: user input to search an integer 
    //Postcondition: displays the integer found at specific index
    const void searchElement(T SearchArray)
    {
        bool found = false;
        for (int i = 0; i <  array.size(); i++)
        {
            if ( array[i] == SearchArray)
            {
                found = true;
                cout << "Element found at index " << i << endl;
            }
        }

        if (found == false)
            cout << SearchArray << " was not found in Mybag." << endl;
    }

    //Precondition: none
    //Postcondition: sorts array then displays sorted array
    void sortArray()
    {
        if ( array.size() == 0)
        {
            cout << "My Bag is empty. " << endl;
            return;
        }
        cout << endl << "The sorted array is: \n";

        sort( array.begin(),  array.end());
        for (int i = 0; i <  array.size(); i++)
            cout <<  array[i] << '\n';
    }


    //Precondition: none
    //Postcondition: clears the array
    void clearArray()
    {
         array.clear();
        cout << endl << "The array has been cleared. \n";
    }

    //Precondition: none
    //Postcondition: clears the array
    void creationClearArray()
    {
         array.clear();
    }
};



//precondition: none
//postcondition: displays the Double Template Class MyBag Menu
int TemplateClassMenuOption()
{
    cout << endl << "2> Template MyBag of double";
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

//Precondition: takes in a Mybag of doubles
//Postcondition: removes a value at a specfied index
const void search(MyBag<double> h)
{
    if (h.getSize() == 0)
    {
        cout << "MyBag is Empty." << endl;
        return;
    }
    h.searchElement(inputDouble("Enter a Value you want to earch for: ", true));
}

//Precondition: takes in a Mybag of doubles
//Postcondition: removes a value at a specfied index
void remove(MyBag<double> &h)
{
    if (h.getSize() == 0)
    {
        cout << "MyBag is Empty." << endl;
        return;
    }
    h.removeElementAtValue(inputDouble("Enter a Value you want to remove: "));
}


//precondition: none
//postcondition: user chooses the Double Template Class MyBag Menu
void TemplateMyBag()
{
    MyBag<double> h;
    do
    {
        switch (TemplateClassMenuOption())
        {
        case 0: return; break;
        case 1: h.clearArray(); break;
        case 2: h.insertElement(inputDouble("Enter a double: ")); break;
        case 3: search(h); break;
        case 4: remove(h); break;
        case 5: h.sortArray(); break;
        case 6: h.display(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}
