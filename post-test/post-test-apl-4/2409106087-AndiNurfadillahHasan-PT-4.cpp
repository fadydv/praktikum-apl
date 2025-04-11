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

Sistem sistem = { {}, {"Andi Nurfadillah Hasan", "2409106087"}, 0 };

int totalStok(int index) {
    if (index == sistem.jumlahLilin) return 0;
    return stoi(sistem.lilin[index].stok) + totalStok(index + 1);
}

void ucapan() {
    cout << "Terima kasih telah menggunakan sistem ini!\n";
}
void ucapan(string nama) {
    cout << "Terima kasih, " << nama << ", telah menggunakan sistem ini!\n";
}

void tambahLilin(Sistem &s) {
    if (s.jumlahLilin < MAX_LILIN) {
        cout << "Masukkan nama lilin: ";
        getline(cin, s.lilin[s.jumlahLilin].nama);
        cout << "Masukkan harga lilin (Rp): ";
        getline(cin, s.lilin[s.jumlahLilin].harga);
        cout << "Masukkan stok lilin (pcs): ";
        getline(cin, s.lilin[s.jumlahLilin].stok);
        s.jumlahLilin++;
        cout << "Data berhasil ditambahkan!\n";
    } else {
        cout << "Kapasitas penuh!\n";
    }
}

void lihatLilin(const Sistem &s) {
    if (s.jumlahLilin == 0) {
        cout << "Belum ada data lilin.\n";
    } else {
        cout << "\n+================================================================+\n";
        cout << "| No  | Nama Lilin          | Harga (Rp)   | Stok (pcs) |\n";
        cout << "+================================================================+\n";
        for (int i = 0; i < s.jumlahLilin; i++) {
            cout << "| " << setw(3) << left << i + 1 << " | "
                 << setw(20) << left << s.lilin[i].nama << " | "
                 << setw(12) << right << s.lilin[i].harga << " | "
                 << setw(10) << right << s.lilin[i].stok << " |\n";
        }
        cout << "+================================================================+\n";
    }
}

void perbaruiLilin(Sistem &s, int index) {
    if (index >= 0 && index < s.jumlahLilin) {
        cout << "Masukkan harga baru lilin (Rp): ";
        getline(cin, s.lilin[index].harga);
        cout << "Masukkan stok baru lilin (pcs): ";
        getline(cin, s.lilin[index].stok);
        cout << "Data berhasil diperbarui!\n";
    } else {
        cout << "Nomor lilin tidak valid.\n";
    }
}

void hapusLilin(Sistem &s, int index) {
    if (index >= 0 && index < s.jumlahLilin) {
        for (int i = index; i < s.jumlahLilin - 1; i++) {
            s.lilin[i] = s.lilin[i + 1];
        }
        s.jumlahLilin--;
        cout << "Data berhasil dihapus!\n";
    } else {
        cout << "Nomor lilin tidak valid.\n";
    }
}

int main() {
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
        cout << "1. Tambah Lilin\n2. Lihat Data Lilin\n3. Perbarui Data Lilin\n4. Hapus Data Lilin\n5. Total Stok Lilin\n6. Keluar\n";
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tambahLilin(sistem);
        } else if (pilihan == 2) {
            lihatLilin(sistem);
        } else if (pilihan == 3) {
            int indeks;
            cout << "Masukkan nomor lilin: ";
            cin >> indeks;
            cin.ignore();
            perbaruiLilin(sistem, indeks - 1);
        } else if (pilihan == 4) {
            int indeks;
            cout << "Masukkan nomor lilin: ";
            cin >> indeks;
            cin.ignore();
            hapusLilin(sistem, indeks - 1);
        } else if (pilihan == 5) {
            int total = totalStok(0);
            cout << "Total seluruh stok lilin: " << total << " pcs\n";
        } else if (pilihan == 6) {
            ucapan(nama);
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}