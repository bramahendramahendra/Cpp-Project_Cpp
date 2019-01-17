#include "HeaderApps.h"

void P_SystemDeleteOrang(system_setting &SS,general_setting &GM)
{
    switch(GM.setting)
    {
        case 1 :
        {
            P_SystemDeleteOrang1(SS,GM);
        }break;
        case 2:
        {
            P_SystemDeleteOrang2(SS,GM);
        }break;
        case 3:
        {
            P_SystemDeleteOrang3(SS,GM);
        }break;
        case 4:
        {
            P_SystemDeleteOrang4(SS,GM);
        }break;
        case 5:
        {
            P_SystemDeleteOrang5(SS,GM);
        }break;
        case 6:
        {
            P_SystemDeleteOrang6(SS,GM);
        }break;
    }
}

void P_SystemDeleteOrang1(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"Cari Nama Orang yang ingin dihapus: "
            <<">>";
    cin>>GM.searching;
    cout<<endl;

    GM.setting = 2;
    P_SystemDeleteOrang(SS,GM);
}

void P_SystemDeleteOrang2(system_setting &SS,general_setting &GM)
{
    //Bagian Mencari Data
    list_orang LO1 = SS.LO;
    GM.looping = 0;
    while(LO1.first != NULL)
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
        P_SystemDeleteOrang(SS,GM);
    }
    else
    {
        GM.setting = 3;
        P_SystemDeleteOrang(SS,GM);
    }
    //Batas Mencari Data
}

void P_SystemDeleteOrang3(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"Nama salah atau nama orang yang anda masukkan belum terdaftar"<<endl;
    cout<<"1.  Cari nama orang lagi \n"
            <<"2. Kembali ke menu delete \n"
            <<">> ";
    cin>>GM.setting;

    switch(GM.setting)
    {
        case 1 :
        {
            GM.setting = 2;
            P_SystemDeleteOrang(SS,GM);
        }break;
        case 2:
        {
            P_MenuDelete(SS,GM);
        }break;
        default:
        {
            P_SystemError(0);
            P_SystemDeleteOrang3(SS,GM);
        }break;
    }
}

void P_SystemDeleteOrang4(system_setting &SS,general_setting &GM)
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

    cout<<"Silahkan masukkan ID orang dari hasil search yang ingin ditambah data orang : ";
    cin>>SS.IO.id;
    cout<<endl;
    GM.start_looping = 1;
    while ((SS.IO.id != GM.search_orang[GM.start_looping].id ) && (GM.start_looping <= GM.looping))
    {
        GM.start_looping++;
    }
    if(SS.IO.id == GM.search_orang[GM.start_looping].id)
    {
        GM.setting = 5;
        P_SystemDeleteOrang(SS,GM);
    }
    else
    {
        cout<<"ID yang anda masukkan salah"<<endl;
        cout<<"Silahkan tekan Enter untuk kembali memasukkan ID"<<endl;
        system("PAUSE");
        GM.setting = 4;
        P_SystemDeleteOrang(SS,GM);
    }
   //Batas Insert Riwayat orang
}

void P_SystemDeleteOrang5(system_setting &SS,general_setting &GM)
{
    cout<<"Apakah anda yakin ingin menghapus data tersebut \n"
            <<"1. Ya                     2.Tidak"
            <<endl;
    cin>>GM.setting;
    switch(GM.setting)
    {
        case 1 :
        {
            GM.setting = 6;
            P_SystemDeleteOrang(SS,GM);
        }break;
        case 2:
        {
            P_MenuDelete(SS,GM);
        }break;
        default:
        {
            P_SystemError(0);
            P_SystemDeleteOrang3(SS,GM);
        }break;
    }
}

void P_SystemDeleteOrang6(system_setting &SS,general_setting &GM)
{
    //Bagian DLL
    P_DeleteAfterDLL(SS.LO,SS.IO);
    //Batas DLL

    //Kembali ke Menu sebelumnya setelah Insert
    system("PAUSE");
}

void P_SystemDeletePendidikan(system_setting &SS,general_setting &GM)
{
    switch(GM.setting)
    {
        case 1 :
        {
            P_SystemDeletePendidikan1(SS,GM);
        }break;
        case 2:
        {
            P_SystemDeletePendidikan2(SS,GM);
        }break;
        case 3:
        {
            P_SystemDeletePendidikan3(SS,GM);
        }break;
        case 4:
        {
            P_SystemDeletePendidikan4(SS,GM);
        }break;
        case 5:
        {
            P_SystemDeletePendidikan5(SS,GM);
        }break;
        case 6:
        {
            P_SystemDeletePendidikan6(SS,GM);
        }break;
    }
}

void P_SystemDeletePendidikan1(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"Cari Singkatan Pendidikan yang ingin dihapus: "
            <<">>";
    cin>>GM.searching;
    cout<<endl;

    GM.setting = 2;
    P_SystemDeletePendidikan(SS,GM);
}

void P_SystemDeletePendidikan2(system_setting &SS,general_setting &GM)
{
    //Bagian Mencari Data
    list_pendidikan LP1 = SS.LP;
    GM.looping = 0;
    while(LP1.first != NULL)
    {
        if (LP1.first->info.jenis == GM.searching)
        {
            GM.looping++;
            GM.search_pendidikan[GM.looping] = LP1.first->info;
        }
        LP1.first = LP1.first->next;
    }
    if(GM.looping != 0)
    {
        GM.setting = 4;
        P_SystemDeletePendidikan(SS,GM);
    }
    else
    {
        GM.setting = 3;
        P_SystemDeletePendidikan(SS,GM);
    }
    //Batas Mencari Data
}

void P_SystemDeletePendidikan3(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"Singkatan salah atau singkatam pendidikan yang anda masukkan belum terdaftar"<<endl;
    cout<<"1.  Cari jenis pendidikan lagi \n"
            <<"2. Kembali ke menu delete \n"
            <<">> ";
    cin>>GM.setting;

    switch(GM.setting)
    {
        case 1 :
        {
            GM.setting = 2;
            P_SystemDeletePendidikan(SS,GM);
        }break;
        case 2:
        {
            P_MenuDelete(SS,GM);
        }break;
        default:
        {
            P_SystemError(0);
            P_SystemDeletePendidikan3(SS,GM);
        }break;
    }
}

void P_SystemDeletePendidikan4(system_setting &SS,general_setting &GM)
{
    //Bagian Insert Riwayat orang
    //Bagian Output array
    system("CLS");
    cout<<"Berikut data hasil searching : "<<endl;
    GM.start_looping = 1;
    while (GM.start_looping <= GM.looping)
    {
        cout<<"ID                   : "<<GM.search_pendidikan[GM.start_looping].id <<endl;
        cout<<"Nama              : "<<GM.search_pendidikan[GM.start_looping].jenis <<endl;
        cout<<"Alamat            : "<<GM.search_pendidikan[GM.start_looping].kepanjangan <<endl;
        GM.start_looping++;
    }

    //Batas Output Array
    cout<<"Silahkan masukkan ID orang dari hasil search yang ingin ditambah data orang : ";
    cin>>SS.IP.id;
    cout<<endl;
    GM.start_looping = 1;
    while ((SS.IP.id != GM.search_pendidikan[GM.start_looping].id ) && (GM.start_looping <= GM.looping))
    {
        GM.start_looping++;
    }

    if(SS.IP.id == GM.search_pendidikan[GM.start_looping].id)
    {
        GM.setting = 5;
        P_SystemDeletePendidikan(SS,GM);
    }
    else
    {
        cout<<"ID yang anda masukkan salah"<<endl;
        cout<<"Silahkan tekan Enter untuk kembali memasukkan ID"<<endl;
        system("PAUSE");
        GM.setting = 4;
        P_SystemDeletePendidikan(SS,GM);
    }
   //Batas Insert Riwayat orang
}

void P_SystemDeletePendidikan5(system_setting &SS,general_setting &GM)
{
    cout<<"Apakah anda yakin ingin menghapus data tersebut \n"
            <<"1. Ya                     2.Tidak"
            <<endl;
    cin>>GM.setting;
    switch(GM.setting)
    {
        case 1 :
        {
            GM.setting = 6;
            P_SystemDeletePendidikan(SS,GM);
        }break;
        case 2:
        {
            P_MenuDelete(SS,GM);
        }break;
        default:
        {
            P_SystemError(0);
            P_SystemDeletePendidikan3(SS,GM);
        }break;
    }
}

void P_SystemDeletePendidikan6(system_setting &SS,general_setting &GM)
{
    //Bagian DLL
    P_DeleteAfterSLL(SS.LP,SS.IP);
    //Batas DLL

    //Kembali ke Menu sebelumnya setelah Insert
    system("PAUSE");
}
