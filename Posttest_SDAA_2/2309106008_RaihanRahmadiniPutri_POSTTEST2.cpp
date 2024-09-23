#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama_barang;
    string kategori;
    int jumlah;
    double nilai_barang;
};

void tambahBarang(Barang *daftar_barang, int *jumlah_barang, string nama_barang, string kategori, int jumlah, double nilai_barang) {
    daftar_barang[*jumlah_barang].nama_barang = nama_barang;
    daftar_barang[*jumlah_barang].kategori = kategori;
    daftar_barang[*jumlah_barang].jumlah = jumlah;
    daftar_barang[*jumlah_barang].nilai_barang = nilai_barang;
    (*jumlah_barang)++;
}

void tampilkanDaftarBarang(Barang *daftar_barang, int jumlah_barang) {
    cout << "Daftar Barang di Bea Cukai:" << endl;
    if (jumlah_barang == 0) {
        cout << "Tidak ada barang yang terdaftar." << endl;
        return;
    }
    for (int i = 0; i < jumlah_barang; i++) {
        cout << "Barang ke-" << i + 1 << endl;
        cout << "Nama Barang: " << daftar_barang[i].nama_barang << endl;
        cout << "Kategori: " << daftar_barang[i].kategori << endl;
        cout << "Jumlah: " << daftar_barang[i].jumlah << endl;
        cout << "Nilai Barang: " << daftar_barang[i].nilai_barang << " IDR" << endl;
        cout << "---------------------------" << endl;
    }
}

void ubahBarang(Barang *daftar_barang, int jumlah_barang, int posisi_barang, string nama_barang, string kategori, int jumlah, double nilai_barang) {
    if (posisi_barang >= 0 && posisi_barang < jumlah_barang) {
        daftar_barang[posisi_barang].nama_barang = nama_barang;
        daftar_barang[posisi_barang].kategori = kategori;
        daftar_barang[posisi_barang].jumlah = jumlah;
        daftar_barang[posisi_barang].nilai_barang = nilai_barang;
        cout << "Barang berhasil diubah!" << endl;
    } else {
        cout << "posisi barang tidak valid!" << endl;
    }
}

void hapusBarang(Barang *daftar_barang, int *jumlah_barang, int posisi_barang) {
    if (posisi_barang >= 0 && posisi_barang < *jumlah_barang) {
        for (int i = posisi_barang; i < *jumlah_barang - 1; i++) {
            daftar_barang[i] = daftar_barang[i + 1];
        }
        (*jumlah_barang)--; 
        cout << "Barang berhasil dihapus!" << endl;
    } else {
        cout << "posisi barang tidak valid!" << endl;
    }
}

double hitungTotalNilai(Barang *daftar_barang, int jumlah_barang) {
    double total_nilai = 0;
    for (int i = 0; i < jumlah_barang; i++) {
        total_nilai += daftar_barang[i].nilai_barang * daftar_barang[i].jumlah;
    }
    return total_nilai;
}

int main() {
    int kapasitas_maksimum = 100;  
    Barang daftar_barang[kapasitas_maksimum];  
    int jumlah_barang = 0;
    int pilihan;
    do {
        cout << "\n=== Pendataan Barang di Bea Cukai ===" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Daftar Barang" << endl;
        cout << "3. Ubah Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Tampilkan Total Nilai Barang" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string nama_barang, kategori;
            int jumlah;
            double nilai_barang;
            cout << "Masukkan Nama Barang: ";
            cin >> nama_barang;
            cout << "Masukkan Kategori: ";
            cin >> kategori;
            cout << "Masukkan Jumlah: ";
            cin >> jumlah;
            cout << "Masukkan Nilai Barang: ";
            cin >> nilai_barang;
            tambahBarang(daftar_barang, &jumlah_barang, nama_barang, kategori, jumlah, nilai_barang);

        } else if (pilihan == 2) {
            tampilkanDaftarBarang(daftar_barang, jumlah_barang);

        } else if (pilihan == 3) {
            int posisi_barang;
            string nama_barang, kategori;
            int jumlah;
            double nilai_barang;
            tampilkanDaftarBarang(daftar_barang, jumlah_barang);
            cout << "Pilih posisi barang yang ingin diubah (mulai dari 1): ";
            cin >> posisi_barang;
            cout << "Masukkan Nama Barang baru: ";
            cin >> nama_barang;
            cout << "Masukkan Kategori baru: ";
            cin >> kategori;
            cout << "Masukkan Jumlah baru: ";
            cin >> jumlah;
            cout << "Masukkan Nilai Barang baru: ";
            cin >> nilai_barang;
            ubahBarang(daftar_barang, jumlah_barang, posisi_barang - 1, nama_barang, kategori, jumlah, nilai_barang);

        } else if (pilihan == 4) {
            int posisi_barang;
            tampilkanDaftarBarang(daftar_barang, jumlah_barang);
            cout << "Pilih posisi barang yang ingin dihapus (mulai dari 1): ";
            cin >> posisi_barang;
            hapusBarang(daftar_barang, &jumlah_barang, posisi_barang - 1);

        } else if (pilihan == 5) {
            double total_nilai = hitungTotalNilai(daftar_barang, jumlah_barang);
            cout << "Total Nilai Barang: " << total_nilai << " IDR" << endl;

        } else if (pilihan == 6) {
            cout << "Keluar dari program." << endl;

        } else {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 6);

    return 0;
}
