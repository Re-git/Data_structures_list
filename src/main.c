#include "list2.h"
#include "list.h"
#include "readfile.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const* argv[])
{

    List* lista = create_list();
    parse_file("instrukcje.txt", lista);
    destroy_list(&lista);
}
