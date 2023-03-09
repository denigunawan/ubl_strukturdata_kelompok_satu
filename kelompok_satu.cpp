#include <iostream>
#include <vector>

using namespace std;

// field on data mahasiswa
struct Mahasiswa{
    string nim;
    string nama;
    string jurusan;
};

// field on data matakuliah
struct MataKuliah{
    string kode_matakuliah;
    string nama_matakuliah;
    string bobot_sks;
};

// field input nilai mahasiswa
struct Nilai{
    int  uts;
    int  tugas;
    int  uas;
    int  nilai_akhir;
    char  grade;
};




string center(string text, int width) {
    int len = text.length();
    int margin = (width - len) / 2;
    string result = string(margin, ' ') + text + string(margin, ' ');
    if (result.length() < width) {
        result += string(width - result.length(), ' ');
    }
    return result;
}
void addDataMataKuliah(vector<MataKuliah> list_matakuliah){
    MataKuliah matakuliah;
    char pilihan;
    do{
        cout <<"===================================\n";
        cout <<center("INPUT DATA MATAKULIAH\n", 30) <<endl;
        cout << "==================================\n";
        cout << "Kode MataKuliah = ";
        cin >> matakuliah.kode_matakuliah;
        cout << "Nama MataKuliah = ";
        cin >> matakuliah.nama_matakuliah;
        cout << "Bobot SKS = ";
        cin >> matakuliah.bobot_sks;
        cout << "=====Succesfully Add Data Mata Kuliah====\n";
        for (int i = 0; i < list_matakuliah.size(); i++) {
        cout << "Kode MataKuliah: " << list_matakuliah[i].kode_matakuliah << endl;
        cout << "Nama MataKuliah: " << list_matakuliah[i].nama_matakuliah << endl;
        cout << "Bobot SKS: " << list_matakuliah[i].bobot_sks << endl;
        cout << "==============================\n";
    }

        cout << "Pilih X Untuk Kembali ke Menu Utama" << endl;
        cin>> pilihan;
        list_matakuliah.push_back(matakuliah);
    } while(pilihan != 'X' && pilihan != 'x' );
}

// method data mahasiswa
void addDataMahasiswa(vector<Mahasiswa> list_mahasiswa){
    // inisialisasi variable
    Mahasiswa mahasiswa;
    char pilihan;
    do {
    cout <<"========================================\n";
    cout <<center("INPUT DATA MAHASISWA\n", 30) <<endl;
    cout << "=======================================\n";
    cout << "NIM =  ";
    cin >> mahasiswa.nim;
    cout << "NAMA = ";
    cin >> mahasiswa.nama;
    cout <<"JURUSAN = ";
    cin >> mahasiswa.jurusan;
    cout << "=====Succesfully Add Data Mahasiswa====\n";
    cout << "Pilih X Untuk Kembali ke Menu Utama" << endl;
    cin >> pilihan;
    list_mahasiswa.push_back(mahasiswa);
    } while(pilihan != 'X' && pilihan != 'x' );
}

void addNilai(vector<Nilai> list_data_nilai){
        Nilai data_nilai;
        char pilihan;
        do {
        cout<<"================================\n"<<endl;
        cout<<center("INPUT NILAI\n", 30) <<endl;
        cout<<"================================\n"<<endl;
        cout << "Input Nilai UTS = ";
        cin >> data_nilai.uts;
        cout << "Input Nilai TUGAS = ";
        cin >> data_nilai.tugas;
        cout << "Input Nilai UAS = ";
        cin >> data_nilai.uas;
        // calculate
        data_nilai.nilai_akhir = 0.3 * data_nilai.uts + 0.3 * data_nilai.tugas + 0.4 * data_nilai.uas;
        cout << "Nilai Akhir : " << data_nilai.nilai_akhir << endl;
        if(data_nilai.nilai_akhir >= 85 && data_nilai.nilai_akhir <= 100 ){
            data_nilai.grade = 'A';
        } else if (data_nilai.nilai_akhir >= 75 && data_nilai.nilai_akhir < 85){
            data_nilai.grade = 'B';
        } else if (data_nilai.nilai_akhir >= 60 && data_nilai.nilai_akhir < 75){
            data_nilai.grade = 'C';
        } else if (data_nilai.nilai_akhir >= 40 && data_nilai.nilai_akhir < 60){
            data_nilai.grade = 'D';
        }else{
            data_nilai.grade = 'E';
        }
        cout << "Grade : " << data_nilai.grade << endl;
        cout << "=====Succesfully Input Nilai Mahasiswa====\n";
        cout << "Pilih X Untuk Kembali ke Menu Utama" << endl;
        cin >> pilihan;
        list_data_nilai.push_back(data_nilai);
    } while(pilihan != 'X' && pilihan != 'x' );
}


int main(){
    vector<MataKuliah> list_matakuliah;
    vector<Mahasiswa> list_mahasiswa;
    vector<Nilai> list_nilai;
    int pilihan_menu;
    do {
    cout<<"================================\n"<<endl;
    cout<<"KELOMPOK 1 - Deni Gunawan (2211601576)"<<endl;
    cout<<"           - Dian Erdiansyah (2211601543)"<<endl;
    cout<<"           - Budi Prasetya (2211601535)"<<endl;
    cout<<"================================\n"<<endl;
    cout<<center("PROGRAM DATA NILAI\n", 30) <<endl;
    cout<<"================================\n"<<endl;
    cout<<"1. Input Mahasiswa"<<endl;
    cout<<"2. Input Matakuliah"<<endl;
    cout<<"3. Input Nilai Mahasiswa"<<endl;
    cout<<"4. Cetak Daftar Nilai Mahasiswa\n"<<endl;
    cout<<"================================\n"<<endl;
    cout<<"Masukkan Pilihan [1..4]:....\n"<<endl;
	cout<<"================================\n"<<endl;
	cin >> pilihan_menu;

	switch(pilihan_menu){
    case 1:
        addDataMahasiswa(list_mahasiswa);
        break;
    case 2:
        addDataMataKuliah(list_matakuliah);
        break;
    case 3:
        addNilai(list_nilai);
    default:
        cout << "Pilihan Tidak Tersedia." << endl;
        break;
	 }
    } while (pilihan_menu != 'X' && pilihan_menu != 'x');
    return 0;
}
