#include <iostream>
#include <string>

using namespace std;

int C;
string compressed;

int idx;

string reorder() {
    if (compressed[idx] == 'b' || compressed[idx] == 'w') {
        return string(1, compressed[idx++]);
    }
    idx++;
    string first = reorder();
    string second = reorder();
    string third = reorder();
    string fourth = reorder();
    return string("x") + third + fourth + first + second;
}


int main() {
    scanf("%d", &C);
    for (int i=0; i<C; i++) {
        idx = 0;
        cin >> compressed;
        string result = reorder();
        cout << result << endl;
    }
}

