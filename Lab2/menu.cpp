#include <limits>
#include "menu.h"
#define MAX_INT 1000
#define MIN_INT -1000
using namespace std;
void print_menu()
{
    cout << "--------------------------------" << endl;
    cout << "1.    Add in string in class    " << endl;
    cout << "2. Remove substring in class    " << endl;
    cout << "3. Find substring in class      " << endl;
    cout << "4. Get length of string in class" << endl;
    cout << "5. Get copy of string from class" << endl;
    cout << "6.            Exit              " << endl;
    cout << "--------------------------------" << endl;
    cout << "> ";
}

int get_variant()
{
    int var = 0;
    while(var < 1 || var > 6)
    {
        cout << "You write a wrong variant! Try again!" << endl;
        cin >> var;
    }
    return var;
}

bool checkingError(string s){
    int size = s.length();
    for(int i = 0; i != size; i++){
        if(s[i] >= '0' && s[i] <= '9')
            continue;
        else
            return true;

    }
    return false;
}
int goodIntInput(){
    string s;
    getline(cin, s);
    while(checkingError(s)){
        cout << "You input a wrong symbols! Try again" << endl;
        cin.clear();
        getline(cin, s);
    }

    return stoi(s);
}


void check_variant(int& var){
    if (var > 6 || var < 1){
        cout << "You wrote a wrong variant! Try again!" << endl;
        var = goodIntInput();

    }
}

void menu()
{
    int i1, i2 = 0;
    cout << "Input a string to create a class\n> ";
    string str;
    getline(cin, str);
    String p(data(str));
    print_menu();
    int variant = goodIntInput();
    check_variant(variant);
    do
    {
        switch (variant)
        {
            case 1:
                cout << "Input a string to add\n>";
                getline(cin, str);
                p.add(str);
                print_menu();
                variant = goodIntInput();
                check_variant(variant);
                break;
            case 2:
                cout << "Input indexes to remove\n>";
                cout << "i1: ";
                i1 = goodIntInput();
                cout << "i2: ";
                i2 = goodIntInput();
                p.remove(i1, i2);
                print_menu();
                variant = goodIntInput();
                check_variant(variant);
                break;
            case 3:
                cout << "Input a substring to find\n>";
                getline(cin, str);
                cout << "Your substring at " << p.find(str) << " index position" << endl;
                print_menu();
                variant = goodIntInput();
                check_variant(variant);
                break;
            case 4:
                cout << "Length of class String is " << p.getSize() << endl;
                print_menu();
                variant = goodIntInput();
                check_variant(variant);
                break;
            case 5:
                cout << p.getStr() << endl;
                print_menu();
                variant = goodIntInput();
                check_variant(variant);
                break;
            default:

                break;

        }

    }while(variant != 6);



}