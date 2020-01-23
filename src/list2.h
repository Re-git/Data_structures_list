#ifndef __LIST2
#define __LIST2

struct List
{
    struct Node* head;
};

struct Node
{
    int value;
    struct Node* next;
};

// typedef struct List List;
typedef struct Node Node;

#endif// __LIST2

