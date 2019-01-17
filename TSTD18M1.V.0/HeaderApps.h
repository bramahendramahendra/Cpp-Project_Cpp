#ifndef HEADERAPPS_H_INCLUDED
#define HEADERAPPS_H_INCLUDED

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define nil NULL

//typedef umum
typedef struct element_orang *address_orang;
typedef struct element_pendidikan *address_pendidikan;
typedef struct element_riwayat *address_riwayat;

//variabel Type untuk type infotype
struct type_tanggal_lahir
{
    string tanggal;
    string bulan;
    string tahun;
};


//Variabe Infotype Program
struct infotype_orang
{
    int id;
    string nama;
    string alamat;
    type_tanggal_lahir tanggal_lahir;
};

struct infotype_pendidikan
{
    int id;
    string jenis;
    string kepanjangan;
};

struct infotype_riwayat
{
    int id_orang;
    int id_pendidikan;
};

//Variabel elment list program
struct element_orang
{
    infotype_orang info;
    address_orang next;
    address_orang prev;
};

struct element_pendidikan
{
    infotype_pendidikan info;
    address_pendidikan next;
};

struct element_riwayat
{
    infotype_riwayat info;
    address_riwayat next;
    address_riwayat prev;
};

//Semua list program
struct list_orang
{
    address_orang first;
    address_orang last;
};

struct list_pendidikan
{
    address_pendidikan first;
};

struct list_riwayat
{
    address_riwayat first;
    address_riwayat last;
};

// strutur data utama
struct system_setting
{
    infotype_orang IO;
    infotype_pendidikan IP;
    infotype_riwayat IR;
    address_orang AO;
    address_pendidikan AP;
    address_riwayat AR;
    list_orang LO;
    list_pendidikan LP;
    list_riwayat LR;
};

struct general_setting
{
    string searching;
    int setting;
    int count_id_LO;
    int count_id_LP;
    int count_id_LR;
    infotype_orang search_orang[100];
    infotype_pendidikan search_pendidikan[100];
    int looping;
    int start_looping;
};

//System Setting Declaration
void SystemSetting();
void SystemProses(int setting, system_setting &SS, general_setting &GM);
void P_SystemIntro();
void P_SystemError(int setting);

//System Process Declaration
void P_MenuHome(system_setting &SS,general_setting &GM);
void P_MenuInsert(system_setting &SS,general_setting &GM);
void P_MenuDelete(system_setting &SS,general_setting &GM);
void P_MenuView(system_setting &SS,general_setting &GM);

//System Insert
void P_SystemInsertOrang(system_setting &SS,general_setting &GM);
void P_SystemInsertPendidikan(system_setting &SS,general_setting &GM);
void P_SystemInsertRiwayat(system_setting &SS,general_setting &GM);
void P_SystemInsertRiwayat1(system_setting &SS,general_setting &GM);
void P_SystemInsertRiwayat2(system_setting &SS,general_setting &GM);
void P_SystemInsertRiwayat3(system_setting &SS,general_setting &GM);
void P_SystemInsertRiwayat4(system_setting &SS,general_setting &GM);
void P_SystemInsertRiwayat5(system_setting &SS,general_setting &GM);
void P_SystemInsertRiwayat6(system_setting &SS,general_setting &GM);
void P_SystemInsertRiwayat7(system_setting &SS,general_setting &GM);

//System Delete
void P_SystemDeleteOrang(system_setting &SS,general_setting &GM);
void P_SystemDeleteOrang1(system_setting &SS,general_setting &GM);
void P_SystemDeleteOrang2(system_setting &SS,general_setting &GM);
void P_SystemDeleteOrang3(system_setting &SS,general_setting &GM);
void P_SystemDeleteOrang4(system_setting &SS,general_setting &GM);
void P_SystemDeleteOrang5(system_setting &SS,general_setting &GM);
void P_SystemDeleteOrang6(system_setting &SS,general_setting &GM);
void P_SystemDeletePendidikan(system_setting &SS,general_setting &GM);
void P_SystemDeletePendidikan1(system_setting &SS,general_setting &GM);
void P_SystemDeletePendidikan2(system_setting &SS,general_setting &GM);
void P_SystemDeletePendidikan3(system_setting &SS,general_setting &GM);
void P_SystemDeletePendidikan4(system_setting &SS,general_setting &GM);
void P_SystemDeletePendidikan5(system_setting &SS,general_setting &GM);
void P_SystemDeletePendidikan6(system_setting &SS,general_setting &GM);

//Single Linked List Declaration
void P_CreateListSLL(list_pendidikan &LP);
bool F_ListEmptySLL(list_pendidikan LP);
address_pendidikan F_AlokasiSLL(infotype_pendidikan IP);
address_pendidikan F_DealokasiSLL(address_pendidikan AP);
void P_InsertLastSLL(list_pendidikan &LP, address_pendidikan AP);
void P_DeleteAfterSLL(list_pendidikan &LP,infotype_pendidikan IP);
void P_ViewSLL(list_pendidikan LP);

//Double Linked List Declaration
void P_CreateListDLL(list_orang &LO);
bool F_ListEmptyDLL(list_orang LO);
address_orang F_AlokasiDLL(infotype_orang IO);
address_orang F_DealokasiDLL(address_orang AO);
void P_InsertFirstDLL(list_orang &LO,address_orang AO);
void P_DeleteAfterDLL(list_orang &LO,infotype_orang IO);
void P_ViewDLL(list_orang LO);

//Circular Double Linked List Declaration
void P_CreateListCDLL(list_riwayat &LR);
bool F_ListEmptyCDLL(list_riwayat LR);
address_riwayat F_AlokasiCDLL(infotype_riwayat IR);
address_riwayat F_DealokasiCDLL(address_riwayat AR);
void P_InsertAfterCDLL(list_riwayat &LR,address_riwayat AR);
void P_ViewCDLL(list_riwayat LR);

/*
//Daftar Login
void P_DafterVoting(setting &S,Program &P);
Type_User F_IsiDaftarVoting(Program &P);
void P_Login(Program &P,setting &S);



//Menu voting
void P_MenuPembuka(setting &S,Program &P);
int F_MenuAcara(setting S);
void P_MenuAcara(setting &S);
int F_MenuInsert(setting S);
void P_MenuInsert(setting &S);
int F_MenuInsertPeserta(int sistem,setting S);
void P_MenuInsertPeserta(int sistem,setting &S);
int F_MenuInsertVoting(int sistem,setting S);
void P_MenuInsertVoting(int sistem,setting &S);
int F_MenuDelete(setting S);
void P_MenuDelete(setting &S);
void P_MenuDeletePeserta(int sistem,setting &S);
void P_MenuDeleteVoting(setting &S);
void P_MenuDeleteVoter(setting &S);
void P_MenuSearchVoting(setting &S);
int F_MenuUpdate(setting S);
void P_MenuUpdate(setting &S);
int F_MenuUpdatePeserta(setting S);
void P_MenuUpdatePeserta(setting &S);
void P_MenuUpdateVoter(setting &S);
void P_MenuView(setting &S);
void P_MenuReport(setting &S);
void P_Error(int sistem);

//Insert Voting
infotype_peserta F_InputanPeserta(infotype_peserta IP);
void P_InsertPeserta(setting &S);
infotype_voter F_InputanVoter(infotype_voter IV);
void P_InsertVoter(setting &S);
string F_inputanVoting(setting S);
void P_InsertVoting(setting &S);

//Delete Voting
void P_DeletePeserta(setting &S);
void P_DeleteVoting(setting &S);
void P_DeleteVoter(setting &S);

//Update Voting
void UpdatePeserta(setting &S);
void UpdateVoter(setting &S);

//Search Voting
void P_SeacrhPeserta(setting S,string NamaSearching);

//Report Voting
void P_ReportVoting(setting S);


//MCDLL voting
void P_CreateListMCDLL(adr_peserta &AP);
bool F_isEmptyListMCDLL(adr_peserta AP);
adr_voting F_AlokasiMCDLL(setting S);
adr_voting F_DealokasiMCDLL(adr_voting P);
void P_InsertLastMCDLL(list_peserta &LP,list_voter &LV,adr_voting AI,adr_voter AV);
void P_DeleteMCDLL(list_peserta &LP,string hapus);



//Print voting
void P_PrintInfo(int system,setting S);

//FileDat Voting
void SaveDataVoting(Program P,setting S);
void LoadDataVoting(Program P,setting S);
*/
#endif // HEADERAPPS_H_INCLUDED
