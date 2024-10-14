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

void tambahBarangKeStack(Node** pointer_awal, string nama_barang, string kategori, int jumlah_barang, double nilai_barang) {
    Node* node_baru = new Node();
    node_baru->data_barang.nama_barang = nama_barang;
    node_baru->data_barang.kategori = kategori;
    node_baru->data_barang.jumlah = jumlah_barang;
    node_baru->data_barang.nilai_barang = nilai_barang;
    node_baru->node_berikutnya = *pointer_awal;
    *pointer_awal = node_baru;
    cout << "Barang berhasil ditambahkan ke Stack!" << endl;
}

void hapusBarangDariStack(Node** pointer_awal) {
    if (*pointer_awal == nullptr) {
        cout << "Stack kosong, tidak ada barang untuk dihapus!" << endl;
        return;
    }
    Node* node_sementara = *pointer_awal;
    *pointer_awal = node_sementara->node_berikutnya;
    delete node_sementara;
    cout << "Barang berhasil dihapus dari Stack!" << endl;
}

void tambahBarangKeQueue(Node** pointer_awal, Node** pointer_akhir, string nama_barang, string kategori, int jumlah_barang, double nilai_barang) {
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

void hapusBarangDariQueue(Node** pointer_awal) {
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
    cout << "Daftar Barang:" << endl;
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

int hitungJumlahNode(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->node_berikutnya;
    }
    return count;
}

Node* ambilNodePadaIndeks(Node* head, int index) {
    int count = 0;
    while (head != nullptr && count < index) {
        head = head->node_berikutnya;
        count++;
    }
    return head;
}

Node* ambilNodeTerakhir(Node* head) {
    while (head != nullptr && head->node_berikutnya != nullptr) {
        head = head->node_berikutnya;
    }
    return head;
}

Node* pembagianTerakhir(Node* start, Node* end, Node** awalBaru, Node** akhirBaru) {
    Node* pivot = end;
    Node* prev = nullptr, * curr = start, * tail = pivot;

    while (curr != pivot) {
        if (curr->data_barang.nilai_barang > pivot->data_barang.nilai_barang) {
            if ((*awalBaru) == nullptr) {
                (*awalBaru) = curr;
            }
            prev = curr;
            curr = curr->node_berikutnya;
        } else {
            if (prev != nullptr) {
                prev->node_berikutnya = curr->node_berikutnya;
            }
            Node* temp = curr->node_berikutnya;
            curr->node_berikutnya = nullptr;
            tail->node_berikutnya = curr;
            tail = curr;
            curr = temp;
        }
    }

    if ((*awalBaru) == nullptr) {
        (*awalBaru) = pivot;
    }

    (*akhirBaru) = tail;
    return pivot;
}

Node* quickSort(Node* start, Node* end) {
    if (!start || start == end) {
        return start;
    }

    Node* awalBaru = nullptr;
    Node* akhirBaru = nullptr;

    Node* pivot = pembagianTerakhir(start, end, &awalBaru, &akhirBaru);

    if (awalBaru != pivot) {
        Node* temp = awalBaru;
        while (temp->node_berikutnya != pivot) {
            temp = temp->node_berikutnya;
        }
        temp->node_berikutnya = nullptr;

        awalBaru = quickSort(awalBaru, temp);

        temp = ambilNodeTerakhir(awalBaru);
        temp->node_berikutnya = pivot;
    }

    pivot->node_berikutnya = quickSort(pivot->node_berikutnya, akhirBaru);

    return awalBaru;
}

void urutkanStackDescending(Node** headRef) {
    (*headRef) = quickSort(*headRef, ambilNodeTerakhir(*headRef));
    cout << "Stack berhasil diurutkan secara descending." << endl;
}

void urutkanQueueAscending(Node** head) {
    int n = hitungJumlahNode(*head);
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            Node* temp = ambilNodePadaIndeks(*head, i);
            Node* jNode = ambilNodePadaIndeks(*head, i - gap);
            Barang tempBarang = temp->data_barang;

            while (jNode && jNode->data_barang.nilai_barang > tempBarang.nilai_barang) {
                temp->data_barang = jNode->data_barang;
                temp = jNode;
                jNode = ambilNodePadaIndeks(*head, i - gap);
            }
            temp->data_barang = tempBarang;
        }
    }
    cout << "Queue berhasil diurutkan secara ascending." << endl;
}

int main() {
    Node* stack = nullptr;  
    Node* queue_awal = nullptr;  
    Node* queue_akhir = nullptr;  
    int pilihan_menu;
    do {
        cout << "\n=== Pendataan Barang ===" << endl;
        cout << "1. Tambah Barang ke Stack" << endl; 
        cout << "2. Hapus Barang dari Stack" << endl; 
        cout << "3. Tambah Barang ke Queue" << endl; 
        cout << "4. Hapus Barang dari Queue" << endl; 
        cout << "5. Tampilkan Daftar Barang di Stack" << endl;
        cout << "6. Tampilkan Daftar Barang di Queue" << endl;
        cout << "7. Urutkan Stack secara Descending" << endl;
        cout << "8. Urutkan Queue secara Ascending" << endl;
        cout << "9. Keluar" << endl;
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
            tambahBarangKeStack(&stack, nama_barang, kategori_barang, jumlah_barang, nilai_barang);
        } else if (pilihan_menu == 2) {
            hapusBarangDariStack(&stack);
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
            tambahBarangKeQueue(&queue_awal, &queue_akhir, nama_barang, kategori_barang, jumlah_barang, nilai_barang);
        } else if (pilihan_menu == 4) {
            hapusBarangDariQueue(&queue_awal);
        } else if (pilihan_menu == 5) {
            tampilkanDaftarBarang(stack);
        } else if (pilihan_menu == 6) {
            tampilkanDaftarBarang(queue_awal);
        } else if (pilihan_menu == 7) {
            urutkanStackDescending(&stack);
        } else if (pilihan_menu == 8) {
            urutkanQueueAscending(&queue_awal);
        }
    } while (pilihan_menu != 9);

    cout << "Program selesai!" << endl;
    return 0;
}
