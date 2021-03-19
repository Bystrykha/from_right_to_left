#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <regex>

int numbers[3];
std::string one_str_from_file;
std::regex pattern_str("[0-9]+ [0-9]+ [1-9][0-9]+");
std::regex pattern_word("[0-9]+");
unsigned long long q, z;
int n = 0, m;

void from_right_to_left(){
    q = numbers[0];
    m = numbers[2];
    std::queue <bool> bin_degree;
    for(int i = 0; numbers[1] != 0;){   //перевод в двоичную систему показателя степени
        i = numbers[1] % 2;
        if(i == 0) bin_degree.push(false);
        else bin_degree.push(true);
        numbers[1] = numbers[1] / 2;
        n++;
    }
    if(!bin_degree.front()) z = 1; // начальное значение z
    else z = numbers[0];

    bin_degree.pop();   // убираем апервый элемент

    for(int i = 1; i < n; i++){     // алгоритм справа на лево
        q = (q * q) % m;
        if(bin_degree.front()) z = (z * q) % m;
        bin_degree.pop();
    }
    std::ofstream out;
    out.open("output.txt", std::ios::app);
    out << z << "\n";
    z = 0;
    q = 0;
    m = 0;
    n = 0;
}

int numb_define(const std::string& dir){
    std::ifstream file;
    file.open(dir);
    if(file.is_open()){
        while(getline(file, one_str_from_file)) {       //считывание из файла
            if (std::regex_match(one_str_from_file, pattern_str)) {     // сравнение с регулярным выражением
                for (int i = 0, j = 0; j < one_str_from_file.length(); j++) {     // разбиение валидной строки на числа
                    if (one_str_from_file[j] >= '0' && one_str_from_file[j] <= '9') {
                        numbers[i] = numbers[i] * 10 + (one_str_from_file[j] - 48);
                    }
                    else i++;
                }
                from_right_to_left();   // подсчет справа на лево
            }
            memset(numbers, 0, sizeof(int) * 3);    // обнуление массива
        }
    }
    else return 0;
    return 1;
}

int main(){
    std::string directory = "input.txt";
    int res = numb_define(directory);
    return res;
}
