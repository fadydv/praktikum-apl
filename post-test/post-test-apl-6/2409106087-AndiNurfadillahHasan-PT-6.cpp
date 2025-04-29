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

Sistem sistem = {
    {
        {"Lavender Bliss", "35000", "12"},
        {"Ocean Breeze", "40000", "7"},
        {"Vanilla Dream", "32000", "15"},
        {"Rose Garden", "45000", "9"},
        {"Lemon Zest", "30000", "18"},
        {"Cinnamon Spice", "38000", "5"},
        {"Mint Fresh", "29000", "10"},
        {"Jasmine Bloom", "41000", "13"},
        {"Coffee Scent", "36000", "11"},
        {"Woodland Pine", "47000", "6"}
    },
    {"Andi Nurfadillah Hasan", "2409106087"},
    10
};

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

void perbaruiHargaLilin(string &hargaBaru) {
    cout << "Harga baru akan menjadi: ";
    getline(cin, hargaBaru);
}

void ubahStokLilin(string *stokPtr) {
    cout << "Stok baru akan menjadi: ";
    getline(cin, *stokPtr);
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
        cout << "\n+===============================================================+\n";
        cout << "| No  | Nama Lilin          | Harga (Rp)   | Stok (pcs) |\n";
        cout << "+===============================================================+\n";
        for (int i = 0; i < s.jumlahLilin; i++) {
            cout << "| " << setw(3) << left << i + 1 << " | "
                 << setw(20) << left << s.lilin[i].nama << " | "
                 << setw(12) << right << s.lilin[i].harga << " | "
                 << setw(10) << right << s.lilin[i].stok << " |\n";
        }
        cout << "+===============================================================+\n";
    }
}

void perbaruiLilin(Sistem &s, int index) {
    if (index >= 0 && index < s.jumlahLilin) {
        perbaruiHargaLilin(s.lilin[index].harga);    
        ubahStokLilin(&s.lilin[index].stok);         
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

void sortNamaDescending(Sistem s) {
    for (int i = 0; i < s.jumlahLilin - 1; i++) {
        for (int j = 0; j < s.jumlahLilin - i - 1; j++) {
            if (s.lilin[j].nama < s.lilin[j + 1].nama) {
                swap(s.lilin[j], s.lilin[j + 1]);
            }
        }
    }
    lihatLilin(s);
}

void sortHargaAscending(Sistem s) {
    for (int i = 0; i < s.jumlahLilin - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < s.jumlahLilin; j++) {
            if (stoi(s.lilin[j].harga) < stoi(s.lilin[minIndex].harga)) {
                minIndex = j;
            }
        }
        swap(s.lilin[i], s.lilin[minIndex]);
    }
    lihatLilin(s);
}

void sortStokDescending(Sistem s) {
    for (int i = 1; i < s.jumlahLilin; i++) {
        Lilin key = s.lilin[i];
        int j = i - 1;
        while (j >= 0 && stoi(s.lilin[j].stok) < stoi(key.stok)) {
            s.lilin[j + 1] = s.lilin[j];
            j--;
        }
        s.lilin[j + 1] = key;
    }
    lihatLilin(s);
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
        cout << "1.  Tambah Lilin\n";
        cout << "2.  Lihat Data Lilin\n";
        cout << "3.  Perbarui Data Lilin\n";
        cout << "4.  Hapus Data Lilin\n";
        cout << "5.  Total Stok Lilin\n";
        cout << "6.  Nama Lilin (Bubble Sort)\n";
        cout << "7.  Harga Lilin (Selection Sort)\n";
        cout << "8.  Stok Lilin (Insertion Sort)\n";
        cout << "9.  Keluar\n";
        cout << "Pilih menu: ";

        int pilihan;
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            tambahLilin(sistem);
        } else if (pilihan == 2) {
            lihatLilin(sistem);
        } else if (pilihan == 3) {
            lihatLilin(sistem);  
            int indeks;
            cout << "Masukkan nomor lilin yang ingin diperbarui: ";
            cin >> indeks;
            cin.ignore();
            perbaruiLilin(sistem, indeks - 1);
        } else if (pilihan == 4) {
            lihatLilin(sistem);
            int indeks;
            cout << "Masukkan nomor lilin yang ingin dihapus: ";
            cin >> indeks;
            cin.ignore();
            hapusLilin(sistem, indeks - 1);
        } else if (pilihan == 5) {
            int total = totalStok(0);
            cout << "Total seluruh stok lilin: " << total << " pcs\n";
        } else if (pilihan == 6) {
            sortNamaDescending(sistem);
        } else if (pilihan == 7) {
            sortHargaAscending(sistem);
        } else if (pilihan == 8) {
            sortStokDescending(sistem);
        } else if (pilihan == 9) {
            ucapan(nama);
            break;
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    }

    return 0;
}
