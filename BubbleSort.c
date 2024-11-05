#include <stdio.h>

// Fungsi untuk melakukan bubble sort dan menampilkan proses pengurutan
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("Langkah %d:\n", i + 1);
        int swapped = 0; // Variabel untuk mengecek apakah ada pertukaran

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Tukar elemen jika elemen saat ini lebih besar dari elemen berikutnya
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set swapped menjadi 1 jika ada pertukaran
            }
            // Tampilkan array setelah setiap perbandingan
            for (int k = 0; k < n; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }

        // Jika tidak ada elemen yang ditukar, hentikan loop
        if (swapped == 0) {
            break;
        }
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

    // Melakukan pengurutan dengan Bubble Sort dan menampilkan setiap langkah
    bubbleSort(arr, n);

    // Menampilkan array setelah diurutkan
    printf("Array setelah diurutkan: ");
    printArray(arr, n);

    return 0;
}
