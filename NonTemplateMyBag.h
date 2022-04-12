class nonTemplateMyBag {
private:
    vector<int> array;
public:

    nonTemplateMyBag()
    {
        array.clear();
    }

    nonTemplateMyBag(int* a)
    {

        for (int i = 0; i < array.size(); i++)
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
    const int getelement(int i)
    {
        return  array[i];
    }

    //Precondition: user input to display array
    //Postcondition: displays current array setup
    const void display()
    {
        if (array.size() == 0)
        {
            cout << "My Bag is Empty." << endl;
            return;
        }
        cout << endl << "Displaying array: \n";

        for (int i = 0; i < array.size(); i++)
            cout << "[" << i << "] - " << array[i] << '\n';


    }

    //Precondition: user input to enter new integer into array
    //Postcondition: places an integer, then adds to the dynamic array size
    void insert()
    {
        int num = { inputInteger("Enter new integer into array: ") };
        array.push_back(num);
    }

    //Precondition: user input to remove a certain array
    //Postcondition: removes the array, and subtracts to the dynamic array
    void removeElementAtIndex(int index)
    {
        array.erase(array.begin() + index);
    }

    //Precondition: user input to remove at certain index
    //Postcondition: removes the array, and subtracts to the dynamic array
    void removeElementAtValue()
    {
        if (array.size() == 0)
        {
            cout << "My Bag is Empty." << endl;
            return;
        }

        int value = inputInteger("Enter a Value you want to remove: ");

        bool found = false;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] == value)
            {
                found = true;
                cout << "Element " << array[i] << " erased at index " << i << endl;
                array.erase(array.begin() + i);
            }
        }

        if (found == false)
            cout << value << " was not found in Mybag." << endl;
    }

    //Precondition: user input to search an integer 
    //Postcondition: displays the integer found at specific index
    const void search()
    {
        if (array.size() == 0)
        {
            cout << "My Bag is Empty." << endl;
            return;
        }
        int SearchArray = inputInteger("Search: ");
        bool found = false;
        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] == SearchArray)
            {
                found = true;
                cout << "Integer found at index [" << i << "]\n";
            }
        }
        if (found == false)
        {
            cout << SearchArray << " was not found in the array." << endl;
        }
    }

    //Precondition: userinput to sort current array
    //Postcondition: sorts array then displays sorted array
    void sortArray()
    {
        if (array.size() == 0)
        {
            cout << "My Bag is Empty." << endl;
            return;
        }
        cout << endl << "The sorted array is: \n";

        sort(array.begin(), array.end());
        for (int i = 0; i < array.size(); i++)
            cout << "[" << i << "] - " << array[i] << '\n';
    }

    //Precondition: user input to clear the array
    //Postcondition: clears the array
    void clear()
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
//postcondition: displays menu for integer bag class
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

//precondition: none
//postcondition: chooses menu for integer bag class
void MyBagIntFunction()
{
    nonTemplateMyBag h;
    do
    {
        switch (nonTemplateMenuOption())
        {
        case 0: return; break;
        case 1: h.clear(); break;
        case 2: h.insert(); break;
        case 3: h.search(); break;
        case 4: h.removeElementAtValue(); break;
        case 5: h.sortArray(); break;
        case 6: h.display(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}
