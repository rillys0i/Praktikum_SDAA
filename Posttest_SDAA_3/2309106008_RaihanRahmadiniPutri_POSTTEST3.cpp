#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama_barang;
    string kategori;
    int jumlah;
    double nilai_barang;
};

struct Node {
    Barang data_barang;
    Node* node_berikutnya;
};

void tambahBarang(Node** pointer_awal, string nama_barang, string kategori, int jumlah_barang, double nilai_barang) {
    Node* node_baru = new Node();  
    node_baru->data_barang.nama_barang = nama_barang;
    node_baru->data_barang.kategori = kategori;
    node_baru->data_barang.jumlah = jumlah_barang;
    node_baru->data_barang.nilai_barang = nilai_barang;
    node_baru->node_berikutnya = nullptr;

    if (*pointer_awal == nullptr) {
        *pointer_awal = node_baru;
    } else {
        Node* node_sementara = *pointer_awal;
        while (node_sementara->node_berikutnya != nullptr) {
            node_sementara = node_sementara->node_berikutnya;
        }
        node_sementara->node_berikutnya = node_baru;
    }
}

void tampilkanDaftarBarang(Node* pointer_awal) {
    cout << "Daftar Barang di Bea Cukai:" << endl;
    if (pointer_awal == nullptr) {
        cout << "Tidak ada barang yang terdaftar." << endl;
        return;
    }
    Node* node_sementara = pointer_awal;
    int indeks_barang = 1;
    while (node_sementara != nullptr) {
        cout << "Barang ke-" << indeks_barang++ << endl;
        cout << "Nama Barang: " << node_sementara->data_barang.nama_barang << endl;
        cout << "Kategori: " << node_sementara->data_barang.kategori << endl;
        cout << "Jumlah: " << node_sementara->data_barang.jumlah << endl;
        cout << "Nilai Barang: " << node_sementara->data_barang.nilai_barang << " IDR" << endl;
        cout << "---------------------------" << endl;
        node_sementara = node_sementara->node_berikutnya;
    }
}

void ubahBarang(Node* pointer_awal, int posisi_barang, string nama_barang_baru, string kategori_baru, int jumlah_barang_baru, double nilai_barang_baru) {
    Node* node_sementara = pointer_awal;
    int indeks_barang = 0;
    while (node_sementara != nullptr && indeks_barang < posisi_barang) {
        node_sementara = node_sementara->node_berikutnya;
        indeks_barang++;
    }
    if (node_sementara != nullptr) {
        node_sementara->data_barang.nama_barang = nama_barang_baru;
        node_sementara->data_barang.kategori = kategori_baru;
        node_sementara->data_barang.jumlah = jumlah_barang_baru;
        node_sementara->data_barang.nilai_barang = nilai_barang_baru;
        cout << "Barang berhasil diubah!" << endl;
    } else {
        cout << "Posisi barang tidak valid!" << endl;
    }
}

void hapusBarang(Node** pointer_awal, int posisi_barang) {
    if (*pointer_awal == nullptr) {
        cout << "Posisi barang tidak valid!" << endl;
        return;
    }
    
    Node* node_sementara = *pointer_awal;
    
    if (posisi_barang == 0) {
        *pointer_awal = node_sementara->node_berikutnya;
        delete node_sementara;
        cout << "Barang berhasil dihapus!" << endl;
        return;
    }
    
    for (int indeks_barang = 0; node_sementara != nullptr && indeks_barang < posisi_barang - 1; indeks_barang++) {
        node_sementara = node_sementara->node_berikutnya;
    }
    
    if (node_sementara == nullptr || node_sementara->node_berikutnya == nullptr) {
        cout << "Posisi barang tidak valid!" << endl;
        return;
    }

    Node* node_berikutnya = node_sementara->node_berikutnya->node_berikutnya;
    delete node_sementara->node_berikutnya;
    node_sementara->node_berikutnya = node_berikutnya;
    
    cout << "Barang berhasil dihapus!" << endl;
}

double hitungTotalNilai(Node* pointer_awal) {
    double total_nilai_barang = 0;
    Node* node_sementara = pointer_awal;
    while (node_sementara != nullptr) {
        total_nilai_barang += node_sementara->data_barang.nilai_barang * node_sementara->data_barang.jumlah;
        node_sementara = node_sementara->node_berikutnya;
    }
    return total_nilai_barang;
}

int main() {
    Node* daftar_barang = nullptr;
    int pilihan_menu;
    do {
        cout << "\n=== Pendataan Barang di Bea Cukai ===" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Tampilkan Daftar Barang" << endl;
        cout << "3. Ubah Barang" << endl;
        cout << "4. Hapus Barang" << endl;
        cout << "5. Tampilkan Total Nilai Barang" << endl;
        cout << "6. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan_menu;

        if (pilihan_menu == 1) {
            string nama_barang, kategori_barang;
            int jumlah_barang;
            double nilai_barang;
            cout << "Masukkan Nama Barang: ";
            cin >> nama_barang;
            cout << "Masukkan Kategori: ";
            cin >> kategori_barang;
            cout << "Masukkan Jumlah: ";
            cin >> jumlah_barang;
            cout << "Masukkan Nilai Barang: ";
            cin >> nilai_barang;
            tambahBarang(&daftar_barang, nama_barang, kategori_barang, jumlah_barang, nilai_barang);

        } else if (pilihan_menu == 2) {
            tampilkanDaftarBarang(daftar_barang);

        } else if (pilihan_menu == 3) {
            int posisi_barang;
            string nama_barang_baru, kategori_barang_baru;
            int jumlah_barang_baru;
            double nilai_barang_baru;
            tampilkanDaftarBarang(daftar_barang);
            cout << "Pilih posisi barang yang ingin diubah (mulai dari 1): ";
            cin >> posisi_barang;
            cout << "Masukkan Nama Barang baru: ";
            cin >> nama_barang_baru;
            cout << "Masukkan Kategori baru: ";
            cin >> kategori_barang_baru;
            cout << "Masukkan Jumlah baru: ";
            cin >> jumlah_barang_baru;
            cout << "Masukkan Nilai Barang baru: ";
            cin >> nilai_barang_baru;
            ubahBarang(daftar_barang, posisi_barang - 1, nama_barang_baru, kategori_barang_baru, jumlah_barang_baru, nilai_barang_baru);

        } else if (pilihan_menu == 4) {
            int posisi_barang;
            tampilkanDaftarBarang(daftar_barang);
            cout << "Pilih posisi barang yang ingin dihapus (mulai dari 1): ";
            cin >> posisi_barang;
            hapusBarang(&daftar_barang, posisi_barang - 1);

        } else if (pilihan_menu == 5) {
            double total_nilai_barang = hitungTotalNilai(daftar_barang);
            cout << "Total Nilai Barang: " << total_nilai_barang << " IDR" << endl;

        } else if (pilihan_menu == 6) {
            cout << "Keluar dari program." << endl;

        } else {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan_menu != 6);

    return 0;
}
