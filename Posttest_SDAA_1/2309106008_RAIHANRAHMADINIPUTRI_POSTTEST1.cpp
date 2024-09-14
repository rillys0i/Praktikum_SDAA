#include <iostream>
using namespace std;

int hitungNilaiPascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return hitungNilaiPascal(baris - 1, kolom - 1) + hitungNilaiPascal(baris - 1, kolom);
    }
}

void cetakSegitigaPascal(int tinggisegitiga) {
    for (int baris = 0; baris < tinggisegitiga; baris++) {
        for (int kolom = 0; kolom <= baris; kolom++) {
            cout << hitungNilaiPascal(baris, kolom) << " ";
        }
        cout << endl;
    }
}

int main() {
    int tinggisegitiga = 3; 
    cout << "Segitiga Pascal dengan " << tinggisegitiga << " tingkat berbentuk segitiga siku-siku:" << endl;
    cetakSegitigaPascal(tinggisegitiga);
    
    return 0;
}
