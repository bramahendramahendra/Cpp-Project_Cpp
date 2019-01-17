#include "HeaderApps.h"

void P_CreateListDLL(list_orang &LO)
{
    LO.first=NULL;
    LO.last=NULL;
}

bool F_ListEmptyDLL(list_orang LO)
{
    if ((LO.first == NULL)&&(LO.last == NULL))
        return true;
    else
        return false;
}

address_orang F_AlokasiDLL(infotype_orang IO)
{
    address_orang AO =  new element_orang;

    AO->info.id = IO.id;
    AO->info.nama = IO.nama;
    AO->info.alamat = IO.alamat;
    AO->info.tanggal_lahir = IO.tanggal_lahir;

    AO->next = NULL;
    AO->prev = NULL;

    return AO;
}

address_orang F_DealokasiDLL(address_orang AO)
{
    delete AO;

    return AO;
}

void P_InsertFirstDLL(list_orang &LO,address_orang AO)
{
    if(F_ListEmptyDLL(LO))
    {
        LO.first=AO;
        LO.last=AO;
    }
    else
    {
        LO.first->prev = AO;
        AO->next = LO.first;
        LO.first = AO;
    }
}

void P_DeleteAfterDLL(list_orang &LO,infotype_orang IO)
{
    if((LO.first->next == NULL)&&(LO.first->prev == NULL))
    {
        address_orang AO1 = LO.first;
        F_DealokasiDLL(AO1);
        P_CreateListDLL(LO);
    }
    else if(LO.first->info.id == IO.id)
    {
        address_orang AO1 = LO.first;
        LO.first = LO.first->next;
        LO.first->prev = NULL;
        F_DealokasiDLL(AO1);
    }
    else if(LO.last->info.id == IO.id)
    {
        address_orang AO1 = LO.last;
        LO.last = LO.last->prev;
        LO.last->next= NULL;
        F_DealokasiDLL(AO1);
    }
    else
    {
        address_orang AO1 = LO.first;
        while ((AO1->next->info.id != IO.id) && (AO1 != NULL))
        {
            AO1 = AO1->next;
        }
        if(AO1->next->info.id == IO.id)
        {
            address_orang AO2 = AO1->next;
            AO1->next= AO1->next->next;
            AO1->next->prev= AO1;
            F_DealokasiDLL(AO2);
        }
        else
        {
            cout<<"Data yang anda masukkan tidak ada";
        }
    }
}

//Testing View
void P_ViewDLL(list_orang LO)
{
    system("CLS");
    list_orang LO1 = LO;
    while (LO1.first != NULL)
    {
        cout<<"ID : ";
        cout<<LO1.first->info.id;
        cout<<endl;

        cout<<"Masukkan Nama     : ";
        cout<<LO1.first->info.nama;
        cout<<endl;

        cout<<"Masukkan Alamat Peserta  : ";
        cout<<LO1.first->info.alamat;
        cout<<endl;

        cout<<"Masukkan Tanggal Lahir Peserta : ";
        cout<<LO1.first->info.tanggal_lahir.tanggal;
        cout<<" ";
        cout<<LO1.first->info.tanggal_lahir.bulan;
        cout<<" ";
        cout<<LO1.first->info.tanggal_lahir.tahun;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        LO1.first = LO1.first->next;
    }

    system("PAUSE");
    system("CLS");

}
//Batas Testing View
