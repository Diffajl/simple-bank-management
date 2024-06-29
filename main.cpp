#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int saldo = 0;
string pin_password = "";

void login();
void menu();
void cek_saldo();
void setor_tunai();
void tarik_tunai(int nominal);

int main()
{
    int pilihan, nominal;
    char lagi;
    
    login();
    
    while (true) {
        menu();
        
        cout << "Masukan Pilihan anda : ";
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                cek_saldo();
                break;
                
            case 2:
                setor_tunai();
                break;
                
            case 3:
                cout << "Masukan nominal yang ingin di tarik : ";
                cin >> nominal;
                tarik_tunai(nominal);
                break;
                
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        
        cout << "Apakah anda ingin mencoba lagi? (y / n) : ";
        cin >> lagi;
        
        if (lagi == 'n' || lagi == 'N') {
            break;
        } else {
            system("clear");
        }
    }
    
    return 0;
}

void login() {
    string nama, pin;
    cout << "+-----------------------------------------------+" << endl;
    cout << "|    Selamat Datang Di Sistem Manajemen Bank    |" << endl;
    cout << "+-----------------------------------------------+" << endl;
    
    cout << "Masukan nama anda : ";
    cin >> nama;
    cout << "Masukan Pin Anda : ";
    cin >> pin;
    
    pin_password += pin;
    
    cout << "\nBerhasil login sebagai " << nama << endl;
    this_thread::sleep_for(chrono::seconds(1));
    
    system("clear");
}

void menu() {
    cout << "+------------------------------+" << endl;
    cout << "|          Pilih menu          |" << endl;
    cout << "+------------------------------+" << endl;
    cout << "|       1. Lihat Saldo         |" << endl;
    cout << "|       2. Setor Tunai         |" << endl;
    cout << "|       3. Tarik Tunai         |" << endl;
    cout << "+------------------------------+" << endl;
}

void cek_saldo() {
    cout << "Saldo anda sekarang adalah : " << saldo << endl;
    this_thread::sleep_for(chrono::seconds(1));
}

void setor_tunai() {
    int nominal;
    string pin;
    cout << "Masukan nominal yang ingin anda setor : ";
    cin >> nominal;
    cout << "Masukan pin anda : ";
    cin >> pin;
    if (pin == pin_password) {
        saldo += nominal;    
        cout << "Berhasil setor tunai sebesar " << nominal << ", Saldo anda sekarang adalah " << saldo << endl;
        this_thread::sleep_for(chrono::seconds(1));
    } else {
        cout << "Pin anda salah!" << endl;
    }
}

void tarik_tunai(int nominal) {
    string pin;
    if (nominal > saldo) {
        cout << "Saldo anda tidak mencukupi!" << endl;
    } else {
        cout << "Masukan pin anda : ";
        cin >> pin;
        
        if (pin == pin_password) {
            saldo -= nominal;
            cout << "Berhasil menarik tunai sebesar " << nominal << ", Saldo anda sekarang : " << saldo << endl; 
        } else {
            cout << "Pin anda salah!" << endl;
        }
        
    }
}
