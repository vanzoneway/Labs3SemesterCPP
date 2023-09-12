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

int checkingOneError(int error){
    if(error!=1){
        return error;
    }
    char temp = getchar();
    while(temp!='\n'){
        if (temp > '9' || temp < '0') {
            return -2;
        }
    }
    return 1;
}
int goodScanfInt(){
    int num = 0;
    rewind(stdin);
    while(checkingOneError(scanf("%d",&num))!=1){
        printf("You wrote an incorrect symbol. Try again!\n>");
        rewind(stdin);
    }
    return num;
}

void check_variant(int& var){
    if (var > 6 || var < 1){
        cout << "You wrote a wrong variant! Try again!" << endl;
        var = goodScanfInt();

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
    int variant = goodScanfInt();
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
                variant = goodScanfInt();
                check_variant(variant);
                break;
            case 2:
                cout << "Input indexes to remove\n>";
                cout << "i1: ";
                i1 = goodScanfInt();
                cout << "i2: ";
                i2 = goodScanfInt();
                p.remove(i1, i2);
                print_menu();
                variant = goodScanfInt();
                check_variant(variant);
                break;
            case 3:
                cout << "Input a substring to find\n>";
                getline(cin, str);
                cout << "Your substring at " << p.find(str) << " index position" << endl;
                print_menu();
                variant = goodScanfInt();
                check_variant(variant);
                break;
            case 4:
                cout << "Length of class String is " << p.getSize() << endl;
                print_menu();
                variant = goodScanfInt();
                check_variant(variant);
                break;
            case 5:
                cout << p.getStr() << endl;
                print_menu();
                variant = goodScanfInt();
                check_variant(variant);
                break;
            default:

                break;

        }

    }while(variant != 6);



}