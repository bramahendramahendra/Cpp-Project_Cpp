#include "HeaderApps.h"

void P_CreateListCDLL(list_riwayat &LR)
{
    LR.first=NULL;
    LR.last=NULL;
}

bool F_ListEmptyCDLL(list_riwayat LR)
{
    if ((LR.first == NULL)&&(LR.last == NULL))
        return true;
    else
        return false;
}

address_riwayat F_AlokasiCDLL(infotype_riwayat IR)
{
    address_riwayat AR = new element_riwayat;

    AR->info.id_orang = IR.id_orang;
    AR->info.id_pendidikan = IR.id_pendidikan;

    AR->next = NULL;
    AR->prev = NULL;

    return AR;
}

address_riwayat F_DealokasiCDLL(address_riwayat AR)
{
    delete AR;
    return AR;
}

void P_InsertAfterCDLL(list_riwayat &LR,address_riwayat AR)
{
    if(F_ListEmptyCDLL(LR))
    {
        LR.first=AR;
        LR.last=AR;
    }
    else
    {
        if((LR.first->next == NULL)&&(LR.first->prev == NULL))
        {
            if(LR.first->info.id_orang>AR->info.id_orang)
            {
                LR.first->prev = AR;
                AR->next = LR.first;
                LR.first = AR;
            }
            else if(LR.first->info.id_orang<AR->info.id_orang)
            {
                LR.last->next = AR;
                AR->prev = LR.last;
                LR.last = AR;
            }
            else
            {
                if(LR.first->info.id_pendidikan>AR->info.id_pendidikan)
                {
                    LR.first->prev = AR;
                    AR->next = LR.first;
                    LR.first = AR;
                }
                else
                {
                    LR.last->next = AR;
                    AR->prev = LR.last;
                    LR.last = AR;
                }
            }
        }
        else if(LR.first->info.id_orang>AR->info.id_orang)
        {
            LR.first->prev = AR;
            AR->next = LR.first;
            LR.first = AR;
        }
        else if(LR.last->info.id_orang<AR->info.id_orang)
        {
            LR.last->next = AR;
            AR->prev = LR.last;
            LR.last = AR;
        }
        else
        {
            if((LR.first->info.id_pendidikan > AR->info.id_pendidikan)&&(LR.first->info.id_orang == AR->info.id_orang))
            {
                LR.first->prev = AR;
                AR->next = LR.first;
                LR.first = AR;
            }
            else if((LR.last->info.id_pendidikan < AR->info.id_pendidikan)&&(LR.last->info.id_orang == AR->info.id_orang))
            {
                LR.last->next = AR;
                AR->prev = LR.last;
                LR.last = AR;
            }
            else
            {
                cout<<"berhasil";
                address_riwayat AR1 = LR.first;
                while (AR->info.id_orang > AR1->info.id_orang)
                {
                    AR1 = AR1->next;
                }
                if(AR->info.id_orang == AR1->info.id_orang)
                {
                    while (AR->info.id_pendidikan>AR1->info.id_pendidikan)
                    {
                        AR1 = AR1->next;
                    }
                    AR->prev = AR1->prev;
                    AR->next = AR1;
                    AR1->prev->next = AR;
                    AR1->prev = AR;
                }
                else
                {
                    AR->prev = AR1->prev;
                    AR->next = AR1;
                    AR1->prev->next = AR;
                    AR1->prev = AR;
                }
            }
        }
    }
     cout<<"berhasil";
    system("PAUSE");
}
/*
void P_DeleteAfterCDLL(list_riwayat &LR,infotype_riwayat IR)
{
    if((LR.first->next == NULL)&&(LO.first->prev == NULL))
    {
        address_riwayat AR1 = LR.first;
        F_DealokasiCDLL(AR1);
        P_CreateListCDLL(LR);
    }
    else if(LR.first->info.id_orang == IR.id_orang)
    {
        address_orang AR1 = LR.first;
        LR.first = LR.first->next;
        LR.first->prev = NULL;
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
*/
//Testing View
void P_ViewCDLL(list_riwayat LR)
{
    system("CLS");
    list_riwayat LR1 = LR;
    while (LR1.first != NULL)
    {
        cout<<"ID orang: ";
        cout<<LR1.first->info.id_orang;
        cout<<endl;

        cout<<"ID Pendidikan: ";
        cout<<LR1.first->info.id_pendidikan;
        cout<<endl;


        cout<<endl;
        cout<<endl;
        cout<<endl;
        LR1.first = LR1.first->next;
    }

    system("PAUSE");
    system("CLS");

}
//Batas Testing View
