#ifndef _CONTREF_H
#define _CONTREF_H

typedef struct memory //lista de referência que contém as datas de todos os ponteiros declarados
{
    void *adress;
    int counter;
    struct memory *next;

}memory;

void clearAll(); //limpando a lista de referência
void printRefList(); //printando a lista de referência
void updateReferenceList(memory *element,int counter); //atualiza a lista de referência após cada atribuição de ponteiros
void *malloc2(int size_); //ponteiro para um espaço de memória alocado e cria um elemento na lista de referência vinculada a este ponteiro
void atrib2(void **receiver,void *transmitter); //data de transferência de um ponteiro para outro, receptor = transmissor

#endif // _CONTREF_H
