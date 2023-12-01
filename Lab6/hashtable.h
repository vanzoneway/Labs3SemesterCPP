
#ifndef LAB6_HASHTABLE_H
#define LAB6_HASHTABLE_H

#include <iostream>
#include <list>
#include <exception>
template <class type_of_value, class type_of_key>
struct Item
{
    type_of_value value;
    type_of_key key;
};


template <class type_of_key, class type_of_value, int size_of_map = 100>
class simple_map_base
{
protected:
    virtual int hashing_func(const type_of_key& key) = 0;
    std::list<Item<type_of_value, type_of_key>> hash_table[size_of_map];


public:
    virtual ~simple_map_base() = default;
    void print()
    {

        for(int i = 0; i < size_of_map; i++)
        {
            std::list<Item<type_of_value, std::string>> tmp_list = this->hash_table[i];
            for(const Item<type_of_value, std::string>& j : tmp_list)
            {
                std::cout << j.key << "|" << j.value << " ";
            }
            std::cout << std::endl;
        }
    };
    type_of_value getValue(const type_of_key& key)
    {
        int i = hashing_func(key);
        std::list<Item<type_of_value, type_of_key>> tmp_list = hash_table[i];
        for(Item<type_of_value, type_of_key> j : tmp_list)
        {
            if(j.key == key)
                return j.value;
        }
    };
    void addValue(const type_of_key& key, const type_of_value& value){
        int i = hashing_func(key);
        Item<type_of_value, std::string> item;
        item.key = key;
        item.value = value;
        hash_table[i].push_back(item);
    };
    void removeValue(const type_of_key& key) {
        int i = hashing_func(key);
        std::list<Item<type_of_value, type_of_key>>* tmp_list = &hash_table[i];
        for(auto it = tmp_list->begin(); it != tmp_list->end();)
        {
            if(it->key == key){
                it = tmp_list->erase(it);
            }
            it++;
        }

    };


};

template <class type_of_key, class type_of_value, int size_of_map = 100>
class simple_map : public simple_map_base<type_of_key, type_of_value, size_of_map>
{
public:

};


template<class type_of_value, int size_of_map>
class simple_map<std::string, type_of_value, size_of_map> : public simple_map_base<std::string, type_of_value, size_of_map>
{
protected:
    int hashing_func(const std::string& key) override
    {
        if (size_of_map >= 1000){
            throw std::logic_error("Too big size_of_map");
        }
        int i = 0;
        for(char j : key)
            i += j;
        return i % size_of_map;
    }
public:
};

template<class type_of_value, int size_of_map>
class simple_map<int, type_of_value, size_of_map> : public simple_map_base<int, type_of_value, size_of_map>
{
protected:
    int hashing_func(const int& key) override
    {
        return key % size_of_map;
    }

public:

};


#endif //LAB6_HASHTABLE_H
