#include "menu.h"
#include "String.h"
int main() {
    String p("hello world");
    String b( " world");
    p += b;
    String c = p + b;
    c.add("Ruslan");
    cout << (p != b) << endl;

//    menu();
    return 0;
}