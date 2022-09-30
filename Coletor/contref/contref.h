#ifndef _CONTREF_H
#define _CONTREF_H

typedef struct memory //lista de refer�ncia que cont�m as datas de todos os ponteiros declarados
{
    void *adress;
    int counter;
    struct memory *next;

}memory;

void clearAll(); //limpando a lista de refer�ncia
void printRefList(); //printando a lista de refer�ncia
void updateReferenceList(memory *element,int counter); //atualiza a lista de refer�ncia ap�s cada atribui��o de ponteiros
void *malloc2(int size_); //ponteiro para um espa�o de mem�ria alocado e cria um elemento na lista de refer�ncia vinculada a este ponteiro
void atrib2(void **receiver,void *transmitter); //data de transfer�ncia de um ponteiro para outro, receptor = transmissor

#endif // _CONTREF_H
