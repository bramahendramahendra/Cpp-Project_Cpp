#include "HeaderApps.h"

void P_MenuHome(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"----------------------------------\n"
        <<" Silahkan Pilih Menu di bawah ini \n"
        <<"----------------------------------\n"
        <<"1. Insert  \n"
        <<"2. Update \n"
        <<"3. Delete \n"
        <<"4. View \n"
        <<"0. Exit \n"
        <<">> ";

    cin>> GM.setting;

    switch(GM.setting)
    {
        case 0 :
            {
               cout<<"EXIT";
            }break;
        case 1 :
            {
                P_MenuInsert(SS,GM);
            }break;
        case 2 :
            {
                //P_MenuUpdate(SS,GM);
            }break;
        case 3:
            {
                P_MenuDelete(SS,GM);
            }break;
        case 4 :
            {
                P_MenuView(SS,GM);
            }break;
        default :
            {
                P_SystemError(0);
                P_MenuHome(SS,GM);
            }break;
    }
}

void P_MenuInsert(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"----------------------------------\n"
        <<" Silahkan Pilih Menu di bawah ini \n"
        <<"----------------------------------\n"
        <<"1. Tambah  Orang  \n"
        <<"2. Tambah  Pendidikan \n"
        <<"3. Tambah Riwayat Pendidikan \n"
        <<"0. Back  \n"
        <<">> ";

    cin>> GM.setting;

    switch(GM.setting)
    {
        case 0 :
            {
                P_MenuHome(SS,GM);
            }break;
        case 1 :
            {
                P_SystemInsertOrang(SS,GM);
                 P_MenuInsert(SS,GM);
            }break;
        case 2 :
            {
                P_SystemInsertPendidikan(SS,GM);
                 P_MenuInsert(SS,GM);
            }break;
        case 3:
            {
                GM.setting = 1;
                P_SystemInsertRiwayat(SS,GM);
                P_MenuInsert(SS,GM);
            }break;
        default :
            {
                P_SystemError(0);
                P_MenuInsert(SS,GM);
            }break;
    }
}

void P_MenuUpdate(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"----------------------------------\n"
        <<" Silahkan Pilih Menu di bawah ini \n"
        <<"----------------------------------\n"
        <<"1. Update Data Orang  \n"
        <<"2. Update Data Pendidikan \n"
        <<"3. Update Data Pendidikan \n"
        <<"0. Back  \n"
        <<">> ";

    cin>> GM.setting;

    switch(GM.setting)
    {
        case 0 :
            {
                P_MenuHome(SS,GM);
            }break;
        case 1 :
            {
                cout<<"Berhasil";
            }break;
        case 2 :
            {
                cout<<"Berhasil";
            }break;
        default :
            {
                P_SystemError(0);
                P_MenuDelete(SS,GM);
            }break;
    }
}

void P_MenuDelete(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"----------------------------------\n"
        <<" Silahkan Pilih Menu di bawah ini \n"
        <<"----------------------------------\n"
        <<"1. Hapus Data Orang tertentu  \n"
        <<"2. Hapus Data Pendidikan tertentu \n"
        <<"3. Hapus Data Riwayat tertentu \n"
        <<"0. Back  \n"
        <<">> ";

    cin>> GM.setting;

    switch(GM.setting)
    {
        case 0 :
            {
                P_MenuHome(SS,GM);
            }break;
        case 1 :
            {
                GM.setting = 1;
                P_SystemDeleteOrang(SS,GM);
                P_MenuDelete(SS,GM);
            }break;
        case 2 :
            {
                GM.setting = 1;
                P_SystemDeletePendidikan(SS,GM);
                P_MenuDelete(SS,GM);
            }break;
        case 3 :
            {
                cout<<"Berhasil";
            }break;
        default :
            {
                P_SystemError(0);
                P_MenuDelete(SS,GM);
            }break;
    }
}

void P_MenuView(system_setting &SS,general_setting &GM)
{
    system("CLS");
    cout<<"----------------------------------\n"
        <<" Silahkan Pilih Menu di bawah ini \n"
        <<"----------------------------------\n"
        <<"1. View Data Orang   \n"
        <<"2. View Data Pendidikan   \n"
        <<"3. View Data Riwayat   \n"
        <<"4. Data Orang dengan Riwayat Pendidikan Tertentu \n"
        <<"5. Data  Riwayat Pendidikan dengan Orang tertentu\n"
        <<"6. Data orang paling banyak riwayat pendidikan hingga tidak \n"
        <<"0. Back  \n"
        <<">> ";

    cin>> GM.setting;

    switch(GM.setting)
    {
        case 0 :
        {
            P_MenuHome(SS,GM);;
        }break;
        case 1 :
            {
                P_ViewDLL(SS.LO);
                P_MenuView(SS,GM);
            }break;
        case 2 :
            {
                P_ViewSLL(SS.LP);
                P_MenuView(SS,GM);
            }break;
        case 3 :
            {
                P_ViewCDLL(SS.LR);
                P_MenuView(SS,GM);
            }break;
        case 4 :
            {
                cout<<"Berhasil";
            }break;
        case 5 :
            {
                P_ViewDLL(SS.LO);
                P_MenuView(SS,GM);
            }break;
        default :
            {
                P_SystemError(0);
                 P_MenuView(SS,GM);
            }break;
    }
}

