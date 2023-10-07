#ifndef LAB2_STRING_H
#define LAB2_STRING_H

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
    explicit String(char* str);
    ~String();
    unsigned int find(const string& str);
    void add(const string& str);
    void remove(int a, int b);
    [[nodiscard]] unsigned int getSize () const;
    [[nodiscard]] string getStr () const;
    friend ostream& operator << (ostream & out, const String & str);
    String &operator-=(String const & a);
    String &operator+=(String const & a);
    String operator -(String const & a);
    String operator +(String const & a);
    friend bool operator==(const String &c1, const String &c2);
    friend bool operator!=(const String &c1, const String &c2);
    friend bool operator>=(const String &c1, const String &c2);
    friend bool operator<=(const String &c1, const String &c2);
    friend bool operator>(const String &c1, const String &c2);
    friend bool operator<(const String &c1, const String &c2);



private:
    void swap(String & a);


};


#endif //LAB2_STRING_H
