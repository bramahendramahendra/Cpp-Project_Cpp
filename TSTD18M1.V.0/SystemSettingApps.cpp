#include "HeaderApps.h"

void SystemSetting()
{
    system_setting SS;
    general_setting GM;

    SystemProses(1,SS,GM);
    SystemProses(2,SS,GM);
}

void SystemProses(int setting, system_setting &SS, general_setting &GM)
{
    switch(setting)
    {
    case 1 :
        {
            P_SystemIntro();
            P_CreateListSLL(SS.LP);
            P_CreateListDLL(SS.LO);
            P_CreateListCDLL(SS.LR);
            GM.count_id_LO=0;
            GM.count_id_LP=0;
        } break;
    case 2 :{
        P_MenuHome(SS,GM);
        } break;
    default : break;
    };
}

//System Intro
void P_SystemIntro()
{
    cout <<endl
            <<endl
            <<"                          Selamat Datang     \n"
            <<endl
            <<"                             Program \n"
            <<"                        Riwayat Pendidikan  \n"
            <<endl
            <<"               Author : Brama Hendra Mahendra              \n";

    cout<<endl;
    cout<<endl;
    cout<<endl;

    system("PAUSE");
    system("CLS");
}

//System Error
void P_SystemError(int setting)
{
    switch(setting)
    {
    case 0 :
        {
            system("CLS");
            cout<<"Angka yang anda masukkan salah \n"
                <<"Tekan ENTER untuk kembali ke menu semula \n";
            system("PAUSE");
            system("CLS");
        }break;
    case 1 :
        {
            system("CLS");
            cout<<"Maaf nama yang anda cari tidak ditemukan silahkan masukkan nama dengan benar ";
            system("PAUSE");
            system("CLS");
        }break;
    case 2 :
        {
            system("CLS");
            cout<<"Maaf ID Peserta yang anda cari tidak ditemukan \n"
                <<"Silahkan Coba lagi \n";
            system("PAUSE");
            system("CLS");
        }break;
    case 3 :
        {
            system("CLS");
            cout<<"Maaf ID Voter yang anda cari tidak ditemukan \n"
                <<"Silahkan Coba lagi \n";
            system("PAUSE");
            system("CLS");
        }break;
    }

}
