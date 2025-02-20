#include <iostream>
#include <string>
using namespace std;

struct rekening {
    string namaPemilik;
    string noRek;
    int saldo;
    string pin;
};

rekening user[10] = {
            {"ari", "111666", 1000000, "123465"},
            {"budi", "121626", 5000000, "616289"},
            {"cindy", "123716", 600000, "711197"},
            {"dani", "613244", 50000, "853178"},
            {"edo", "715643", 150000, "312465"},
            {"farah", "715690", 1750000, "600890"},
            {"guntur", "413224", 5000000, "808088"},
            {"hanif", "415672", 2500000, "111101"},
            {"irfan", "818563", 650000, "007690"},
            {"jeremy", "116588", 150000, "144150"}
};

void menuid() {
    cout << "+=========Mesin ATM==========+" << endl;
    cout << "| 1. Informasi Saldo         |" << endl;
    cout << "| 2. Tarik Tunai             |" << endl;
    cout << "| 3. Transfer                |" << endl;
    cout << "| 0. Keluar                  |" << endl;
    cout << "+============================+" << endl;
    cout << "Pilih Menu : ";
}

void menuEng() {
    cout << "+=============ATM===========+" << endl;
    cout << "| 1. Balance Information    |" << endl;
    cout << "| 2. Cash Withdrawal        |" << endl;
    cout << "| 3. Transfer               |" << endl;
    cout << "| 0. Exit                   |" << endl;
    cout << "+===========================+" << endl;
    cout << "Choose Menu : ";
}

int cariRek(rekening akun[], int jumRek, string nomor, string pin) {
    for (int i = 0; i < jumRek; i++) {
        if (akun[i].noRek == nomor && akun[i].pin == pin) {
            return i;
        }
    }
    return -1;
}

void tarikTunaiID(int indeks) {
    int tarTun;
    cout << "Masukkan jumlah uang yang ingin ditarik: ";
    cin >> tarTun;
    if (tarTun > user[indeks].saldo) {
        cout << "Saldo tidak mencukupi." << endl;
    }
    else {
        user[indeks].saldo -= tarTun;
        cout << "Penarikan berhasil! Saldo Anda sekarang: Rp" << user[indeks].saldo << endl;
    }
}

void tarikTunaiEng(int indeks) {
    int tarTun;
    cout << "Enter the amount you want to withdraw: ";
    cin >> tarTun;
    if (tarTun > user[indeks].saldo) {
        cout << "Insufficient balance." << endl;
    }
    else {
        user[indeks].saldo -= tarTun;
        cout << "Withdrawal successful! Your balance now: Rp" << user[indeks].saldo << endl;
    }
}

void TransferId (int indeks) {
    int transferinput;
    string tujuan;
    cout << "Masukkan nomor rekening tujuan: ";
    cin >> tujuan;
    cout << "Masukkan jumlah yang ingin ditransfer: ";
    cin >> transferinput;   

    if (tujuan != user[indeks].noRek) {
        cout << "Nomor rekening tujuan salah." << endl;
    }
    else{
        if (transferinput > user[indeks].saldo) {
            cout << "Saldo tidak mencukupi." << endl;
        } 
        else {
            user[indeks].saldo -= transferinput;
            int sisa = user[indeks].saldo;
            cout << "Transfer berhasil. Sisa saldo Anda: Rp" << sisa << endl;

        }
    }
    
    for(int i = 0; i < 10; i++) {
        if (user[i].noRek == tujuan) {
            user[i].saldo += transferinput;
        }
    }
}

void TransferEng (int indeks) {
    int transferinput;
    string tujuan;
    cout << "Enter target account number: ";
    cin >> tujuan;
    cout << "Enter the amount to transfer: ";
    cin >> transferinput;   

    if (tujuan != user[indeks].noRek) {
        cout << "Target account number is incorrect." << endl;
    }
    else{
        if (transferinput > user[indeks].saldo) {
            cout << "Insufficient balance." << endl;
        } 
        else {
            user[indeks].saldo -= transferinput;
            int sisa = user[indeks].saldo;
            cout << "Transfer successful. Your remaining balance: Rp" << sisa << endl;
        }
    }
    for(int i = 0; i < 10; i++) {
        if (user[i].noRek == tujuan) {
            user[i].saldo += transferinput;
        }
    }
}


int main() {
    int jumRek = 10;
    char lagi;
    string noRek, pin;
    int indeks;
    int percobaan = 0;
        
    do{
        cout << "Masukkan Rekening: ";
        cin >> noRek;
        cout << "Masukkan PIN: ";
        cin >> pin;

        while ((indeks = cariRek(user, jumRek, noRek, pin)) == -1) {
            percobaan++;
            if (percobaan >= 3) {
                cout << "Anda telah melakukan maksimal percobaan. Program akan keluar." << endl;
                return 0;
            }

            cout << "Nomor rekening atau PIN salah. Silakan coba lagi." << endl;
            cout << "Masukkan nomor rekening: ";
            cin >> noRek;
            cout << "Masukkan PIN: "; 
            cin >> pin;
        }

        cout << "Login berhasil. Selamat datang, " << user[indeks].namaPemilik << "!" << endl;

        int bhs;
        cout << "Pilih Bahasa/Choose language \n1. Bahasa Indonesia\n2. English"<<endl;
        cout << "Pilihlah/Choose : ";
        cin >> bhs;

        if (bhs == 1) {
            int pilihan;
            char ulang;
            do {
                system("cls");
                menuid();
                cin >> pilihan;

                switch (pilihan) {
                    case 1:
                        cout << "Saldo saat ini : Rp" << user[indeks].saldo << endl;
                        break;
                    case 2:
                        tarikTunaiID(indeks);
                        break;
                    case 3:
                        TransferId(indeks);
                        break;
                    case 0:
                        cout << "Terima kasih telah menggunakan layanan kami. Sampai jumpa!" << endl;
                        return 0;
                        break;
                    default:
                        cout << "\ntidak valid." << endl;
                        break;
                }


                cout << "Ingin melanjutkan (Y/N)? ";
                cin >> ulang;
            } while (ulang == 'Y' || ulang == 'y');

        } 
        else if (bhs == 2) {
            int pilihan;
            char ulang;
            do {
                system("cls");
                menuEng();
                cin >> pilihan;

                switch (pilihan) {
                    case 1:
                        cout << "current balance: Rp" << user[indeks].saldo << endl;
                        break;
                    case 2:
                        tarikTunaiEng(indeks);
                        break;
                    case 3:
                        TransferEng(indeks);
                        break;
                    case 0:
                        cout << "Thank you for using our services. See you later!" << endl;
                        return 0;
                        break;
                    default:
                        cout << "Invalid choice." << endl;
                        break;
                }

                cout << "Do you want to continue (Y/N)? ";
                cin >> ulang;
            } while (ulang == 'Y' || ulang == 'y');
        }
        
        cout<<"ingin cek rekening lagi (Y/N)? ";
        cin>>lagi;
        system("cls");
    }while(lagi=='Y' || lagi=='y');
    cout << "\n\n\tTerima kasih. / Thank you.\n\n" << endl;
    return 0;
}