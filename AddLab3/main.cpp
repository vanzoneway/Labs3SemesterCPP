#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> array_of_words(const std::string& line )
{
    std::vector<std::string> vectstr;
    std::stringstream s(line);
    std::string word;
    while ( s >> word ) vectstr.push_back(word);
    return vectstr;

}

char** create_matrix(int N, int M){
    char** matrix = new char*[N];
    matrix[0] = new char[N * M];
    for(int i = 1; i != N; i++)
    {
        matrix[i] = matrix[i-1] + M;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            matrix[i][j] = '*';
        }
    }
    return matrix;
}

template <typename T>
void print_matrix(T** matrix, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void encrypt_word(std::string & str, const int& key) {
    int size_of_word = static_cast<int>(str.size());
    char **matrix = create_matrix(key, size_of_word);
    bool flag = false;
    int rows = 0, cols = 0;
    for (int i = 0; i < size_of_word; i++) {
        if (rows == 0 || rows == key - 1)
            flag = !flag;
        matrix[rows][cols++] = str[i];
        flag ? rows++ : rows--;
    }
    str.clear();
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < size_of_word; j++) {
            if (matrix[i][j] != '*')
                str.push_back(matrix[i][j]);

        }
    }
    print_matrix(matrix, key, size_of_word);
    delete [] matrix[0];
    delete [] matrix;
}

void decrypt_word(std::string & str, const int& key) {
    int size_of_word = static_cast<int>(str.size());
    char **matrix = create_matrix(key, size_of_word);
    bool flag = false;
    int rows = 0, cols = 0;
    for (int i = 0; i < size_of_word; i++) {
        if (rows == 0 || rows == key - 1)
            flag = !flag;
        matrix[rows][cols++] = '`';
        flag ? rows++ : rows--;
    }

    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<size_of_word; j++)
            if (matrix[i][j] == '`' && index < size_of_word)
                matrix[i][j] = str[index++];
    str.clear();
    flag = false;
    rows = 0, cols = 0;
    for (int i = 0; i < size_of_word; i++) {
        if (rows == 0 || rows == key - 1)
            flag = !flag;
        if(matrix[rows][cols] != '*')
            str.push_back(matrix[rows][cols++]);
        flag ? rows++ : rows--;
    }
//    delete [] matrix[0];
//    delete [] matrix;
}



int main() {

    std::string str = "Eye for eye my friend dear";
    int key = 4;
    encrypt_word(str, key);
    std::cout << str << std::endl;
    decrypt_word(str, key);
    std::cout << str << std::endl;





    return 0;
}
