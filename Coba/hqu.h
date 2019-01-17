#ifndef HQU_H_INCLUDED
#define HQU_H_INCLUDED

#include <iostream>
using namespace std;

struct arr_queue{
    int info[4];
    int head,tail;
};


struct arr_buku{
    int ID_buku;
    string judul_buku;
    string nama_pengarang;
};

struct arr_stack{
    arr_buku info[4];
    int top;
};

void createQueue(arr_queue *q);
bool isEmpty(arr_queue q);
bool isFull(arr_queue q);
void enqueue(int elm, arr_queue *q);
int dequeue(arr_queue *q);
void viewQueue(arr_queue *q);
void splitQueue(arr_queue *q,arr_queue *r,arr_queue *s);



void createStack(arr_stack *s);
bool isEmpty(arr_stack s);
bool isFull(arr_stack s);
void push_stack(arr_buku elm, arr_stack *s);
arr_buku pop_stack(arr_stack *s);
void peek(arr_stack s);
void viewStack(arr_stack *s);
void inversStack(arr_stack *s);

#endif // HQU_H_INCLUDED
