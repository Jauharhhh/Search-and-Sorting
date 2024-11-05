#include <stdio.h>

int main() {
    int arr[10];       // Array untuk menyimpan 10 elemen
    int i, target;     // Variabel untuk pencarian dan perulangan
    int found = 0;     // Flag untuk menandai apakah elemen ditemukan
    
    // Meminta user untuk memasukkan 10 elemen ke dalam array
    printf("Masukkan 10 elemen array:\n");
    for(i = 0; i < 10; i++) {
        printf("Elemen ke-%d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    // Meminta user untuk memasukkan elemen yang ingin dicari
    printf("Masukkan elemen yang ingin dicari: ");
    scanf("%d", &target);

    printf("\nProses Pencarian:\n");
    // Proses pencarian linear search
    for(i = 0; i < 10; i++) {
        printf("Memeriksa elemen pada indeks %d: %d", i, arr[i]);
        
        // Mengecek apakah elemen pada indeks saat ini adalah target
        if(arr[i] == target) {
            printf(" --> Elemen ditemukan! (%d == %d)\n", arr[i], target);
            printf("Elemen %d ditemukan pada indeks %d.\n", target, i);
            found = 1; // Menandai bahwa elemen telah ditemukan
            break;
        } else {
            printf(" --> Bukan elemen yang dicari (%d != %d)\n", arr[i], target);
        }
    }

    // Jika elemen tidak ditemukan
    if(!found) {
        printf("Elemen %d tidak ditemukan dalam array.\n", target);
    }

    return 0;
}
