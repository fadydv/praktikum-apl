#include <iostream>
using namespace std;

int main() {
    string username, password;
    int percobaan = 0;
    bool loginBerhasil = false;

    while (percobaan < 3 && !loginBerhasil) {
        cout << "Masukkan Username: ";
        getline(cin, username);
        cout << "Masukkan Password: ";
        getline(cin, password);

        if (username == "Andi Nurfadillah Hasan" && password == "2409106087") {
            loginBerhasil = true;
            cout << "Login berhasil!\n\n";
        } else {
            percobaan++;
            cout << "Username atau Password salah! Percobaan ke-" << percobaan << "/3\n\n";
        }
    }

    if (!loginBerhasil) {
        cout << "Kesempatan login habis. Program berhenti.\n";
        return 0;
    }

    int pilihanMenu;
    do {
        cout << "\n--- Menu Utama ---\n";
        cout << "1. Konversi Mata Uang\n";
        cout << "2. Konversi Jarak\n";
        cout << "3. Konversi Waktu\n";
        cout << "4. Logout\n";
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1: {
                int pilihanUang;
                double nilai, hasil;
                cout << "\n--- Konversi Mata Uang ---\n";
                cout << "1. Rupiah ke Dolar AS\n";
                cout << "2. Rupiah ke Euro\n";
                cout << "3. Dolar AS ke Rupiah\n";
                cout << "4. Dolar AS ke Euro\n";
                cout << "5. Euro ke Rupiah\n";
                cout << "6. Euro ke Dolar AS\n";
                cout << "7. Kembali\n";
                cout << "Pilih opsi: ";
                cin >> pilihanUang;

                if (pilihanUang >= 1 && pilihanUang <= 6) {
                    cout << "Masukkan jumlah: ";
                    cin >> nilai;
                }

                switch (pilihanUang) {
                    case 1: hasil = nilai / 15000; cout << "Hasil: " << hasil << " USD\n"; break;
                    case 2: hasil = nilai / 16000; cout << "Hasil: " << hasil << " EUR\n"; break;
                    case 3: hasil = nilai * 15000; cout << "Hasil: " << hasil << " IDR\n"; break;
                    case 4: hasil = nilai * 0.85; cout << "Hasil: " << hasil << " EUR\n"; break;
                    case 5: hasil = nilai * 17000; cout << "Hasil: " << hasil << " IDR\n"; break;
                    case 6: hasil = nilai * 1.18; cout << "Hasil: " << hasil << " USD\n"; break;
                    case 7: cout << "Kembali ke menu utama...\n"; break;
                    default: cout << "Pilihan tidak valid!\n";
                }
                break;
            }

            case 2: {
                int pilihanJarak;
                double nilai, hasil;
                cout << "\n--- Konversi Jarak ---\n";
                cout << "1. Kilometer ke Meter\n";
                cout << "2. Kilometer ke Centimeter\n";
                cout << "3. Meter ke Kilometer\n";
                cout << "4. Meter ke Centimeter\n";
                cout << "5. Centimeter ke Kilometer\n";
                cout << "6. Centimeter ke Meter\n";
                cout << "7. Kembali\n";
                cout << "Pilih opsi: ";
                cin >> pilihanJarak;

                if (pilihanJarak >= 1 && pilihanJarak <= 6) {
                    cout << "Masukkan jarak: ";
                    cin >> nilai;
                }

                switch (pilihanJarak) {
                    case 1: hasil = nilai * 1000; cout << "Hasil: " << hasil << " m\n"; break;
                    case 2: hasil = nilai * 100000; cout << "Hasil: " << hasil << " cm\n"; break;
                    case 3: hasil = nilai / 1000; cout << "Hasil: " << hasil << " km\n"; break;
                    case 4: hasil = nilai * 100; cout << "Hasil: " << hasil << " cm\n"; break;
                    case 5: hasil = nilai / 100000; cout << "Hasil: " << hasil << " km\n"; break;
                    case 6: hasil = nilai / 100; cout << "Hasil: " << hasil << " m\n"; break;
                    case 7: cout << "Kembali ke menu utama...\n"; break;
                    default: cout << "Pilihan tidak valid!\n";
                }
                break;
            }

            case 3: {
                int pilihanWaktu;
                double nilai, hasil;
                cout << "\n--- Konversi Waktu ---\n";
                cout << "1. Jam ke Menit\n";
                cout << "2. Jam ke Detik\n";
                cout << "3. Menit ke Jam\n";
                cout << "4. Menit ke Detik\n";
                cout << "5. Detik ke Jam\n";
                cout << "6. Detik ke Menit\n";
                cout << "7. Kembali\n";
                cout << "Pilih opsi: ";
                cin >> pilihanWaktu;

                if (pilihanWaktu >= 1 && pilihanWaktu <= 6) {
                    cout << "Masukkan waktu: ";
                    cin >> nilai;
                }

                switch (pilihanWaktu) {
                    case 1: hasil = nilai * 60; cout << "Hasil: " << hasil << " menit\n"; break;
                    case 2: hasil = nilai * 3600; cout << "Hasil: " << hasil << " detik\n"; break;
                    case 3: hasil = nilai / 60; cout << "Hasil: " << hasil << " jam\n"; break;
                    case 4: hasil = nilai * 60; cout << "Hasil: " << hasil << " detik\n"; break;
                    case 5: hasil = nilai / 3600; cout << "Hasil: " << hasil << " jam\n"; break;
                    case 6: hasil = nilai / 60; cout << "Hasil: " << hasil << " menit\n"; break;
                    case 7: cout << "Kembali ke menu utama...\n"; break;
                    default: cout << "Pilihan tidak valid!\n";
                }
                break;
            }

            case 4:
                cout << "Logout berhasil. Program berhenti.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihanMenu != 4);

    return 0;
}