
#ifndef LAB7_TEXTNOTE_H
#define LAB7_TEXTNOTE_H
#include "itextnote.h"

class TextNote : public ITextNote {
public:
    explicit TextNote(std::string pathToFile);

    void RewriteFile(int width) override;

    friend std::ostream& operator<<(std::ostream& out, const TextNote& note);

private:
    std::vector<std::string> splitText(const std::string& text, int width) override;

    void deleteTextFromFile (std::fstream& file, const std::string& name_of_file) override;

    std::string getTextFromFile(std::fstream& file, const std::string& name_of_file) override;

    void writeLinesInFile (std::fstream& file, const std::string& name_of_file, const std::vector<std::string>& lines) override;


};


#endif //LAB7_TEXTNOTE_H
