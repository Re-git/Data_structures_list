#include "list.h"
#include "readfile.h"
#include <stdlib.h>
#include <stdio.h>

// Uncomment to run debug verstion
#define DEBUG

void test_list()
{
    List * lista = create_list();
    append_to_list(lista,1);
    append_to_list(lista,2);
    append_to_list(lista,3);
    insert_to_list(lista, 9, 0);
    insert_to_list(lista, 11, 1);
    remove_nth_element(lista, 1);
    get_nth_element(lista, 0);
    clear_list(lista);
    count_elements(lista);
    destroy_list(&lista);
}

int main(int argc, char const* argv[])
{
    // test_list();

    List* lista = create_list();
    parse_file("instrukcje.txt", lista);
    destroy_list(&lista);
    // printf("%p\n", lista);
}
// bez sort i reverse jest 5.0
// jesli nie ma wyciekow pamieci

/*  TODO:
           - fix number of instruction that is get from file 
             (currently it counts intructions and args -> should be only instructions CHAR)
           - list clearing all elements memory
           - test with memcheck (valgrind)
           - fill switch with all of the functions

*/