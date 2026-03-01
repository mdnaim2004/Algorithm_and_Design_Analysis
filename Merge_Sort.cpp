#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& a, int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) L[i] = a[l + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    // ধরে নাও:
    // arr = main array
    // L = left sorted part (size n1)
    // R = right sorted part (size n2)
    // l = arr তে শুরু index (যেখান থেকে বসানো শুরু হবে)

    int i = 0;      // L array এর index
    int j = 0;      // R array এর index
    int k = l;      // main array a তে বসানোর index

    // ১) যতক্ষণ দুই পাশে (L এবং R) element আছে, compare করে ছোটটা a তে বসাও
    while (i < n1 && j < n2) {
        // L[i] এবং R[j] compare করা হচ্ছে
        if (L[i] <= R[j]) {
            // a[k] তে L[i] বসানো হচ্ছে
            a[k] = L[i];
            // এরপর যেহেতু L[i] ব্যবহার হয়ে গেছে, তাই L এর index বাড়াও
            i = i + 1;
            // a তে এক ঘর পূরণ হয়েছে, তাই main index k বাড়াও
            k = k + 1;
        }
        else {
            // a[k] তে R[j] বসানো হচ্ছে
            a[k] = R[j];
            // এরপর যেহেতু R[j] ব্যবহার হয়ে গেছে, তাই R এর index বাড়াও
            j = j + 1;
            // a তে এক ঘর পূরণ হয়েছে, তাই main index k বাড়াও
            k = k + 1;
        }
    }

    // ২) যদি L তে এখনো কিছু element বাকি থাকে, সেগুলো a তে copy করো
    while (i < n1) {
        a[k] = L[i];
        i = i + 1;
        k = k + 1;
    }

    // ৩) যদি R তে এখনো কিছু element বাকি থাকে, সেগুলো a তে copy করো
    while (j < n2) {
        a[k] = R[j];
        j = j + 1;
        k = k + 1;
    }
}

void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    mergeArrays(a, l, mid, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}