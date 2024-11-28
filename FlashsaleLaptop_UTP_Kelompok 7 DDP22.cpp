#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Anggota Kelompok 7:
1. Ananda Sheva Hidayat (2217051096)
2. Dede Juniar Putra (2217051015)
3. Farid Sidhiq (2257051028)
*/

// Struktur untuk data laptop
struct Laptop {
    string nama; // Menyimpan nama laptop
    int harga;   // Menyimpan harga laptop
};

// Konstanta
const double PAJAK = 0.1; // Pajak sebesar 10%

// Deklarasi variabel global
int totalHarga = 0; // Variabel global untuk menyimpan total harga pembelian

// Fungsi untuk menampilkan header toko
void header() {
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "||\t\t\t\t\tWELCOME TO DFS COM STORE\t\t\t\t||\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"; 
}

// Fungsi untuk menampilkan daftar laptop
void tampilkanLaptop(const vector<Laptop>& daftarLaptop) {
    cout << "BERIKUT ADALAH 10 LAPTOP YANG AKAN DI FLASHSALE PADA 11/11:\n\n";
    for (size_t i = 0; i < daftarLaptop.size(); i++) {
        // Menampilkan setiap laptop di daftar lengkap dengan nama dan harga
        cout << i + 1 << ". " << daftarLaptop[i].nama << "\tONLY!!!\tRp. " << daftarLaptop[i].harga << endl;
    }
    cout << "\nNOTED: HARGA SUDAH TERMASUK PAJAK!" << endl;
}

// Fungsi untuk menghitung total harga pembelian
int hitungTotal(const vector<int>& harga) {
    int total = 0; // Variabel untuk menyimpan total sementara
    for (int h : harga) {
        total += h; // Menambahkan setiap harga ke total
    }
    return total;
}

// Fungsi untuk menampilkan footer toko
void closeHeader() {
    cout << "==========================================================\n";
    cout << "||\tTERIMA KASIH SUDAH BERBELANJA DI TOKO KAMI\t||\n";
    cout << "||\t\t   HAVE A NICE DAY ^_^\t\t\t||\n";
    cout << "==========================================================\n";
}

int main() {
    // Daftar laptop yang tersedia di toko
    vector<Laptop> daftarLaptop = {
        {"Lenovo Ideapad Slim 3i 4/256GB", 5999000},
        {"Dell Inspiron 3511 4/256GB", 6499000},
        {"Asus Vivobook 14 4/256GB", 6799000},
        {"HP 14s-FQ0020AU 8/512GB", 7199000},
        {"Lenovo Ideapad S340 8/512GB", 7599000},
        {"Acer Aspire Slim 5 8/512GB", 7999000},
        {"Asus Vivobook Ultra 15 8/256GB", 8299000},
        {"MSI Modern 14 8/512GB", 8799000},
        {"HP Pavilion 8/512GB", 9499000},
        {"Acer Nitro 5 8/512GB", 9999000}
    };

    string nama, yes;           // Variabel untuk nama pengguna dan konfirmasi pembelian lagi
    vector<int> harga;          // Menyimpan harga laptop yang dipilih
    do {
        system("CLS");          // Membersihkan layar terminal
        system("COLOR 06");     // Mengatur warna tampilan
        header();               // Menampilkan header toko
        cout << endl;

        // Menampilkan daftar laptop
        tampilkanLaptop(daftarLaptop);
        cout << endl;

        // Input nama customer
        cout << "Username Customer\t : "; cin.ignore(); getline(cin, nama);

        // Input jumlah pembelian
        int jumlahPembelian;
        cout << "Jumlah Pembelian\t : "; cin >> jumlahPembelian;

        // Loop untuk memilih laptop berdasarkan jumlah pembelian
        for (int i = 0; i < jumlahPembelian; i++) {
            int kodeLaptop;
            do {
                // Meminta input pilihan laptop (1-10)
                cout << "\nPilihan Laptop ke-" << i + 1 << " (1-10): ";
                cin >> kodeLaptop;
                if (kodeLaptop < 1 || kodeLaptop > 10) {
                    cout << "Opsi tidak valid, silakan ulangi." << endl;
                }
            } while (kodeLaptop < 1 || kodeLaptop > 10);

            // Menambahkan harga laptop ke daftar
            cout << "Laptop yang kamu ambil: " << daftarLaptop[kodeLaptop - 1].nama << endl;
            harga.push_back(daftarLaptop[kodeLaptop - 1].harga);
        }

        // Menghitung total harga
        totalHarga = hitungTotal(harga);
        cout << "\nTotal Pembayaran\t : Rp. " << totalHarga << endl;

        // Input pembayaran dari pengguna
        int bayar;
        cout << "Bayar\t\t\t : Rp. "; cin >> bayar;

        // Validasi pembayaran
        while (bayar < totalHarga) {
            int kurang = totalHarga - bayar;
            cout << "Uang anda tidak cukup! Silahkan bayar kembali: Rp. " << kurang << endl;
            cout << "Bayar Kembali\t : Rp. "; cin >> kurang;
            bayar += kurang;
        }

        // Menampilkan kembalian
        cout << "Kembali\t\t\t : Rp. " << bayar - totalHarga << endl;

        // Tanya untuk pembelian ulang
        cout << "\nIngin Membeli lagi? [Y/T] : "; cin >> yes;
        harga.clear(); // Reset daftar harga untuk pembelian baru
        totalHarga = 0; // Reset total harga

    } while (yes == "Y" || yes == "y"); // Ulangi jika pengguna ingin membeli lagi

    closeHeader(); // Menampilkan footer toko
    return 0; // Mengakhiri program
}
