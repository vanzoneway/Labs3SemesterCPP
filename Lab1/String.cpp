#include "String.h"

#include <utility>

String::String(char* str) : size_(strlen(str)), str_(str)
{}

String::~String()
{
    str_.clear();
}

unsigned int String::getSize() const { return size_; }

string String::getStr() const
{
    return str_ ;
}

void String::remove(int a, int b)
{
    str_.erase(a, b);
    size_ = str_.length();
}

void String::add(const string& str)
{
    str_.append(str);
    size_ = str_.length();
}

unsigned int String::find(const string& str)
{
    return str_.find(str);
}

String::String(String const & a) : size_(a.size_), str_(a.str_)
{}

void String::swap(String & a)
{
    std::swap(a.size_, this->size_);
    std::swap(a.str_, this->str_);

}
String &String::operator=(const String &a)
{
    if(this != &a){
        String(a).swap(*this);
    }
    return *this;
}









