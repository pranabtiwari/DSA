#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Bubble Sort
void Bubblesorting(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
    }
}

// Insertion Sort
void insertionsort(int A[], int n) {
    for (int i = 1; i < n; i++) {
        int x = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > x) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

// Selection Sort
void selectionsort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[k]) {
                k = j;
            }
        }
        swap(&A[i], &A[k]);
    }
}

// Quick Sort
int partition(int A[], int l, int h) {
    int pivot = A[l];
    int i = l + 1;
    int j = h;

    while (true) {
        while (i <= h && A[i] <= pivot) i++;
        while (j > l && A[j] > pivot) j--;

        if (i >= j) break;
        swap(&A[i], &A[j]);
    }
    swap(&A[l], &A[j]);
    return j;
}

void Quicksort(int A[], int l, int h) {
    if (l < h) {
        int j = partition(A, l, h);
        Quicksort(A, l, j - 1);
        Quicksort(A, j + 1, h);
    }
}

// Merge Sort
void mergesort(int A[], int B[], int n, int m) {
    int c[n + m];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (A[i] < B[j]) {
            c[k++] = A[i++];
        } else {
            c[k++] = B[j++];
        }
    }
    while (i < n) c[k++] = A[i++];
    while (j < m) c[k++] = B[j++];

    for (i = 0; i < n + m; i++) {
        cout << c[i] << " ";
    }
    cout << endl;
}

// Count Sort
int maxelement(int A[], int n) {
    int max = A[0];
    int i = 1;

    while (i < n) {
        if (A[i] > max) {
            max = A[i];
        }
        i++;
    }
    return max;
}

void countsort(int A[], int n) {
    int max = maxelement(A, n);
    int *c = new int[max + 1];

    int i = 0;
    while (i <= max) {
        c[i] = 0;
        i++;
    }

    i = 0;
    while (i < n) {
        c[A[i]]++;
        i++;
    }

    i = 0;
    int j = 0;
    while (i <= max) {
        while (c[i] > 0) {
            A[j++] = i;
            c[i]--;
        }
        i++;
    }

    delete[] c;
}

int main() {
    int A[] = {50, 30, 30, 34, 60, 90};
    int B[] = {10, 20, 30, 40, 80};
    int n = sizeof(A) / sizeof(A[0]);
    int m = sizeof(B) / sizeof(B[0]);

    // mergesort(A, B, n, m);
    countsort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
