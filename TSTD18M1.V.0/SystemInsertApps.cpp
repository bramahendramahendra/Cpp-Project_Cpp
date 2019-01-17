#include "HeaderApps.h"

void P_SystemInsertOrang(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"Silahkan isi Biodata peserta dibawah ini : "
            <<endl;

    //Bagian Input Data
    //auto insert ID
    GM.count_id_LO++;
    SS.IO.id  = GM.count_id_LO;

    cout<<"Masukkan Nama     : ";
    cin>>SS.IO.nama;
    cout<<endl;

    cout<<"Masukkan Alamat Peserta  : ";
    cin>>SS.IO.alamat;
    cout<<endl;

    cout<<"Masukkan Tanggal Lahir Peserta : ";
    cout<<endl;

    cout<<"Masukkan Tanggal : ";
    cin>>SS.IO.tanggal_lahir.tanggal;
    cout<<endl;

    cout<<"Masukkan Bulan   : ";
    cin>>SS.IO.tanggal_lahir.bulan;
    cout<<endl;

    cout<<"Masukkan Tahun   : ";
    cin>>SS.IO.tanggal_lahir.tahun;
    cout<<endl;
    //Batas Input Data

    //Bagian DLL
    SS.AO = F_AlokasiDLL(SS.IO);
    P_InsertFirstDLL(SS.LO, SS.AO);
    //Batas DLL

    //Kembali ke Menu sebelumnya stetlah Insert
    system("PAUSE");
}

void P_SystemInsertPendidikan(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"Silahkan isi Biodata pendidikan dibawah ini : "
            <<endl;

    //Bagian Input Data
    //auto insert ID
    GM.count_id_LP++;
    SS.IP.id  = GM.count_id_LP;

    cout<<"Masukkan Jenis     : ";
    cin>>SS.IP.jenis;
    cout<<endl;

    cout<<"Masukkan Kepoanjangan  : ";
    cin>>SS.IP.kepanjangan;
    cout<<endl;
    //Batas Input Data

    //Bagian SLL
    SS.AP = F_AlokasiSLL(SS.IP);
    P_InsertLastSLL(SS.LP, SS.AP);
    //Batas SLL

    //Kembali ke Menu sebelumnya stetlah Insert
    system("PAUSE");
}

void P_SystemInsertRiwayat(system_setting &SS,general_setting &GM)
{
    switch(GM.setting)
    {
        case 1 :
        {
            P_SystemInsertRiwayat1(SS,GM);
        }break;
        case 2:
        {
            P_SystemInsertRiwayat2(SS,GM);
        }break;
        case 3:
        {
            P_SystemInsertRiwayat3(SS,GM);
        }break;
        case 4:
        {
            P_SystemInsertRiwayat4(SS,GM);
        }break;
        case 5:
        {
            P_SystemInsertRiwayat5(SS,GM);
        }break;
        case 6:
        {
            P_SystemInsertRiwayat6(SS,GM);
        }break;
        case 7:
        {
            P_SystemInsertRiwayat7(SS,GM);
        }break;
    }
}
//Batas Insert

void P_SystemInsertRiwayat1(system_setting &SS,general_setting &GM)
{
    system("CLS");

    cout<<"Silahkan Search data orang di bawah ini : "
            <<endl;
    cout<<"Masukkan Nama orang : " <<endl;
    cin>>GM.searching;
    cout<<endl;

    GM.setting = 2;
    P_SystemInsertRiwayat(SS,GM);
}

void P_SystemInsertRiwayat2(system_setting &SS,general_setting &GM)
{
    //Bagian Search Data
    list_orang LO1 = SS.LO;
    GM.looping = 0;
    while (LO1.first != NULL)
    {
        if (LO1.first->info.nama == GM.searching)
        {
            GM.looping++;
            GM.search_orang[GM.looping] = LO1.first->info;
        }
        LO1.first = LO1.first->next;
    }
    if(GM.looping != 0)
    {
        GM.setting = 4;
        P_SystemInsertRiwayat(SS,GM);
    }
    else
    {
        GM.setting = 3;
        P_SystemInsertRiwayat(SS,GM);
    }
    //Batas Search Data
}

void P_SystemInsertRiwayat3(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"Nama salah atau nama orang yang anda masukkan belum terdaftar"<<endl;
    cout<<"1.  Cari nama orang lagi \n"
            <<"2. Kembali ke menu insert \n"
            <<">> ";
    cin>>GM.setting;

    switch(GM.setting)
    {
        case 1 :
        {
            GM.setting = 2;
            P_SystemInsertRiwayat(SS,GM);
        }break;
        case 2:
        {
            P_MenuInsert(SS,GM);
        }break;
        default:
        {
            P_SystemError(0);
            P_SystemInsertRiwayat3(SS,GM);
        }break;
    }
}

void P_SystemInsertRiwayat4(system_setting &SS,general_setting &GM)
{
    //Bagian Insert Riwayat orang
    //Bagian Output array
    system("CLS");
    cout<<"Berikut data hasil searching : "<<endl;
    GM.start_looping = 1;
    while (GM.start_looping <= GM.looping)
    {
        cout<<"ID                   : "<<GM.search_orang[GM.start_looping].id <<endl;
        cout<<"Nama              : "<<GM.search_orang[GM.start_looping].nama <<endl;
        cout<<"Alamat            : "<<GM.search_orang[GM.start_looping].alamat <<endl;
        cout<<"Tanggal LAhir : "<<GM.search_orang[GM.start_looping].tanggal_lahir.tanggal <<"  "<<GM.search_orang[GM.start_looping].tanggal_lahir.bulan<<"  "<<GM.search_orang[GM.start_looping].tanggal_lahir.tahun<<endl;
        GM.start_looping++;
    }
    //Batas Output Array

    cout<<"Silahkan masukkan ID riwayat dari hasil search yang ingin ditambah riwayat pendidikan : ";
    cin>>SS.IR.id_orang;
    cout<<endl;
    GM.start_looping = 1;
    while ((SS.IR.id_orang != GM.search_orang[GM.start_looping].id ) && (GM.start_looping <= GM.looping))
    {
        GM.start_looping++;
    }
    if(SS.IR.id_orang == GM.search_orang[GM.start_looping].id)
    {
        GM.setting = 5;
        P_SystemInsertRiwayat(SS,GM);
    }
    else
    {
        cout<<"ID yang anda masukkan salah"<<endl;
        cout<<"Silahkan tekan Enter untuk kembali memasukkan ID"<<endl;
        system("PAUSE");
        GM.setting = 4;
        P_SystemInsertRiwayat(SS,GM);
    }
   //Batas Insert Riwayat orang
}

void P_SystemInsertRiwayat5(system_setting &SS,general_setting &GM)
{
    //Bagian Mengisi Data Pendidikan
    system("CLS");
    cout<< "Berikut Merupakan Data Mahasiswa : "<<endl;
    cout<<"ID                   : "<<GM.search_orang[GM.start_looping].id <<endl;
    cout<<"Nama              : "<<GM.search_orang[GM.start_looping].nama <<endl;
    cout<<"Alamat            : "<<GM.search_orang[GM.start_looping].alamat <<endl;
    cout<<"Tanggal LAhir : "<<GM.search_orang[GM.start_looping].tanggal_lahir.tanggal <<"  "<<GM.search_orang[GM.start_looping].tanggal_lahir.bulan<<"  "<<GM.search_orang[GM.start_looping].tanggal_lahir.tahun<<endl;
     cout<<"Pilihlah Data Pendidikan yang ingin di inputkan kedalam Data Mahasiswa tersebut "<<endl;
    list_pendidikan LP1 = SS.LP;
    while (LP1.first != NULL)
    {
        cout<<"ID                   : "<<LP1.first->info.id<<endl;
        cout<<"Jenis               : "<<LP1.first->info.jenis<<endl;
        cout<<"Kepanjangan   : "<<LP1.first->info.kepanjangan<<endl;
        LP1.first = LP1.first->next;
    }
    cout<<"Silahkan inputkan ID pendidikan \n"
            <<">>";
    cin>>SS.IR.id_pendidikan;
    //Batas Mengisi Data Pendidikan

    GM.setting = 6;
    P_SystemInsertRiwayat(SS,GM);
}

void P_SystemInsertRiwayat6(system_setting &SS,general_setting &GM)
{
    //Bagian Untuk Meyakinkan Data Riwayat Benar atau Salah
    list_orang LO1 = SS.LO;
    while (LO1.first->info.id != SS.IR.id_orang)
    {
        LO1.first = LO1.first->next;
    }
    cout<<"ID                   : "<<LO1.first->info.id<<endl;
    cout<<"Nama               : "<<LO1.first->info.nama<<endl;
    cout<<"Alamat            : "<<LO1.first->info.alamat<<endl;
    cout<<"Tanggal Lahir   : "<<LO1.first->info.tanggal_lahir.tanggal<<" "<<LO1.first->info.tanggal_lahir.bulan<<" "<<LO1.first->info.tanggal_lahir.tahun<<endl;

    list_pendidikan LP1 = SS.LP;
    while (LP1.first->info.id != SS.IR.id_pendidikan)
    {
        LP1.first = LP1.first->next;
    }
    cout<<"ID                   : "<<LP1.first->info.id<<endl;
    cout<<"Jenis               : "<<LP1.first->info.jenis<<endl;
    cout<<"Kepanjangan   : "<<LP1.first->info.kepanjangan<<endl;
    //Batas Untuk Meyakinkan Data Riwayat Benar atau Salah
    cout<<endl
            <<"Apakah anda yakin ingin menyimpan data tersebut \n"
            <<"1. Ya                     2.Tidak"<<endl;
    cin>>GM.setting;
    switch(GM.setting)
    {
        case 1 :
        {
            GM.setting = 7;
            P_SystemInsertRiwayat(SS,GM);
        }break;
        case 2:
        {
            P_MenuInsert(SS,GM);
        }break;
        default:
        {
            P_SystemError(0);
            P_SystemInsertRiwayat3(SS,GM);
        }break;
    }
}

void P_SystemInsertRiwayat7(system_setting &SS,general_setting &GM)
{
    //Bagian DLL
    SS.AR = F_AlokasiCDLL(SS.IR);
    P_InsertAfterCDLL(SS.LR, SS.AR);
    //Batas DLL

    //Kembali ke Menu sebelumnya setelah Insert
    system("PAUSE");
}
