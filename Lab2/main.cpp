#include "menu.h"
#include "String.h"
int main() {
    String p("hello world");
    String b( " world");
    p += b;
    String c = p + b;
    c.add("Ruslan");
    cout << c << endl;

//    menu();
    return 0;
}