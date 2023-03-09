#include <iostream>
#include <vector>

using namespace std;


string center(string text, int width) {
    int len = text.length();
    int margin = (width - len) / 2;
    string result = string(margin, ' ') + text + string(margin, ' ');
    if (result.length() < width) {
        result += string(width - result.length(), ' ');
    }
    return result;
}

// field on data mahasiswa
struct Mahasiswa{
    int no;
    string nim;
    string nama;
    string jurusan;
};

// field on data matakuliah
struct MataKuliah{
    int no;
    string kode_matakuliah;
    string nama_matakuliah;
    string bobot_sks;
};

// field input nilai mahasiswa
struct Nilai {
    int no;
    int  uts;
    int  tugas;
    int  uas;
    int  nilai_akhir;
    char  grade;
};



void displayDataMataKuliah(vector<MataKuliah> list_matakuliah){
    cout << "==================================\n";
    cout << center("DATA MATA KULIAH\n", 30) <<endl;
    cout << "==================================\n";
    cout << "No|Kode Mata Kuliah|Nama Mata Kuliah|Bobot SKS\n";
    cout << "==================================\n";
    for (int i = 0; i < list_matakuliah.size(); i++){
        cout << i+1 << "\t" << list_matakuliah[i].kode_matakuliah << "\t\t" << list_matakuliah[i].nama_matakuliah << "\t\t" << list_matakuliah[i].bobot_sks << endl;
    }
    cout << endl;
}

void displayDataMahasiswa(vector<Mahasiswa> list_mahasiswa){
    cout << "==================================\n";
    cout << center("DATA MAHASISWA\n", 30) <<endl;
    cout << "==================================\n";
    cout << "No|\tNIM |\tNAMA |\tJURUSAN\n";
    cout << "==================================\n";
    for (int i = 0; i < list_mahasiswa.size(); i++){
        cout << i+1 << "\t" << list_mahasiswa[i].nim << "\t" << list_mahasiswa[i].nama << "\t" << list_mahasiswa[i].jurusan << endl;
    }
    cout << endl;
}


void displayDataNilai(vector<Nilai> list_nilai){
    cout << "==================================\n";
    cout << center("DATA NILAI MAHASISWA\n", 30) <<endl;
    cout << "==================================\n";
    cout << "No|\tUTS|\tTUGAS|\tUAS|\tNILAI AKHIR|\tGRADE\n";
    cout << "==================================\n";
    for (int i = 0; i < list_nilai.size(); i++){
        cout << i+1 << "\t" << list_nilai[i].uts << "\t" << list_nilai[i].tugas << "\t" << list_nilai[i].uas<< "\t" << list_nilai[i].nilai_akhir<< "\t\t" << list_nilai[i].grade << endl;
    }
    cout << endl;
}



void addDataMataKuliah(vector<MataKuliah>& list_matakuliah){
    MataKuliah matakuliah;
    char pilihan;
    do{
        cout <<center("INPUT DATA MATAKULIAH\n", 30) <<endl;
        cout << "==================================\n";
        matakuliah.no = list_matakuliah.size() + 1;
        cout << "Input matakuliah(dibuat otomatis)    = " << matakuliah.no << endl;
        cout << "Kode MataKuliah    = ";
        cin >> matakuliah.kode_matakuliah;
        cout << "Nama MataKuliah    = ";
        cin >> matakuliah.nama_matakuliah;
        cout << "Bobot SKS          = ";
        cin >> matakuliah.bobot_sks;
        cout << "Pilih X Untuk Kembali ke Menu Utama" << endl;
        cout<<"======================================\n"<<endl;
        cin>> pilihan;
        list_matakuliah.push_back(matakuliah);
        displayDataMataKuliah(list_matakuliah); // menampilkan data terbaru
    } while(pilihan != 'X' && pilihan != 'x' );
}



// method data mahasiswa
void addDataMahasiswa(vector<Mahasiswa> list_mahasiswa){
    // inisialisasi variable
    Mahasiswa mahasiswa;
    char pilihan;
    do {
    cout <<center("INPUT DATA MAHASISWA\n", 30) <<endl;
    cout << "=======================================\n";
    mahasiswa.no = list_mahasiswa.size() + 1;
    cout << "Input Mahasiswa(dibuat otomatis)    = " << mahasiswa.no << endl;
    cout << "NIM                                 = ";
    cin >> mahasiswa.nim;
    cout << "NAMA                                = ";
    cin >> mahasiswa.nama;
    cout <<"JURUSAN                             SI= ";
    cin >> mahasiswa.jurusan;
    cout << "Pilih X Untuk Kembali ke Menu Utama" << endl;
    cout<<"======================================\n"<<endl;
    cin >> pilihan;
    list_mahasiswa.push_back(mahasiswa);
    displayDataMahasiswa(list_mahasiswa);
    } while(pilihan != 'X' && pilihan != 'x' );
}

void addNilai(vector<Nilai> list_data_nilai){
        Nilai data_nilai;
        char pilihan;
        do {
        cout<<"================================\n"<<endl;
        cout<<center("INPUT NILAI\n", 30) <<endl;
        cout<<"================================\n"<<endl;
        data_nilai.no = list_data_nilai.size() + 1;
        cout << "Input Nilai Mahasiswa(dibuat otomatis)    = " << data_nilai.no << endl;
        cout << "Input Nilai UTS    = ";
        cin >> data_nilai.uts;
        cout << "Input Nilai TUGAS  = ";
        cin >> data_nilai.tugas;
        cout << "Input Nilai UAS    = ";
        cin >> data_nilai.uas;
        // calculate
        data_nilai.nilai_akhir = 0.3 * data_nilai.uts + 0.3 * data_nilai.tugas + 0.4 * data_nilai.uas;
        cout << "Nilai Akhir        = " << data_nilai.nilai_akhir << endl;
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
        cout << "Grade              = " << data_nilai.grade << endl;
        cout << "Pilih X Untuk Kembali ke Menu Utama" << endl;
        cout<<"======================================\n"<<endl;
        cin >> pilihan;
        list_data_nilai.push_back(data_nilai);
        displayDataNilai(list_data_nilai);
    } while(pilihan != 'X' && pilihan != 'x' );
}
struct CetakData{
    int no;
    Mahasiswa mahasiswa;
    Nilai nilai;
    MataKuliah matakuliah;
};

void printData(vector<CetakData>& list_data) {
    for (auto& d : list_data) {
        cout << "NO. " << d.no << " | NIM: " << d.mahasiswa.nim << " | NAMA: " << d.mahasiswa.nama
             << " | JURUSAN: " << d.mahasiswa.jurusan << " | KODE MTK: " << d.matakuliah.kode_matakuliah
             << " | NAMA MTK: " << d.matakuliah.nama_matakuliah << " | SKS: " << d.matakuliah.bobot_sks
             << " | UTS: " << d.nilai.uts << " | TUGAS: " << d.nilai.tugas << " | UAS: " << d.nilai.uas << endl;
    }
}


int main(){
    vector<MataKuliah> list_matakuliah;
    vector<Mahasiswa> list_mahasiswa;
    vector<Nilai> list_nilai;
    vector<CetakData> list_cetak;
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
