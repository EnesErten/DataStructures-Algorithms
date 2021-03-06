#include <stdio.h>
#include <stdlib.h>
#include "clist.h"

static void print_list(const CList *list)
{
    CListElmt          *element;
    int                *data,size,i;

    fprintf(stdout, "List size is %d (circling twice)\n", clist_size(list));

    size = clist_size(list);
    element = clist_head(list);
    i = 0;

    while (i < size * 2)
    {

        data = clist_data(element);
        fprintf(stdout, "list[%03d]=%03d\n", (i % size), *data);
        element = clist_next(element);
        i++;

    }

    return;
}

int main()
{
    CList              list;
    CListElmt          *element;

    int                *data,i;

    clist_init(&list, free);
    element = clist_head(&list);

    for (i = 0; i < 10; i++)
    {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            fprintf(stdout,"Memory Does not allocated\n");

        *data = i + 1;

        if (clist_ins_next(&list, element, data) != 0)
            fprintf(stdout,"Element does not inserted to the list\n");

        if (element == NULL)
            element = clist_next(clist_head(&list));

        else
            element = clist_next(element);

    }

    print_list(&list);

    element = clist_head(&list);

    for (i = 0; i < 10; i++)
        element = clist_next(element);

    data = clist_data(element);
    fprintf(stdout, "Circling and removing an element after the one containing %03d\n",*data);

    if (clist_rem_next(&list, element, (void **)&data) != 0)
        fprintf(stdout,"Element could not removed\n");

    free(data);

    print_list(&list);

    element = clist_head(&list);

    for (i = 0; i < 15; i++)
        element = clist_next(element);

    data = clist_data(element);
    fprintf(stdout, "Circling and inserting 011 after the element containing %03d\n", *data);

    if ((data = (int *)malloc(sizeof(int))) == NULL)
        fprintf(stdout,"Memory Does not allocated\n");

    *data = 11;

    if (clist_ins_next(&list, element, data) != 0)
        fprintf(stdout,"Memory Does not allocated\n");

    print_list(&list);

    fprintf(stdout, "Destroying the list\n");

    clist_destroy(&list);

    return 0;
}

