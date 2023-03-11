#include <iostream>
#include <vector>
#include <iomanip>


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

    string getNim() const {
        return nim;
    }
    void setNim(const string& nim) {
        this->nim = nim;
    }
    string getNama() const {
        return nama;
    }
    void setNama(const string& nama) {
        this->nama = nama;
    }
    string getJurusan() const {
        return jurusan;
    }
    void setJurusan(const string& jurusan) {
        this->jurusan = jurusan;
    }
};

// field on data matakuliah
struct MataKuliah{
    int no;
    string kode_matakuliah;
    string nama_matakuliah;
    int bobot_sks;

    void setKodeMatakuliah(const string& kode_matakuliah){
        this->kode_matakuliah = kode_matakuliah;
    }

    void setNamaMatakuliah(const string& nama_matakuliah){
        this->nama_matakuliah = nama_matakuliah;
    }

    void setBobotSks(const int& bobot_sks){
        this->bobot_sks = bobot_sks;
    }

    string getKodeMatakuliah() const {
        return kode_matakuliah;
    }

    string getNamaMatakuliah() const {
    return nama_matakuliah;
    }

    int getBobotSks() const{
        return bobot_sks;
    }
};

// field input nilai mahasiswa
struct Nilai {
    int no;
    int  uts;
    int  tugas;
    int  uas;
    int  nilai_akhir;
    char  grade;

      // Getter untuk atribut uts
    int getUts() const {
        return uts;
    }

    // Setter untuk atribut uts
    void setUts(int newUts) {
        uts = newUts;
    }

    // Getter untuk atribut tugas
    int getTugas() const {
        return tugas;
    }

    // Setter untuk atribut tugas
    void setTugas(int newTugas) {
        tugas = newTugas;
    }

    // Getter untuk atribut uas
    int getUas() const {
        return uas;
    }

    // Setter untuk atribut uas
    void setUas(int newUas) {
        uas = newUas;
    }

    // Getter untuk atribut nilai_akhir
    int getNilaiAkhir() const {
        return nilai_akhir;
    }

    // Setter untuk atribut nilai_akhir
    void setNilaiAkhir(int newNilaiAkhir) {
        nilai_akhir = newNilaiAkhir;
    }

    // Getter untuk atribut grade
    char getGrade() const {
        return grade;
    }

    // Setter untuk atribut grade
    void setGrade(char newGrade) {
        grade = newGrade;
    }

};


void displayDataMataKuliah(vector<MataKuliah>& list_matakuliah){
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

void displayDataMahasiswa(vector<Mahasiswa>& list_mahasiswa){
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

void addDataMahasiswa(vector<Mahasiswa>& list_mahasiswa){
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
    cout <<"JURUSAN                             = ";
    cin >> mahasiswa.jurusan;
    cout << "Pilih X Untuk Kembali ke Menu Utama" << endl;
    cout<<"======================================\n"<<endl;
    cin >> pilihan;
    list_mahasiswa.push_back(mahasiswa);
    displayDataMahasiswa(list_mahasiswa);
    } while(pilihan != 'X' && pilihan != 'x' );
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
        displayDataMataKuliah(list_matakuliah);
    } while(pilihan != 'X' && pilihan != 'x' );
}

void addNilai(vector<Nilai>& list_data_nilai, vector<Mahasiswa>& list_mahasiswa, vector<MataKuliah>& list_matakuliah){
        Nilai data_nilai;
        Mahasiswa mahasiswa;
        MataKuliah matakuliah;
        char pilihan;
        do {
        cout<<"================================\n"<<endl;
        cout<<center("INPUT NILAI\n", 30) <<endl;
        cout<<"================================\n"<<endl;
        data_nilai.no = list_data_nilai.size() + 1;
        cout << "Input Nilai Mahasiswa(dibuat otomatis)    = " << data_nilai.no << endl;
        string nim;
        cout << "Input NIM                                 = ";
        cin >> nim;
        bool found_mahasiswa = false;
        string nama_mahasiswa, jurusan_mahasiswa;
        for (Mahasiswa mahasiswa : list_mahasiswa) {
            if (mahasiswa.nim == nim) {
                found_mahasiswa = true;
                nama_mahasiswa = mahasiswa.nama;
                jurusan_mahasiswa = mahasiswa.jurusan;
                break;
            }
        }
        if (!found_mahasiswa) {
            cout << "Mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
            continue;
        }
        cout << "Nama                                      = " << nama_mahasiswa << endl;
        cout << "Jurusan                                   = " << jurusan_mahasiswa << endl;
        string kode_matakuliah;
        cout << "Input Kode Matakuliah                     = ";
        cin >> kode_matakuliah;
        bool found_matakuliah = false;
        string nama_matakuliah;
        int bobot_sks = 0;
        for (MataKuliah matakuliah : list_matakuliah) {
            if (matakuliah.kode_matakuliah == kode_matakuliah) {
                found_matakuliah = true;
                nama_matakuliah = matakuliah.nama_matakuliah;
                bobot_sks = matakuliah.bobot_sks;
                break;
            }
        }
        if (!found_matakuliah) {
            cout << "Matakuliah dengan kode " << kode_matakuliah << " tidak ditemukan." << endl;
            continue;
        }
        cout << "Nama Matakuliah                           = " << nama_matakuliah << endl;
        cout << "Bobot SKS                                 = " << bobot_sks << endl;
        cout << "Input Nilai UTS                           = ";
        cin >> data_nilai.uts;
        cout << "Input Nilai TUGAS                         = ";
        cin >> data_nilai.tugas;
        cout << "Input Nilai UAS                           = ";
        cin >> data_nilai.uas;
        // calculate
        data_nilai.nilai_akhir = 0.3 * data_nilai.uts + 0.3 * data_nilai.tugas + 0.4 * data_nilai.uas;
        cout << "Nilai Akhir                               = " << data_nilai.nilai_akhir << endl;
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
        cout << "Grade                                     = " << data_nilai.grade << endl;
        cout << "Pilih X Untuk Kembali ke Menu Utama" << endl;
        cout<<"======================================\n"<<endl;
        cin >> pilihan;
        list_data_nilai.push_back(data_nilai);
        displayDataNilai(list_data_nilai);
    } while(pilihan != 'X' && pilihan != 'x' );
}


void cetakAllData(vector<Mahasiswa>& list_mahasiswa, vector<MataKuliah>& list_matakuliah, vector<Nilai>& list_nilai) {
    std::cout << "DATA NILAI MAHASISWA KELOMPOK 1" << std::endl;
    std::cout << "=====================================================================================" << std::endl;
    std::cout << std::setw(3) << "NO." << " | "
              << std::setw(7) << "NIM" << " | "
              << std::setw(14) << "NAMA" << " | "
              << std::setw(8) << "JURUSAN" << " | "
              << std::setw(9) << "KODE MTK" << " | "
              << std::setw(14) << "NAMA MTK" << " | "
              << std::setw(3) << "SKS" << " | "
              << std::setw(3) << "UTS" << " | "
              << std::setw(4) << "TUGAS" << " | "
              << std::setw(3) << "UAS" << " | "
              << std::setw(5) << "AKHIR" << " | "
              << std::setw(5) << "GRADE" << std::endl;
    std::cout << "=====================================================================================" << std::endl;
    for (int i = 0; i < list_mahasiswa.size(); i++) {
        MataKuliah mtk = list_matakuliah[i];
        Nilai nilai = list_nilai[i];
        std::cout << std::setw(3) << i+1 << " | "
                  << std::setw(7) << list_mahasiswa[i].getNim() << " | "
                  << std::setw(14) << list_mahasiswa[i].getNama() << " | "
                  << std::setw(8) << list_mahasiswa[i].getJurusan() << " | "
                  << std::setw(9) << mtk.getKodeMatakuliah() << " | "
                  << std::setw(14) << mtk.getNamaMatakuliah() << " | "
                  << std::setw(3) << mtk.getBobotSks() << " | "
                  << std::setw(3) << nilai.getUts() << " | "
                  << std::setw(4) << nilai.getTugas() << " | "
                  << std::setw(3) << nilai.getUas() << " | "
                  << std::setw(5) << nilai.getNilaiAkhir() << " | "
                  << std::setw(5) << nilai.getGrade() << std::endl;
    std::cout << "=====================================================================================" << std::endl;
}
}

int main(){
vector<Mahasiswa> list_mahasiswa;
vector<MataKuliah> list_matakuliah;
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
        addNilai(list_nilai, list_mahasiswa, list_matakuliah);
        break;
    case 4:
        cetakAllData(list_mahasiswa, list_matakuliah, list_nilai);
    default:
        cout << "Pilihan Tidak Tersedia." << endl;
        break;
	 }
    } while (pilihan_menu != 'X' && pilihan_menu != 'x');
    return 0;
}
