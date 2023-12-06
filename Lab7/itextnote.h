
#ifndef LAB7_ITEXTNOTE_H
#define LAB7_ITEXTNOTE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include <vector>
#include <cctype>

class ITextNote {
public:
    explicit ITextNote(std::string  path_to_file)
    : path_to_file(std::move(path_to_file))
    {}

    virtual void RewriteFile(int width) = 0;


protected:
    bool isPunctuation(char c) { return std::ispunct(static_cast<unsigned char>(c)); }

    virtual std::vector<std::string> splitText(const std::string& text, int width) = 0;

    virtual void deleteTextFromFile (std::fstream& file, const std::string& name_of_file) = 0;

    virtual std::string getTextFromFile(std::fstream& file, const std::string& name_of_file) = 0;

    virtual void writeLinesInFile (std::fstream& file, const std::string& name_of_file, const std::vector<std::string>& lines) = 0;

protected:
    std::vector<std::string> lines;
    std::string raw_text;
    std::string path_to_file;
    std::fstream file;
};


#endif //LAB7_ITEXTNOTE_H
