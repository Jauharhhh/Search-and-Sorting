#include <stdio.h>
#include <string.h>

#define MAX 94

typedef struct {
    char nim[20];
    char nama[50];
} Data;

int binarySearch(Data data[], int n, char *key) {
    int low = 0, high = n - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        printf("\n[INFO] Sedang memeriksa elemen di posisi tengah:");
        printf("\n   Rentang saat ini: Low = %d, Mid = %d, High = %d", low, mid, high);
        printf("\n   Data di tengah: NIM = %s, Nama = %s", data[mid].nim, data[mid].nama);
        
        // Mengambil dua digit terakhir dari NIM
        char lastTwoDigits[3];
        strncpy(lastTwoDigits, data[mid].nim + strlen(data[mid].nim) - 2, 2);
        lastTwoDigits[2] = '\0'; // Mengakhiri string

        printf("\n   Dua digit terakhir dari NIM: %s", lastTwoDigits);
        printf("\n   Kunci dicari: %s\n", key);

        if (strcmp(lastTwoDigits, key) == 0) {
            return mid; // Ditemukan
        } else if (strcmp(lastTwoDigits, key) < 0) {
            low = mid + 1; // Pindah ke sebelah kanan
            printf("\n   Karena %s < %s, pindah ke kanan (Low = %d)\n", lastTwoDigits, key, low);
        } else {
            high = mid - 1; // Pindah ke sebelah kiri
            printf("\n   Karena %s > %s, pindah ke kiri (High = %d)\n", lastTwoDigits, key, high);
        }
    }
    
    return -1; // Tidak ditemukan
}

int main() {
    Data data[MAX] = {
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

     int size = sizeof(data) / sizeof(data[0]);
printf("\n\n<<<<<<< -- PROGRAM PENCARIAN NAMA MAHASISWA BERDASAR NIM -- >>>>>>>\n\n");
    char key[3];
    
    printf("Masukkan 2 digit terakhir NIM: ");
    scanf("%s", key);

    int result = binarySearch(data, size, key);

    // Menampilkan hasil akhir
    if (result != -1) {
        printf("\n[[[---SUKSES---]]] Data dengan nim akhiran %s berupa : \n NIM = %s, Nama = %s\n", key , data[result].nim, data[result].nama);
    } else {
        printf("\n[[[---GAGAL---]]] Data tidak ditemukan.\n");
    }

    return 0;
}