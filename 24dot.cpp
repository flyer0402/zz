#include <stdio.h>
#include <vector>

using namespace std;
#define INPUT_CHAR_NUN 4
bool is24 = false;

bool CheckInputNum(int num)
{
    if (num < 1 || num > 13) {
        return false;
    } else {
        return true;
    }
}

int ConvertInt(char c)
{
    if (c == 'T') {
        return 10;
    }
    if (c == 'J') {
        return 11;
    }
    if (c == 'Q') {
        return 12;
    }
    if (c == 'K') {
        return 13;
    }
    if (c == 'A') {
        return 1;
    }
    return (c - '0');
}

vector<double> Calculate(double x, double y)
{
    vector<double> result;
    result.push_back(x + y);
    result.push_back(x > y ? (x - y) : (y - x));
    result.push_back(x * y);
    if (x != 0) {
        result.push_back(y / x);
    }
    if (y != 0) {
        result.push_back(x / y);
    }
    return result;
}

void Do24(vector<double> data)
{
    if (is24) {
        return;
    }
    if (data.size() == 2) {
        vector<double> result = Calculate(data[0], data[1]);
        for (auto iter = result.begin(); iter != result.end(); ++iter) {
            if (*iter > 23.999 && *iter < 24.001) {
                is24 = true;
                return;
            }
        }
    }
    for (auto i = data.begin(); i != data.end(); ++i) {
        for (auto j = i + 1; j != data.end(); ++j) {
            vector<double> tmp = Calculate(*i, *j);
            for (auto k : tmp) {
                vector<double> ttt;
                bool ii = true;
                bool jj = true;
                for (auto l : data) {
                    if (ii && l == *i) {
                        ii = false;
                        continue;
                    }
                    if (jj && l == *j) {
                        jj = false;
                        continue;
                    }
                    ttt.push_back(l);
                }
                ttt.push_back(k);
                Do24(ttt);
            }
        }
    }
}

int main(){
    char inputChar[INPUT_CHAR_NUN];
    int inputInt[INPUT_CHAR_NUN];
    vector<double> inputNums;
    while (scanf("%c %c %c %c", &inputChar[0], &inputChar[1], &inputChar[2], &inputChar[3]) != EOF) {
        getchar();
        is24 = false;
        for (int i = 0; i < INPUT_CHAR_NUN; ++i) {
            inputInt[i] = ConvertInt(inputChar[i]);
        }
        if (!CheckInputNum(inputInt[0]) || !CheckInputNum(inputInt[1]) ||
            !CheckInputNum(inputInt[2]) || !CheckInputNum(inputInt[3])){
            printf("%s\n", "No");
            return 0;
        }
        inputNums.clear();
        inputNums = {inputInt[0], inputInt[1], inputInt[2], inputInt[3]};
        Do24(inputNums);
        printf("%s\n", (is24) ? "Yes" : "No");
    }
    return 0;
}