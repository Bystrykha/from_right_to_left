#include <iostream>
#include <fstream>
#include <string>
#include <queue>

int numbers[3];

int numb_define(const std::string& dir){
    std::ifstream file(dir);
    std::string numb1, numb2, numb3;

    if(file.is_open()){
        file >> numb1 >> numb2 >> numb3;
        numbers[0] = atoi(numb1.c_str());
        numbers[1] = atoi(numb2.c_str());
        numbers[2] = atoi(numb3.c_str());
        return 1;
    }

    else{
        std::cout << "The file is not open.";
        return 0;
    }
}

int from_right_to_left(){
    int q = numbers[0], z, n = 0;
    std::queue <bool> bin_degree;
    for(int i = 0; numbers[1] != 0;){   //перевод в двоичную систему показателя степени
        i = numbers[1] % 2;
        if(i == 0){
            bin_degree.push(false);
        }
        else{
            bin_degree.push(true);
        }
        numbers[1] = numbers[1] / 2;
        n++;
    }

    if(!bin_degree.front()){
        z = 1;
    }
    else {
        z = numbers[0];
    }

    bin_degree.pop();
    for(int i = 1; i < n; i++){
        q = (q * q) % numbers[2];
        if(bin_degree.front()){
            z = (z * q) % numbers[2];
        }
        bin_degree.pop();
    }

    std::cout << z;
    return 1;
}


int main(){
    std::string directory = "C:\\Users\\Asus\\Desktop\\aaa.txt";
//    std::cin >> directory;
    int f_res = numb_define(directory);

    if(f_res == 1){
//        std::cout << numbers[0] << numbers[1] << numbers[2];
        for(int number : numbers) {
            if (number < 0) {
                std::cout << "One of numbers is negative.";
                return 0;
            }
        }
        int a = from_right_to_left();
        return a;
    }

    else{
        return 0;
    }
}
