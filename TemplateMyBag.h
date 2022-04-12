#pragma once

template <class T>
class MyBag {
private:
    vector<T> array;
public:
    
    MyBag()
    {
        array.clear();
    }

    MyBag(T* a)
    {
        for (int i = 0; i < array.size(); i++)
            ary[i] = a[i];
    }
    
    //precondition: none
    //postcondition: gets size of array
    int getSize()
    {
        return array.size();
    }
    
    //precondition: none
    //postcondition: gets element in position i of array
    T getelement(int i)
    {
        return array[i];
    }

    //Precondition: user input to display array
    //Postcondition: displays current array setup

    void display()
    {
        cout << endl << "Displaying array: \n";

        for (int i = 0; i < array.size(); i++)
            cout << array[i] << '\n';
    }

    //Precondition: user input to enter new integer into array
    //Postcondition: places an integer, then adds to the dynamic array size
    void insertElement(T num)
    {
        array.push_back(num);
    }

    //Precondition: user input to remove a certain array
    //Postcondition: removes the array, and subtracts to the dynamic array
    void removeElement(int index)
    {
        array.erase(array.begin() + index);
    }
    //Precondition: user input to search an integer 
    //Postcondition: displays the integer found at specific index
    void searchElement(T SearchArray)
    {
        bool found = false;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] == SearchArray)
            {
                found = true;
                cout << SearchArray << " found at index " << i << endl;
            }
        }

        if (found == false)
            cout << SearchArray << " was not found in Mybag." << endl;
    }

    //Precondition: user input to sort current array
    //Postcondition: sorts array then displays sorted array
    void sortArray()
    {
        cout << endl << "The sorted array is: \n";

        sort(array.begin(), array.end());
        for (int i = 0; i < array.size(); i++)
            cout << array[i] << '\n';
    }


    //Precondition: user input to clear the array
    //Postcondition: clears the array
    void clearArray()
    {
        array.clear();
        cout << endl << "The array has been cleared. \n";
    }
};

//precondition: none
//postcondition: displays the Double Template Class MyBag Menu
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
//postcondition: user chooses the Double Template Class MyBag Menu
void TemplateMyBagMenu()
{
    MyBag<double> h;
    do
    {
        switch (TemplateClassMenuOption())
        {
        case 0: return; break;
        case 1: h.clearArray(); break;
        case 2: h.insertElement(inputDouble("Enter a double: ")); break;
        case 3: h.searchElement(inputInteger("Enter a value you wish to find: ", 0, h.getSize())); break;
        case 4: h.removeElement(inputInteger("Enter a index you wish to delete at: ", 0, h.getSize())); break;
        case 5: h.sortArray(); break;
        case 6: h.display(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

};
