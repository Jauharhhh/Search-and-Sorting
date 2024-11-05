#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struktur data untuk menyimpan NIM dan Nama
typedef struct {
    char nim[12];
    char nama[50];
} Mahasiswa;

// Fungsi untuk menukar dua elemen dalam array
void swap(Mahasiswa *a, Mahasiswa *b) {
    Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk mengacak elemen-elemen dalam array
void shuffle(Mahasiswa arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(&arr[i], &arr[j]);
    }
}

// Fungsi partisi untuk algoritma quicksort berdasarkan NIM
int partition(Mahasiswa arr[], int low, int high) {
    Mahasiswa pivot = arr[high];
    int i = low - 1;

    printf("\nPivot saat ini adalah NIM yang berakhir dengan %s\n", &pivot.nim[8]);

    int swapCount = 0; // Counter untuk contoh output pertukaran
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j].nim, pivot.nim) < 0) {
            i++;
            swap(&arr[i], &arr[j]);
            swapCount++;
            if (swapCount <= 2) { // Menampilkan maksimal 2 contoh alasan pertukaran
                printf("- Memindahkan NIM akhir %s ke depan karena lebih kecil dari pivot\n", &arr[i].nim[8]);
            }
        }
    }
    swap(&arr[i + 1], &arr[high]);
    printf("Menempatkan NIM akhir %s pada posisi yang sesuai\n", &arr[i + 1].nim[8]);
    return i + 1;
}

// Fungsi Quick Sort untuk mengurutkan berdasarkan NIM
void quickSort(Mahasiswa arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Fungsi untuk menampilkan array
void printArray(Mahasiswa arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s - %s\n", arr[i].nim, arr[i].nama);
    }
}


int main() {
    Mahasiswa arr[] = {
        {"24106050001", "Muh. Ariq Zuhdi"}, {"24106050002", "DIFLA NABARI AL-FAQIH"},
        {"24106050003", "Firja Al Ghifari"}, {"24106050004", "Neyla Azna Sabila"},
        {"24106050005", "Nurul Fatiha"}, {"24106050006", "Gahyaka Ararya Fairuz Rakha Febrila Putra"},
        {"24106050007", "Muhammad Fajri"}, {"24106050008", "Muhammad Nabeel Akhtar"},
        {"24106050009", "Khatimatul Husna"}, {"24106050010", "Hesti Febriyani"},
        {"24106050011", "Fariz Husain Albar"}, {"24106050012", "Deca Delia Putri"},
        {"24106050013", "Wildatul Rahmaniyah"}, {"24106050014", "Mia Amelia"},
        {"24106050015", "Zahrotul Ngaliyah"}, {"24106050016", "M.Dyo Nabel Kosya"},
        {"24106050017", "Younata Nur Rahman"}, {"24106050018", "Nur Hafidz Sodiq"},
        {"24106050019", "Faiz Satria Ahimsa"}, {"24106050020", "Fitri Laily Yuanisa"},
        {"24106050021", "Ridwan Sidiq"}, {"24106050022", "Abdur Rahman"},
        {"24106050023", "Raka Ramdhani"}, {"24106050024", "Yazid Nur Fauzi"},
        {"24106050025", "Dinda Mir'ati Hayatullatif"}, {"24106050026", "Reffi Rizqullah Imannurhaq"},
        {"24106050027", "Dina Nur Azizah"}, {"24106050028", "Rachman Aulia Daffa Trirayi"},
        {"24106050029", "Muhammad Afif Faizun"}, {"24106050030", "Hafizh Nurfitrian Syah"},
        {"24106050031", "Ahmad Na’im"}, {"24106050032", "Muhammad Akbar Suryawan"},
        {"24106050033", "Nabila Rasty Azzahra"}, {"24106050034", "Fajar Dwi Arwanto"},
        {"24106050035", "Muhamad Hafid Imam"}, {"24106050036", "Dafa Rahestian Almuzaki"},
        {"24106050037", "Rendy Maulana Nasrul Izza"}, {"24106050038", "Adheva Dwi Anugrah Kurniagus"},
        {"24106050039", "Hisyam Hibatulloh"}, {"24106050040", "Syaiful Amri"},
        {"24106050041", "Zikri Dzulfikar"}, {"24106050042", "Muhammad Fazlan Istanjung"},
        {"24106050043", "Muhammad Ridwan Kurniawan"}, {"24106050044", "Muhammad Azka Giovani"},
        {"24106050045", "Amirul Akhmad Hardiawan"}, {"24106050046", "Muhammad Naufal Daffa' Rusmanto"},
        {"24106050047", "Muhammad Faqih Fiddin"}, {"24106050048", "Maulana Zhafran Arya Samudra"},
        {"24106050049", "Muhamad Rhedy Kustanto"}, {"24106050050", "Ardito Sam Purusatama"},
        {"24106050051", "LM. Khalis Adhipramana"}, {"24106050052", "Angga Rifqi Eksayahya"},
        {"24106050053", "Muhammad Hafidz Ar Ras Yid Hutagalung"}, {"24106050054", "Ahmad Faiq Zada"},
        {"24106050055", "M. Didat Ramadhan"}, {"24106050056", "Fajar Nurshinta"},
        {"24106050057", "Varel Hamigan Adranasty"}, {"24106050058", "Mahardika Ahmad Abdurrahman"},
        {"24106050059", "Najib Rizqi Romadhon Ardafa"}, {"24106050060", "Fadil As Siddiq"},
        {"24106050061", "Adiba Maulidya Maharani"}, {"24106050062", "Imam Wahyudi"},
        {"24106050063", "Hanif Fathoni Abdurrahman"}, {"24106050064", "Rahardian Bekti Nugraha"},
        {"24106050065", "Muhammad Irsyad Imaduddin"}, {"24106050066", "Septian Zihan Saputra"},
        {"24106050067", "Maulana Ilham Hamdhallah"}, {"24106050068", "Fatih Abiyyi Arfat"},
        {"24106050069", "Fira Yuniar"}, {"24106050070", "Salman Alfarisi"},
        {"24106050071", "Muhammad Khuzaifah Ghazali"}, {"24106050072", "Muhammad Marsa Valentino Tektonico"},
        {"24106050073", "Haris Prasetyo"}, {"24106050074", "Hamdan Rahmadin Akbar"},
        {"24106050075", "Dika Rachman"}, {"24106050076", "Muhammad Azdi Al Afkar"},
        {"24106050077", "Muhammad Apzirza Rafi"}, {"24106050078", "Muhammad Ilham Hanafi"},
        {"24106050079", "Rifa Athallah Okky Putra"}, {"24106050080", "Nafi Ageng Dhiandra"},
        {"24106050081", "Moh. Miftahul Kholif"}, {"24106050082", "Muhammad Ridhwan Hadayana Malik"},
        {"24106050083", "Syauqi Amran"}, {"24106050084", "Ziad Uais Qorni"},
        {"24106050085", "Mochamad Dimas Saputro"}, {"24106050086", "Nayla Mafazah"},
        {"24106050087", "Hasban Shamdanie Rahman"}, {"24106050088", "Salahudin"},
        {"24106050089", "Regan Gibran N"}, {"24106050090", "Jauhar Habib"},
        {"24106050091", "Feri Sarono"}, {"24106050092", "Raisya Dwi Novadenia Putri"},
        {"24106050093", "Rafli Haikal Akbar"}
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    // Mengacak array
    shuffle(arr, n);

    // Tampilkan array yang sudah diacak
    printf("\n\n");
    printf("<<<<<----- Data yang Mahasiswa yang telah mengisi Form ----->>>>>\n\n");
    printf("Array yang berisi data yang belum terurut:\n");
    printArray(arr, n);

    // Mengurutkan array menggunakan quicksort
    printf("\nProses pengurutan:\n");
    quickSort(arr, 0, n - 1);

    // Tampilkan hasil akhir
    printf("\nArray setelah diurutkan:\n");
    printArray(arr, n);

    return 0;
}