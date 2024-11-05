#include <stdio.h>

// Fungsi untuk melakukan insertion sort dan menampilkan setiap langkah pengurutan
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Geser elemen-elemen yang lebih besar dari key ke satu posisi di depan posisi saat ini
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // Tampilkan array setelah setiap langkah penyisipan
        printf("Langkah %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

// Fungsi untuk mencetak array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Meminta pengguna memasukkan jumlah elemen
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    int arr[n];

    // Meminta pengguna memasukkan elemen-elemen array
    printf("Masukkan %d elemen:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemen %d: ", i + 1);
        scanf("%d", &arr[i]);
    }   

    // Menampilkan array sebelum diurutkan
    printf("Array sebelum diurutkan: ");
    printArray(arr, n);

    // Melakukan pengurutan dengan Insertion Sort dan menampilkan setiap langkah
    insertionSort(arr, n);

    // Menampilkan array setelah diurutkan
    printf("Array setelah diurutkan: ");
    printArray(arr, n);

    return 0;
}
