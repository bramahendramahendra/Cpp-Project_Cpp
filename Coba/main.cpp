#include "hqu.h"
#include "hst.h"

int main()
{
    /*cout << "Stack Array" << endl;
    cout <<endl;
    arr_buku it;
    arr_stack my;
    createStack(&my);
    cout << "push STACK array"<<endl;

    it.ID_buku=111;
    it.judul_buku="Why?Mathematic";
    it.nama_pengarang="Yun E Hyeon";
    push_stack(it,&my);

    it.ID_buku=112;
    it.judul_buku="Detektif Conan";
    it.nama_pengarang="Aoyama Gosho";
    push_stack(it,&my);

    it.ID_buku=113;
    it.judul_buku="Kambing Jantan";
    it.nama_pengarang="Raditya Dika";
    push_stack(it,&my);

    it.ID_buku=110;
    it.judul_buku="Dilan 1990";
    it.nama_pengarang="Pidi Baiq";
    push_stack(it,&my);


    viewStack(&my);

    arr_buku okey = pop_stack(&my);
    cout<<"DELETED : "<<endl;
    cout<<" ID Buku         = "<<okey.ID_buku<<endl;
    cout<<" Judul      = "<<okey.judul_buku<<endl;
    cout<<" Nama Pengarang  = "<<okey.nama_pengarang<<endl;
    cout<<endl;
    cout<<"AFTER DELETE"<<endl;
    viewStack(&my);
    cout<<endl;
    cout<<endl;
    cout<<"INVERSE STACK"<<endl;
    inversStack(&my);
    viewStack(&my);*/

    arr_queue ii,rr,mm;
    createQueue(&ii);
    createQueue(&rr);
    createQueue(&mm);
    enqueue(2,&ii);
    enqueue(8,&ii);
    enqueue(1,&ii);
    enqueue(4,&ii);
    cout<<"ENQUEUE "<<endl;
    viewQueue(&ii);
    cout<<"peek = "<<ii.info[ii.head]<<endl;
    cout<<endl;

    cout<<"deleted = "<<dequeue(&ii)<<endl;
    viewQueue(&ii);
    cout<<endl;
    cout<<endl;
    cout<<"SPLIT"<<endl;
    splitQueue(&ii,&rr,&mm);
    cout<<"initial"<<endl;
    viewQueue(&ii);
    cout<<"even"<<endl;
    viewQueue(&rr);
    cout<<"odd"<<endl;
    viewQueue(&mm);
    return 0;
}
