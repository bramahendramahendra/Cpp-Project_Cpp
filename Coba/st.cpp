#include "hqu.h"

void createStack(arr_stack *s){
    s->top = -1;
}

void peek(arr_stack s){
    if (s.top!=-1){
        cout<<"top="<<endl;
        cout<<"judul="<<s.info[s.top].judul_buku<<endl;
        cout<<"nama pengarang="<<s.info[s.top].nama_pengarang<<endl;
    }
    else {
        cout<<"top = EMPTY!"<<endl;
        cout<<"judul = EMPTY!"<<endl;
        cout<<"nama pengarang = UNKNOWN!"<<endl;
    }
}

bool isEmpty(arr_stack s){
    if (s.top==-1){
        return true;
    }
    else {
        return false;
    }
}

bool isFull(arr_stack s){
    if (s.top==3){
        return true;
    }
    else{
        return false;
    }
}

void push_stack(arr_buku elm, arr_stack *s){
    if (isFull(*s)){
        cout<<"FULL"<<endl;
    }
    else{
        s->top=s->top+1;
        s->info[s->top]=elm;
    }
}

arr_buku pop_stack(arr_stack *s){
    if (isEmpty(*s)){
        arr_buku x;
        x.ID_buku=0;
        x.judul_buku="EMPTY";
        x.nama_pengarang="UNKNOWN";
        return x;
    }
    else{
        arr_buku x=s->info[s->top];
        s->top=s->top-1;
        return x;
    }
}

void viewStack(arr_stack *s){
    if (isEmpty(*s)){
            cout<<"Stack is EMPTY"<<endl;
    }
    else{
        int r=s->top;
        while (r>=0){
            cout<<s->info[r].ID_buku<<endl;
            cout<<s->info[r].judul_buku<<endl;
            cout<<s->info[r].nama_pengarang<<endl;
            r=r-1;
        }
    }
}

void inversStack(arr_stack *s){

    arr_stack a;
    createStack(&a);
    for (int i = s->top; i>=0;i--)
        {
            arr_buku c = pop_stack(s);
            push_stack(c,&a);
        }
    *s = a;
}
