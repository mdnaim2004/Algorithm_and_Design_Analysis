#include <bits/stdc++.h>
using namespace std;

int partitionLomuto(vector<int>& a, int low, int high) {
    int pivot = a[high];          // last element pivot
    int i = low - 1;              // boundary of smaller elements

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;                 // pivot final position
}

void quickSort(vector<int>& a, int low, int high) {
    if (low < high) {
        int p = partitionLomuto(a, low, high);
        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}