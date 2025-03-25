#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_LILIN 100

struct Lilin {
    string nama;
    string harga;
    string stok;
};

struct Admin {
    string username;
    string password;
};

struct Sistem {
    Lilin lilin[MAX_LILIN];
    Admin admin;
    int jumlahLilin;
};

Sistem sistem;

int main() {
    sistem.jumlahLilin = 0;
    sistem.admin = {"Andi Nurfadillah Hasan", "2409106087"};

    string nama, nim;
    int percobaan = 3;

    while (percobaan > 0) {
        cout << "\n===== LOGIN ADMIN =====" << endl;
        cout << "Masukkan Nama: ";
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        getline(cin, nim);
        
        if (sistem.admin.username == nama && sistem.admin.password == nim) {
            cout << "Login berhasil!\n";
            break;
        } else {
            percobaan--;
            cout << "Login gagal! Sisa percobaan: " << percobaan << "\n";
        }
    }

    if (percobaan == 0) {
        cout << "Anda telah gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    while (true) {
        cout << "\n===== Sistem Manajemen Penjualan Lilin Aromaterapi =====" << endl;
        cout << "1. Tambah Lilin" << endl;
        cout << "2. Lihat Data Lilin" << endl;
        cout << "3. Perbarui Data Lilin" << endl;
        cout << "4. Hapus Data Lilin" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            if (sistem.jumlahLilin < MAX_LILIN) {
                cout << "Masukkan nama lilin: ";
                getline(cin, sistem.lilin[sistem.jumlahLilin].nama);
                cout << "Masukkan harga lilin (Rp): ";
                getline(cin, sistem.lilin[sistem.jumlahLilin].harga);
                cout << "Masukkan stok lilin (pcs): ";
                getline(cin, sistem.lilin[sistem.jumlahLilin].stok);
                sistem.jumlahLilin++;
                cout << "Data berhasil ditambahkan!\n";
            } else {
                cout << "Kapasitas penuh! Tidak bisa menambah lilin lagi.\n";
            }
        } else if (pilihan == 2) {
            if (sistem.jumlahLilin == 0) {
                cout << "Belum ada data lilin.\n";
            } else {
                cout << "\n+================================================================+\n";
                cout << "| No  | Nama Lilin          | Harga (Rp)   | Stok (pcs) |\n";
                cout << "+================================================================+\n";
                for (int i = 0; i < sistem.jumlahLilin; i++) {
                    cout << "| " << setw(3) << left << i + 1 << " | "
                         << setw(20) << left << sistem.lilin[i].nama << " | "
                         << setw(12) << right << sistem.lilin[i].harga << " | "
                         << setw(10) << right << sistem.lilin[i].stok << " |\n";
                }
                cout << "+================================================================+\n";
            }
        } else if (pilihan == 3) {
            if (sistem.jumlahLilin == 0) {
                cout << "Belum ada data lilin.\n";
                continue;
            }
            cout << "Masukkan nomor lilin yang ingin diperbarui: ";
            int indeks;
            cin >> indeks;
            cin.ignore();
            
            if (indeks > 0 && indeks <= sistem.jumlahLilin) {
                cout << "Masukkan harga baru lilin (Rp): ";
                getline(cin, sistem.lilin[indeks - 1].harga);
                cout << "Masukkan stok baru lilin (pcs): ";
                getline(cin, sistem.lilin[indeks - 1].stok);
                cout << "Data berhasil diperbarui!\n";
            } else {
                cout << "Nomor lilin tidak valid.\n";
            }
        } else if (pilihan == 4) {
            if (sistem.jumlahLilin == 0) {
                cout << "Belum ada data lilin.\n";
                continue;
            }
            cout << "Masukkan nomor lilin yang ingin dihapus: ";
            int indeks;
            cin >> indeks;
            
            if (indeks > 0 && indeks <= sistem.jumlahLilin) {
                for (int i = indeks - 1; i < sistem.jumlahLilin - 1; i++) {
                    sistem.lilin[i] = sistem.lilin[i + 1];
                }
                sistem.jumlahLilin--;
                cout << "Data berhasil dihapus!\n";
            } else {
                cout << "Nomor lilin tidak valid.\n";
            }
        } else if (pilihan == 5) {
            cout << "Terima kasih! Program berhenti.\n";
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }
    return 0;
}