//
// Created by PC on 04.12.2023.
//

#include "textnote.h"

#include <utility>

TextNote::TextNote(std::string pathToFile)
: ITextNote(std::move(pathToFile))
{

}

std::vector<std::string> TextNote::splitText(const std::string &text, int width) {
    std::string word;
    std::string line;
    std::vector<std::string> lines;
    std::istringstream iss(text);
    while(iss >> word)
    {
        if(line.length() + word.length() + 1 <= width)
        {
            if(!line.empty())
                line += " ";
            line += word;
        }
        else
        {
            if(!line.empty() && !isPunctuation(line.back()))
            {
                lines.push_back(line);
                line.clear();
                continue;
            }
            lines.push_back(line);
            line = word;
        }

    }
    lines.push_back(line);
    return lines;
}

void TextNote::deleteTextFromFile(std::fstream &file, const std::string &name_of_file) {
    file.open(name_of_file, std::ios::trunc);
    if(!file.is_open())
    {
        std::cout << "Cannot open file!" << std::endl;
        std::cin.get();
        exit(0);
    }
    file.close();
}

std::string TextNote::getTextFromFile(std::fstream &file, const std::string &name_of_file) {
    file.open(name_of_file, std::ios::in);
    if(!file.is_open()) {
        std::cout << "Cannot open file!" << std::endl;
        std::cin.get();
        exit(0);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void
TextNote::writeLinesInFile(std::fstream &file, const std::string &name_of_file, const std::vector<std::string> &lines) {
    file.open(name_of_file, std::ios::out);
    if(!file.is_open())
    {
        std::cout << "Cannot open file!" << std::endl;
        std::cin.get();
        exit(0);
    }
    for(const std::string& line : lines)
    {
        file << line << "\n";
    }
}

void TextNote::RewriteFile(int width) {
    raw_text = getTextFromFile(file, path_to_file);
    lines = splitText(raw_text, width);
    deleteTextFromFile(file, path_to_file);
    writeLinesInFile(file, path_to_file, lines);
}

std::ostream &operator<<(std::ostream &out, const TextNote &note) {
    for(const std::string& line : note.lines)
        out << line << "\n";
    return out;
}

