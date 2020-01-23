#include "readfile.h"
#include "list2.h"
#include "list.h"

int read_number(FILE * file, int * value)
{
    char* p_end;
    char buff[256];
    fscanf(file, "%s", buff);
    *value = strtol(buff,&p_end,10);
    if(p_end != buff)
            {
                return 1;
            }
            else
            {
                return 0;
            }
}

int read_char(FILE * file, char * value)
{
    char* p_end;
    char buff[256];
    fscanf(file, "%s", buff);
    *value = strtol(buff,&p_end,10);
    if(p_end != buff)
            {
                printf("Error - expected char but got int instead\n");
                return 0;
            }
            else
            {
                *value=buff[0];
                return -1;
            }
}

void parse_file(const char* file_path,  List* lista)
{
    FILE * file = NULL;
    char buff[32];
    // int value;
    char ch;
    int num_of_instr;

    file = fopen(file_path, "r");
    if(file)
    {
        fscanf(file, "%s", buff);
        num_of_instr = strtol(buff, 0, 10);
        printf("I expect %d elements\n", num_of_instr);
        for (int i = 0; i < num_of_instr;)
        {
            if(read_char(file, &ch))
            {
                // container for numerical args
                int args[2] = {0};

                // printf("%c\n", ch);

                switch (ch)
                {
                case 'p':
                    {
                        i++;
                        int list_count = count_elements(lista);
                        printf(":");
                        for (int i = 0; i < list_count; i++)
                        {
                            printf("%d ", get_nth_element(lista,i));
                        }      
                        printf("\n");
                    }
                    break;

                case 'a':
                    {
                        i++;
                        read_number(file, &args[0]);
                        // printf("%d\n", args[0]);
                        append_to_list(lista, args[0]);
                    }
                    break;
                
                case 'c':
                    {
                        i++;
                        clear_list(lista);
                    }
                    break;

                case 'i':
                {
                    i++;
                    for(int j=0;j<2;j++)
                    {
                        if(!read_number(file, &args[j]))
                        {
                            printf("Expcted number but got something else");
                        }
                    }
                    insert_to_list(lista, args[1], args[0]);
                    // printf("args[0] = %d\n", args[0]);
                    // printf("args[1] = %d\n", args[1]);
                }
                break;
                    
                case 'd':
                {
                    i++;
                    read_number(file, &args[0]);
                    remove_nth_element(lista, args[0]);
                }
                break;

                case 's':
                {
                    i++;
                    printf("sort - not implemented");                    
                }
                break;
                
                case 'r':
                {
                    i++;
                    printf("reverse - not implemented");                    
                }
                break;

                default:
                    break;
                }
            }
        }        
        fclose(file);
    }
    else
        {
            printf("Failed to open file.\n");
        }
    }

