#include "hashtable.h"
#include <exception>



int main() {
    simple_map<std::string, std::string> my_map;
    simple_map<int, std::string> my_map2;
    my_map.addValue("mum", "Natalia");
    my_map.addValue("dad", "Vyacheslav");
    my_map.addValue("sister", "Marta");
    my_map.addValue("retsis", "Ilia");
    my_map.removeValue("sister");
    my_map.removeValue("retsis");

    try
    {

    }
    catch(std::logic_error& x)
    {

    }
    catch(...)
    {

    }

    my_map.print();

    return 0;
}
