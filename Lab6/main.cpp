#include <iostream>
#include "hashtable.h"



int main()
{
    using namespace std;
    simple_map<string, string> my_map;
    my_map.addValue("Mother", "Natasha");
    my_map.addValue("Father", "Andrey");
    my_map.addValue("Sister", "Masha");
    my_map.print();

    simple_map<string, list<int>> my_map2;


}