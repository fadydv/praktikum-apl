#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_LILIN 100

string lilin[MAX_LILIN][3];
int jumlahLilin = 0;

int tampilkanData() {
    if (jumlahLilin == 0) {
        cout << "\nBelum ada data lilin.\n";
        return 0;
    }

    cout << "\nData Lilin Aromaterapi:\n";
    cout << "=====================================================\n";
    cout << setw(5) << left << "No" 
         << setw(20) << left << "Nama Lilin"
         << setw(15) << left << "Harga"
         << setw(10) << left << "Stok" << endl;
    cout << "=====================================================\n";

    for (int i = 0; i < jumlahLilin; i++) {
        cout << setw(5) << left << i + 1
             << setw(20) << left << lilin[i][0]
             << setw(15) << left << lilin[i][1]
             << setw(10) << left << lilin[i][2] << endl;
    }

    cout << "=====================================================\n";
    return 1;
}

int tambahLilin() {
    if (jumlahLilin < MAX_LILIN) {
        cout << "Masukkan nama lilin: ";
        cin.ignore();
        getline(cin, lilin[jumlahLilin][0]);
        cout << "Masukkan harga lilin: ";
        getline(cin, lilin[jumlahLilin][1]);
        cout << "Masukkan stok lilin: ";
        getline(cin, lilin[jumlahLilin][2]);
        jumlahLilin++;
        cout << "Data berhasil ditambahkan!\n";
        return 1;
    } else {
        cout << "Kapasitas penuh! Tidak bisa menambah lilin lagi.\n";
        return 0;
    }
}

int updateLilin() {
    if (tampilkanData() == 0) return 0;

    int indeks;
    cout << "Masukkan nomor lilin yang ingin diperbarui: ";
    cin >> indeks;
    cin.ignore();

    if (indeks > 0 && indeks <= jumlahLilin) {
        cout << "Masukkan nama baru lilin: ";
        getline(cin, lilin[indeks - 1][0]);
        cout << "Masukkan harga baru lilin: ";
        getline(cin, lilin[indeks - 1][1]);
        cout << "Masukkan stok baru lilin: ";
        getline(cin, lilin[indeks - 1][2]);
        cout << "Data berhasil diperbarui!\n";
        return 1;
    } else {
        cout << "Nomor lilin tidak valid.\n";
        return 0;
    }
}

int hapusLilin() {
    if (tampilkanData() == 0) return 0;

    int indeks;
    cout << "Masukkan nomor lilin yang ingin dihapus: ";
    cin >> indeks;

    if (indeks > 0 && indeks <= jumlahLilin) {
        for (int i = indeks - 1; i < jumlahLilin - 1; i++) {
            lilin[i][0] = lilin[i + 1][0];
            lilin[i][1] = lilin[i + 1][1];
            lilin[i][2] = lilin[i + 1][2];
        }
        jumlahLilin--;
        cout << "Data berhasil dihapus!\n";
        return 1;
    } else {
        cout << "Nomor lilin tidak valid.\n";
        return 0;
    }
}

int main() {
    string nama, nim;
    int percobaan = 3;

    while (percobaan > 0) {
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);

        if (nama == "Andi Nurfadillah Hasan" && nim == "2409106087") {
            cout << "Login berhasil!\n";
            break;
        } else {
            percobaan--;
            cout << "Login gagal! Sisa percobaan: " << percobaan << endl;
        }
    }

    if (percobaan == 0) {
        cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Tambah Lilin\n";
        cout << "2. Lihat Data Lilin\n";
        cout << "3. Perbarui Data Lilin\n";
        cout << "4. Hapus Data Lilin\n";
        cout << "5. Keluar\n";
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tambahLilin();
        } else if (pilihan == 2) {
            tampilkanData();
        } else if (pilihan == 3) {
            updateLilin();
        } else if (pilihan == 4) {
            hapusLilin();
        } else if (pilihan == 5) {
            cout << "Terima kasih! Program berhenti.\n";
            return 0;
        } else {
            cout << "Pilihan tidak valid! Silakan pilih lagi.\n";
        }
    }

    return 0;
}