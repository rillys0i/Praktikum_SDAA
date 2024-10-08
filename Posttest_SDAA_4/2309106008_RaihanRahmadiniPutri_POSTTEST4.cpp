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

void push(Node** pointer_awal, string nama_barang, string kategori, int jumlah_barang, double nilai_barang) {
    Node* node_baru = new Node();
    node_baru->data_barang.nama_barang = nama_barang;
    node_baru->data_barang.kategori = kategori;
    node_baru->data_barang.jumlah = jumlah_barang;
    node_baru->data_barang.nilai_barang = nilai_barang;
    node_baru->node_berikutnya = *pointer_awal;
    *pointer_awal = node_baru;
    cout << "Barang berhasil ditambahkan ke Stack!" << endl;
}

void pop(Node** pointer_awal) {
    if (*pointer_awal == nullptr) {
        cout << "Stack kosong, tidak ada barang untuk dihapus!" << endl;
        return;
    }
    Node* node_sementara = *pointer_awal;
    *pointer_awal = node_sementara->node_berikutnya;
    delete node_sementara;
    cout << "Barang berhasil dihapus dari Stack!" << endl;
}

void enqueue(Node** pointer_awal, Node** pointer_akhir, string nama_barang, string kategori, int jumlah_barang, double nilai_barang) {
    Node* node_baru = new Node();
    node_baru->data_barang.nama_barang = nama_barang;
    node_baru->data_barang.kategori = kategori;
    node_baru->data_barang.jumlah = jumlah_barang;
    node_baru->data_barang.nilai_barang = nilai_barang;
    node_baru->node_berikutnya = nullptr;

    if (*pointer_akhir == nullptr) {
        *pointer_awal = node_baru;
        *pointer_akhir = node_baru;
    } else {
        (*pointer_akhir)->node_berikutnya = node_baru;
        *pointer_akhir = node_baru;
    }
    cout << "Barang berhasil ditambahkan ke Queue!" << endl;
}

void dequeue(Node** pointer_awal) {
    if (*pointer_awal == nullptr) {
        cout << "Queue kosong, tidak ada barang untuk dihapus!" << endl;
        return;
    }
    Node* node_sementara = *pointer_awal;
    *pointer_awal = node_sementara->node_berikutnya;
    delete node_sementara;
    cout << "Barang berhasil dihapus dari Queue!" << endl;
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

int main() {
    Node* stack = nullptr;  
    Node* queue_awal = nullptr;  
    Node* queue_akhir = nullptr;  
    int pilihan_menu;
    do {
        cout << "\n=== Pendataan Barang di Bea Cukai ===" << endl;
        cout << "1. Tambah Barang ke Stack" << endl; 
        cout << "2. Hapus Barang dari Stack" << endl; 
        cout << "3. Tambah Barang ke Queue" << endl; 
        cout << "4. Hapus Barang dari Queue" << endl; 
        cout << "5. Tampilkan Daftar Barang di Stack" << endl;
        cout << "6. Tampilkan Daftar Barang di Queue" << endl;
        cout << "7. Keluar" << endl;
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
            push(&stack, nama_barang, kategori_barang, jumlah_barang, nilai_barang);

        } else if (pilihan_menu == 2) {
            pop(&stack);

        } else if (pilihan_menu == 3) {
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
            enqueue(&queue_awal, &queue_akhir, nama_barang, kategori_barang, jumlah_barang, nilai_barang);

        } else if (pilihan_menu == 4) {
            dequeue(&queue_awal);

        } else if (pilihan_menu == 5) {
            tampilkanDaftarBarang(stack);

        } else if (pilihan_menu == 6) {
            tampilkanDaftarBarang(queue_awal);

        } else if (pilihan_menu == 7) {
            cout << "Keluar dari program." << endl;

        } else {
            cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan_menu != 7);

    return 0;
}
