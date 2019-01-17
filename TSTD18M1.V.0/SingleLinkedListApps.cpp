#include "HeaderApps.h"

void P_CreateListSLL(list_pendidikan &LP)
{
    LP.first = NULL;
}

bool F_ListEmptySLL(list_pendidikan LP)
{
    if (LP.first == NULL)
        return true;

    else
        return false;
}

address_pendidikan F_AlokasiSLL(infotype_pendidikan IP)
{
    address_pendidikan AP =  new element_pendidikan;

    AP->info.id = IP.id;
    AP->info.jenis = IP.jenis;
    AP->info.kepanjangan = IP.kepanjangan;

    AP->next = NULL;

    return AP;
}

address_pendidikan F_DealokasiSLL(address_pendidikan AP)
{
    delete AP;

    return AP;
}

void P_InsertLastSLL(list_pendidikan &LP, address_pendidikan AP)
{
    if(F_ListEmptySLL(LP))
    {
        LP.first = AP;
    }
    else
    {
        if(LP.first->next == NULL)
        {
            LP.first->next = AP;
        }
        else
        {
            address_pendidikan AP1 = LP.first;
            while(AP1->next != NULL)
            {
                AP1 = AP1->next;
            }
            AP1->next = AP;
        }
    }
}

void P_DeleteAfterSLL(list_pendidikan &LP,infotype_pendidikan IP)
{
    if(LP.first->next == NULL)
    {
        cout<<"Berhasil";
        system("PAUSE");
        address_pendidikan AP1 = LP.first;
        F_DealokasiSLL(AP1);
        P_CreateListSLL(LP);
    }
    else if(LP.first->info.id == IP.id)
    {
        address_pendidikan AP1 = LP.first;
        LP.first = LP.first->next;
        F_DealokasiSLL(AP1);
    }
    else
    {
        address_pendidikan AP1 = LP.first;
        while ((AP1->next->info.id != IP.id) && (AP1 != NULL))
        {
            AP1 = AP1->next;
        }
        if(AP1->next->info.id == IP.id)
        {
            address_pendidikan AP2 = AP1->next;
            AP1->next = AP1->next->next;
            F_DealokasiSLL(AP2);
        }
        else
        {
            cout<<"Data yang anda masukkan tidak ada";
        }
    }
}

//Testing View
void P_ViewSLL(list_pendidikan LP)
{
    system("CLS");
    list_pendidikan LP1 = LP;
    while (LP1.first != NULL)
    {
        cout<<"ID : ";
        cout<<LP1.first->info.id;
        cout<<endl;

        cout<<"Jenis     : ";
        cout<<LP1.first->info.jenis;
        cout<<endl;

        cout<<"Kepanjangan  : ";
        cout<<LP1.first->info.kepanjangan;
        cout<<endl;
        cout<<endl;
        cout<<endl;


        LP1.first= LP1.first->next;
    }

    system("PAUSE");
    system("CLS");

}
//Batas Testing View
