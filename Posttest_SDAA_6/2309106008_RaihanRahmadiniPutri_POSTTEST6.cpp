#include <iostream>
#include <string>
#include <cstdlib>  
#include <thread>   
#include <chrono>   
#include <limits>  
#include <cmath>    
#include <vector>   
#include <algorithm>


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


void tambahBarangKeStack(Node** pointer_awal, string nama_barang, string kategori, int jumlah_barang, double nilai_barang);
void hapusBarangDariStack(Node** pointer_awal);
void tampilkanDaftarBarang(Node* pointer_awal);
Node* ambilNodeTerakhir(Node* head);
Node* quickSort(Node* start, Node* end);
void urutkanStackDescending(Node** headRef);
void tambahBarangKeQueue(Node** pointer_awal, Node** pointer_akhir, string nama_barang, string kategori, int jumlah_barang, double nilai_barang);
void hapusBarangDariQueue(Node** pointer_awal);
void urutkanQueueAscending(Node** head);
int hitungJumlahNode(Node* head);
void clearConsole();
bool validasiInputInt(int& input);
bool validasiInputDouble(double& input);
void bersihkanMemori(Node** pointer_awal);
int fibonacciSearch(int arr[], int n, int x);
int jumpSearch(int arr[], int n, int x);
int boyerMooreSearch(const string& text, const string& pattern);
void cariJumlahBarangDenganFibonacci(Node* head, int jumlah_dicari);
void cariJumlahBarangDenganJump(Node* head, int jumlah_dicari);
void cariNamaBarangDenganBoyerMoore(Node* head, string nama_dicari);

int main() {
    Node* stack = nullptr;  
    Node* queue_awal = nullptr;  
    Node* queue_akhir = nullptr;  
    int pilihan_menu;

    do {
        clearConsole(); 
        cout << "\n=== Pendataan Barang ===" << endl;
        cout << "1. Menu Stack" << endl; 
        cout << "2. Menu Queue" << endl; 
        cout << "3. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan_menu;

        if (pilihan_menu == 1) {
            int pilihan_stack;
            do {
                clearConsole(); 
                cout << "\n=== Menu Stack ===" << endl;
                cout << "1. Tambah Barang ke Stack" << endl; 
                cout << "2. Hapus Barang dari Stack" << endl; 
                cout << "3. Tampilkan Daftar Barang di Stack" << endl;
                cout << "4. Urutkan Stack secara Descending" << endl;
                cout << "5. Cari Jumlah Barang (Fibonacci Search)" << endl;
                cout << "6. Cari Jumlah Barang (Jump Search)" << endl;
                cout << "7. Cari Nama Barang (Boyer-Moore Search)" << endl;
                cout << "8. Kembali ke Menu Utama" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan_stack;

                if (pilihan_stack == 1) {
                    string nama_barang, kategori_barang;
                    int jumlah_barang;
                    double nilai_barang;
                    cout << "Masukkan Nama Barang: ";
                    cin >> nama_barang;
                    cout << "Masukkan Kategori: ";
                    cin >> kategori_barang;

                    do {
                        cout << "Masukkan Jumlah: ";
                    } while (!validasiInputInt(jumlah_barang));  

                    do {
                        cout << "Masukkan Nilai Barang: ";
                    } while (!validasiInputDouble(nilai_barang));  

                    tambahBarangKeStack(&stack, nama_barang, kategori_barang, jumlah_barang, nilai_barang);
                } else if (pilihan_stack == 2) {
                    hapusBarangDariStack(&stack);
                } else if (pilihan_stack == 3) {
                    tampilkanDaftarBarang(stack);
                } else if (pilihan_stack == 4) {
                    urutkanStackDescending(&stack);
                } else if (pilihan_stack == 5) {
                    int jumlah_dicari;
                    cout << "Masukkan jumlah barang yang dicari: ";
                    cin >> jumlah_dicari;
                    cariJumlahBarangDenganFibonacci(stack, jumlah_dicari);
                } else if (pilihan_stack == 6) {
                    int jumlah_dicari;
                    cout << "Masukkan jumlah barang yang dicari: ";
                    cin >> jumlah_dicari;
                    cariJumlahBarangDenganJump(stack, jumlah_dicari);
                } else if (pilihan_stack == 7) {
                    string nama_dicari;
                    cout << "Masukkan nama barang yang dicari: ";
                    cin >> nama_dicari;
                    cariNamaBarangDenganBoyerMoore(stack, nama_dicari);
                }
                this_thread::sleep_for(chrono::milliseconds(2000)); 
            } while (pilihan_stack != 8);
        } else if (pilihan_menu == 2) {
            int pilihan_queue;
            do {
                clearConsole(); 
                cout << "\n=== Menu Queue ===" << endl;
                cout << "1. Tambah Barang ke Queue" << endl; 
                cout << "2. Hapus Barang dari Queue" << endl; 
                cout << "3. Tampilkan Daftar Barang di Queue" << endl;
                cout << "4. Urutkan Queue secara Ascending" << endl;
                cout << "5. Kembali ke Menu Utama" << endl;
                cout << "Pilih menu: ";
                cin >> pilihan_queue;

                if (pilihan_queue == 1) {
                    string nama_barang, kategori_barang;
                    int jumlah_barang;
                    double nilai_barang;
                    cout << "Masukkan Nama Barang: ";
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');   
                    getline(cin, nama_barang);  
                    cout << "Masukkan Kategori: ";
                    getline(cin, kategori_barang);  


                    do {
                        cout << "Masukkan Jumlah: ";
                    } while (!validasiInputInt(jumlah_barang));

                    do {
                        cout << "Masukkan Nilai Barang: ";
                    } while (!validasiInputDouble(nilai_barang));

                    tambahBarangKeQueue(&queue_awal, &queue_akhir, nama_barang, kategori_barang, jumlah_barang, nilai_barang);
                } else if (pilihan_queue == 2) {
                    hapusBarangDariQueue(&queue_awal);
                } else if (pilihan_queue == 3) {
                    tampilkanDaftarBarang(queue_awal);
                } else if (pilihan_queue == 4) {
                    urutkanQueueAscending(&queue_awal);
                }
                this_thread::sleep_for(chrono::milliseconds(2000)); 
            } while (pilihan_queue != 5);
        }
    } while (pilihan_menu != 3);

    bersihkanMemori(&stack);  
    bersihkanMemori(&queue_awal);  
    cout << "Program selesai!" << endl;
    return 0;
}

void clearConsole() {
    system("cls"); 
}

bool validasiInputInt(int& input) {
    cin >> input;
    if (cin.fail() || input < 0) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        cout << "Input tidak valid! Masukkan angka positif." << endl;
        return false;
    }
    return true;
}

bool validasiInputDouble(double& input) {
    cin >> input;
    if (cin.fail() || input < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Input tidak valid! Masukkan nilai positif." << endl;
        return false;
    }
    return true;
}

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
        cout << "Error: Stack kosong, tidak ada barang untuk dihapus!" << endl;
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
        cout << "Error: Queue kosong, tidak ada barang untuk dihapus!" << endl;
        return;
    }
    Node* node_sementara = *pointer_awal;
    *pointer_awal = node_sementara->node_berikutnya;
    delete node_sementara;
    cout << "Barang berhasil dihapus dari Queue!" << endl;
}

void tampilkanDaftarBarang(Node* pointer_awal) {
    if (pointer_awal == nullptr) {
        cout << "Daftar barang kosong." << endl;
        return;
    }
    Node* temp = pointer_awal;
    int index = 1;
    while (temp != nullptr) {
        cout << index++ << ". Nama Barang: " << temp->data_barang.nama_barang
             << ", Kategori: " << temp->data_barang.kategori
             << ", Jumlah: " << temp->data_barang.jumlah
             << ", Nilai Barang: " << temp->data_barang.nilai_barang << endl;
        temp = temp->node_berikutnya;
    }
}

Node* ambilNodeTerakhir(Node* head) {
    while (head && head->node_berikutnya != nullptr) {
        head = head->node_berikutnya;
    }
    return head;
}

Node* partition(Node* start, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr, *cur = start, *tail = pivot;

    while (cur != pivot) {
        if (cur->data_barang.jumlah > pivot->data_barang.jumlah) { 
            if ((*newHead) == nullptr) (*newHead) = cur;
            prev = cur;
            cur = cur->node_berikutnya;
        } else {
            if (prev) prev->node_berikutnya = cur->node_berikutnya;
            Node* temp = cur->node_berikutnya;
            cur->node_berikutnya = nullptr;
            tail->node_berikutnya = cur;
            tail = cur;
            cur = temp;
        }
    }

    if ((*newHead) == nullptr) (*newHead) = pivot;
    (*newEnd) = tail;

    return pivot;
}

Node* quickSortRecur(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node* newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);

    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->node_berikutnya != pivot) temp = temp->node_berikutnya;
        temp->node_berikutnya = nullptr;

        newHead = quickSortRecur(newHead, temp);
        temp = ambilNodeTerakhir(newHead);
        temp->node_berikutnya = pivot;
    }

    pivot->node_berikutnya = quickSortRecur(pivot->node_berikutnya, newEnd);
    return newHead;
}

void urutkanStackDescending(Node** headRef) {
    *headRef = quickSortRecur(*headRef, ambilNodeTerakhir(*headRef));
    cout << "Stack berhasil diurutkan secara descending berdasarkan jumlah barang!" << endl;
}

void urutkanQueueAscending(Node** head) {
    if (*head == nullptr) return;

    Node* temp = *head;
    vector<Node*> nodes;

    while (temp != nullptr) {
        nodes.push_back(temp);
        temp = temp->node_berikutnya;
    }

    sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
        return a->data_barang.jumlah < b->data_barang.jumlah; 
    });

    *head = nodes[0];
    for (size_t i = 1; i < nodes.size(); ++i) {
        nodes[i - 1]->node_berikutnya = nodes[i];
    }
    nodes.back()->node_berikutnya = nullptr;

    cout << "Queue berhasil diurutkan secara ascending berdasarkan jumlah barang!" << endl;
}

int hitungJumlahNode(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->node_berikutnya;
    }
    return count;
}

void bersihkanMemori(Node** pointer_awal) {
    while (*pointer_awal != nullptr) {
        Node* temp = *pointer_awal;
        *pointer_awal = (*pointer_awal)->node_berikutnya;
        delete temp;
    }
}

int fibonacciSearch(int arr[], int n, int x) {
    int fib2 = 0; 
    int fib1 = 1;
    int fib = fib2 + fib1; 

    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }

    int offset = -1;

    while (fib > 1) {
        int i = min(offset + fib2, n - 1);

        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else {
            return i;
        }
    }

    if (fib1 && arr[offset + 1] == x)
        return offset + 1;

    return -1;
}

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) return -1;
    }

    if (arr[prev] == x) return prev;

    return -1;
}

vector<int> buildBadCharTable(const string& pattern) {
    int m = pattern.size();
    vector<int> badChar(256, -1);

    for (int i = 0; i < m; i++) {
        badChar[pattern[i]] = i;
    }

    return badChar;
}

int boyerMooreSearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m == 0) return -1;

    vector<int> badChar = buildBadCharTable(pattern);

    int shift = 0;
    while (shift <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[shift + j])
            j--;

        if (j < 0) {
            return shift; 
        } else {
            shift += max(1, j - badChar[text[shift + j]]);
        }
    }

    return -1; 
}

void cariJumlahBarangDenganFibonacci(Node* head, int jumlah_dicari) {
    int n = hitungJumlahNode(head); 
    int* jumlah_barang_array = new int[n];
    
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        jumlah_barang_array[i] = temp->data_barang.jumlah;
        temp = temp->node_berikutnya;
    }

    int result = fibonacciSearch(jumlah_barang_array, n, jumlah_dicari);
    if (result != -1) {
        cout << "Barang dengan jumlah " << jumlah_dicari << " ditemukan pada indeks ke-" << result << "." << endl;
    } else {
        cout << "Barang dengan jumlah " << jumlah_dicari << " tidak ditemukan." << endl;
    }

    delete[] jumlah_barang_array;
}

void cariJumlahBarangDenganJump(Node* head, int jumlah_dicari) {
    int n = hitungJumlahNode(head); 
    int* jumlah_barang_array = new int[n];
    
    Node* temp = head;
    for (int i = 0; i < n; i++) {
        jumlah_barang_array[i] = temp->data_barang.jumlah;
        temp = temp->node_berikutnya;
    }

    int result = jumpSearch(jumlah_barang_array, n, jumlah_dicari);
    if (result != -1) {
        cout << "Barang dengan jumlah " << jumlah_dicari << " ditemukan pada indeks ke-" << result << "." << endl;
    } else {
        cout << "Barang dengan jumlah " << jumlah_dicari << " tidak ditemukan." << endl;
    }

    delete[] jumlah_barang_array;
}

void cariNamaBarangDenganBoyerMoore(Node* head, string nama_dicari) {
    Node* temp = head;
    int index = 0;

    while (temp != nullptr) {
        string nama_barang = temp->data_barang.nama_barang;
        int result = boyerMooreSearch(nama_barang, nama_dicari);
        if (result != -1) {
            cout << "Nama barang yang dicari ditemukan pada indeks ke-" << index << "." << endl;
            return;
        }
        index++;
        temp = temp->node_berikutnya;
    }

    cout << "Nama barang yang dicari tidak ditemukan." << endl;
}
