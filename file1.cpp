#include <iostream>

using namespace std;

int main() {
    int N, K;
    cout << "Masukkan jumlah astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai K awal: ";
    cin >> K;

    int astronot[1000];
    for (int i = 0; i < N; i++) {
        astronot[i] = i + 1;
    }

    int jumlah_tersisa = N;
    int index = 0;

    cout << "\n--- HASIL SELEKSI ---" << endl;
    cout << "Urutan astronot yang dieliminasi: ";

    while (jumlah_tersisa > 1) {
        int index_eliminasi = (index + K - 1) % jumlah_tersisa;
        int tereliminasi = astronot[index_eliminasi];

        cout << tereliminasi << " ";

        
        for (int i = index_eliminasi; i < jumlah_tersisa - 1; i++) {
            astronot[i] = astronot[i + 1];
        }
        jumlah_tersisa--;

        
        if (tereliminasi % 2 == 0) {
            K += 2;
        } else {
            K -= 1;
        }

        if (K < 2) {
            K = 2;
        }

        index = index_eliminasi;
    }

    cout << "\nAstronot terakhir yang bertahan: Astronot Nomor " << astronot[0] << endl;

    return 0;
}