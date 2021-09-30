#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector <int> a[50000];
int n, r, used[1001];

void Spisuk_ot_Susedi() {

    int v1, v2;

    for (int i = 1; i <= n; i++) {
    }

    for (int i = 0; i < r; i++) {
        cin >> v1;
        cin >> v2;

        a[v1].push_back(v2);
        a[v2].push_back(v1);
    }
}


void dfs(int k)
{
    for (unsigned i = 0; i < a[k].size(); i++) {
        if (used[a[k][i]])
            continue;
        used[a[k][i]] = 1;
        dfs(a[k][i]);
    }
}


int main() {
    cout << "Enter the number of V: ";
    cin >> n;
    cout << "Enter the number of ribs: ";
    cin >> r;

    Spisuk_ot_Susedi();

    int x = 1;
    int count = 0;
    while (x <= n) {
        if (used[x]) {
            x++;
            continue;
        }
        dfs(x);
        count++;
        x++;

    }
    cout << count << endl;


    return 0;
}
