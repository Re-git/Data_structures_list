#include "list.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const* argv[])
{

    List* A = create_list();
    List* B = create_list();
    append_to_list(A, 1);
    append_to_list(A, 2);
    append_to_list(B, 3);
    append_to_list(B, 4);

    int list_countA = count_elements(A);
    printf(":");
    for (int i = 0; i < list_countA; i++)
    {
        printf("%d ", get_nth_element(A,i));
    }
          
    int list_countB = count_elements(B);
    printf(":");
    for (int i = 0; i < list_countB; i++)
    {
        printf("%d ", get_nth_element(B,i));
    }

    destroy_list(&A);
    destroy_list(&B);
}
