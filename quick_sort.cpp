#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;

int *generate_random_int(int n) {
    int *data = new int[n];

    for (int i = 0; i < n; i++) {
        data[i] = rand();
    }

    return data;
}

bool is_sorted(int *data, int n) {
    for (int i = 1; i < n; i++) {
        if (data[i - 1] > data[i]) {
            return false;
        }
    }
    return true;
}

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int num_of_experiments = 100;
    int *data;
    int n;

    // DEBUG
    // The program will stop if the sorting is incorrect n = 100;
    data = generate_random_int(n);
    quick_sort(data, 0, n - 1);
    if (!is_sorted(data, n)) {
        throw runtime_error("Sorting function ERROR.");
    }

    // EXPERIMENTS
    cout << "data, time (ms)\n"; 
    cout << "	\n";
    for (int i = 1; i <= num_of_experiments; i++) {
        n = i * 1000;
        data = generate_random_int(n);

        auto start = chrono::high_resolution_clock::now();
        quick_sort(data, 0, n - 1);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        cout << n << ", " << duration.count() << "\n";
        delete[] data;
    }

    return 0;
}