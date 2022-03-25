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




void TemplateMyBag()
{
    
   
 
    do
    {
        switch (TemplateClassMenuOption())
        {
        case 0: return; break;
             //  case 1: clear(); break;
             //  case 2:  insert(); break;
             //  case 3: search(); break;
             //  case 4: remove(); break;
             //  case 5: sortArray(); break;
              // case 6: display(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);

}
