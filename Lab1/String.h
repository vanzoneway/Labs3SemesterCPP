//
// Created by PC on 10.09.2023.
//

#ifndef LAB1_STRING_H
#define LAB1_STRING_H

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

class String {
private:
    unsigned int size_;
    string str_;
public:
    String(String const & a);
    String & operator=(String const & a);
    String(char* str);
    ~String();
    unsigned int find(const string& str);
    void add(const string& str);
    void remove(int a, int b);
    unsigned int getSize () const;
    string getStr () const;

private:
    void swap(String & a);


};


#endif //LAB1_STRING_H
