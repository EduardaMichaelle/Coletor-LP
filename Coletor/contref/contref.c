#include <stdio.h>
#include <stdlib.h>
#include "contref.h"

memory *ref_list=NULL; //variável global para a inicialização da lista de referência

void clearAll() //executa toda a lista removendo cada elemento para liberar espaço antes de terminar o programa
{
    memory *aux=ref_list;
    while (aux!=NULL)
    {
        free(aux->adress);
        free(aux);
        aux=aux->next;
    }
}

void printRefList() //executa toda a lista imprimindo seus elementos
{
    memory *aux=ref_list;
    while (aux!=NULL)
    {
        printf("adress:%d\t",aux->adress);
        printf("ref:%d\n",aux->counter);
        aux=aux->next;
    }
}

void updateReferenceList(memory *element, int counter)  //atualiza a quantidade de referências a um ponteiro

    element->counter += counter;
    if (element->counter == 0)
    {
        if (ref_list->next != NULL)
        {
            memory *runner = ref_list;
            if (runner !=element)
            {
                while (runner->next != element)
                {
                    runner = runner->next;
                }
                runner->next = element->next;
            }
            else
            {
                ref_list = element->next;
            }
        }
        free(element->adress);
        free(element);
    }

void *malloc2(int size_) //ponteiro para um espaço de memória alocado e cria um elemento na lista de referência vinculada a este ponteiro
{
    void *new_allocated_memory = (void *)malloc(size_);
    memory *new_reference_list_element = (memory *)malloc(sizeof(memory));
    new_reference_list_element->adress = new_allocated_memory;
    new_reference_list_element->counter = 1;
    new_reference_list_element->next = NULL;
    if (ref_list == NULL)
    {
        ref_list= new_reference_list_element;
    }
    else
    {
        memory *aux = ref_list;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = new_reference_list_element;
    }
    return new_allocated_memory;
}

void atrib2(void **receiver, void *transmitter) //transferindo data de um ponteiro para outro
{                                               //faz o controle das referências aos ponteiros
    if ((*receiver) != NULL)
    {
        memory *run_list = ref_list;
        while (run_list->adress != (*receiver))
        {
            run_list = run_list->next;
        }
        updateReferenceList(run_list, -1);
        if (transmitter != NULL)
        {
            (*receiver) = transmitter;
            run_list = ref_list;
            while (run_list->adress !=transmitter)
            {
                run_list = run_list->next;
            }
            updateReferenceList(run_list, 1);
        }
        else
        {
            (*receiver)=NULL;
        }
    }
}
