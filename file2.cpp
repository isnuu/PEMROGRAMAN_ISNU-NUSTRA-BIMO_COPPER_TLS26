#include <iostream>

using namespace std;

int main() {
    char pesan_asli[100];
    cout << "Masukkan pesan asli (huruf kapital): ";
    cin >> pesan_asli;

    char pesan_sandi[100];
    
    // Huruf pertama tidak berubah
    pesan_sandi[0] = pesan_asli[0];

    int i = 1;
    while (pesan_asli[i] != '\0') {
        // Ambil nilai alfabet (A = 1, B = 2, ..., Z = 26)
        int nilai_sekarang = pesan_asli[i] - 'A' + 1;
        int nilai_sebelumnya = pesan_asli[i - 1] - 'A' + 1;

        // Hitung pergeseran
        int nilai_baru = nilai_sekarang + nilai_sebelumnya;

        // Jika melebihi 26, putar kembali ke A (1-26)
        int nilai_modulus = nilai_baru % 26;
        if (nilai_modulus == 0) {
            nilai_modulus = 26;
        }

        // Ubah kembali ke karakter huruf
        pesan_sandi[i] = (char)(nilai_modulus - 1 + 'A');
        i++;
    }
    
    // Penanda akhir string C++
    pesan_sandi[i] = '\0';

    cout << "Hasil pesan sandi: " << pesan_sandi << endl;

    return 0;
}