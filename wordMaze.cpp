#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct MyPointer {
    int row;
    int col;
};

int n;
int m;
bool** visited;
string word;
string* mazeMap;

bool wordMaze(int index, MyPointer mp)
{
    if (index == word.size()) {
        return true;
    } 
    
    stack<MyPointer> mps;
    // 依次上、右、下、左顺序，找下个字符
    if (mp.col - 1 >= 0 && !visited[mp.row][mp.col - 1] && mazeMap[mp.row][mp.col - 1] == word[index]) {
        mps.push(MyPointer{mp.row, mp.col - 1});
    }

    if (mp.row + 1 < n && !visited[mp.row + 1][mp.col] && mazeMap[mp.row + 1][mp.col] == word[index]) {
        mps.push(MyPointer{mp.row + 1, mp.col});
    }

    if (mp.col + 1 < m && !visited[mp.row][mp.col + 1] && mazeMap[mp.row][mp.col + 1] == word[index]) {
        mps.push(MyPointer{mp.row, mp.col + 1});
    }
    
    if (mp.row - 1 >= 0 && !visited[mp.row - 1][mp.col] && mazeMap[mp.row - 1][mp.col] == word[index]) {
        mps.push(MyPointer{mp.row - 1, mp.col});
    }

    while (!mps.empty()) {
        MyPointer next = mps.top();
        visited[next.row][next.col] = true;
        if (wordMaze(index + 1, next)) {
            return true;
        } else {
            visited[next.row][next.col] = false;
            mps.pop();
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    visited = new bool*[n];
    for (int i = 0; i < n; ++i) {
        visited[i] = new bool[m];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            visited[i][j] = false;
        }
    }
    
    cin >> word;
    
    mazeMap = new string[n];
    for (int i = 0; i < n; ++i) {
        cin >> mazeMap[i];
    }

    stack<MyPointer> firstWords;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mazeMap[i][j] == word[0]) {
                firstWords.push(MyPointer{i, j});
            }
        }
    }
    while (!firstWords.empty()) {
        MyPointer mp = firstWords.top();
        visited[mp.row][mp.col] = true;
        if (wordMaze(1, mp)) {
            cout << "YES" << endl;
            return 0;
        } else {
            visited[mp.row][mp.col] = false;
            firstWords.pop();
        }
    }
    cout << "NO" << endl;
    return 0;
}
