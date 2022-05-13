#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEADS 1
#define TAILS 0

/* global variables */
double freq_tails, freq_heads;

typedef struct node {
    int side;
    struct node* next;
} *Coin;

/* Adds new coin to the linked list */
Coin New(Coin head, int side)
{
    Coin new = (Coin) malloc(sizeof(struct node));
    new->side = side;
    new->next = head;
    head = new;

    return head;
}

/* free allocated memory of linked list with head "head" */
void freeList(Coin head)
{
    Coin aux;

    if(head == NULL)
        return;

    while(head != NULL)
    {
        aux = head->next;
        free(head);
        head = aux;
    }
}

/* flips nth coins */
Coin flipCoins(Coin head, int n)
{
    int side;

    for(int i=0; i<n; i++)
    {
        /* random side selected */
        side = rand()%2;
        head = New(head, side);
    } 

    return head;
}

/* calculates the frequency of heads and tails */
void freqCoins(Coin head, int n_coins)
{
    Coin aux = head;
    int n_heads = 0, n_tails = 0;

    while(head != NULL)
    {
        aux = head->next;
        
        if(head->side == HEADS)
            n_heads++;
        
        else if(head->side == TAILS)
            n_tails++;

        head = aux;
    }

    freq_heads = n_heads/(double)n_coins;
    freq_tails = n_tails/(double)n_coins;

    printf("HEADS: %f TAILS: %f\n", freq_heads, freq_tails);
    
}

void freqGraph()
{

    printf("------HEADS vs TAILS------\n\n");
}

int main()
{
    int coin_num;
    Coin head = NULL;

    /* makes it random outcome different every time program is executed */
    srand(time(0));

    printf("How many coins do you want to flip?\n");
    scanf("%d", &coin_num);

    head = flipCoins(head, coin_num);

    freqCoins(head, coin_num);

    freeList(head);

    return 0;
}