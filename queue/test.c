#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "queue.h"

static void print_queue(const Queue *queue)
{
    ListElmt           *element;

    int                *data,size,i;

    fprintf(stdout, "Queue size is %d\n", size = queue_size(queue));

    i = 0;
    element = list_head(queue);

    while (i < size)
    {
        data = list_data(element);
        fprintf(stdout, "queue[%03d]=%03d\n", i, *data);
        element = list_next(element);
        i++;
    }

    return;
}

int main()
{
    Queue              queue;
    int                *data,i;

    queue_init(&queue, free);

    fprintf(stdout, "Enqueuing 10 elements\n");

    for (i = 0; i < 10; i++)
    {

        if ((data = (int *)malloc(sizeof(int))) == NULL)
            fprintf(stdout,"Memory doesnt allocated!\n");

        *data = i + 1;

        if (queue_enqueue(&queue, data) != 0)
            fprintf(stdout,"Error!\n");

    }

    print_queue(&queue);

    fprintf(stdout, "Dequeuing 5 elements\n");

    for (i = 0; i < 5; i++)
    {
        if (queue_dequeue(&queue, (void **)&data) == 0)
            free(data);

        else
            fprintf(stdout,"Error!\n");
    }

    print_queue(&queue);

    fprintf(stdout, "Enqueuing 100 and 200\n");

    if ((data = (int *)malloc(sizeof(int))) == NULL)
        fprintf(stdout,"Memory doesnt allocated!\n");

    *data = 100;

    if (queue_enqueue(&queue, data) != 0)
        fprintf(stdout,"Error!\n");

    if ((data = (int *)malloc(sizeof(int))) == NULL)
        fprintf(stdout,"Memory doesnt allocated!\n");

    *data = 200;

    if (queue_enqueue(&queue, data) != 0)
        fprintf(stdout,"Error!\n");

    print_queue(&queue);

    if ((data = queue_peek(&queue)) != NULL)
        fprintf(stdout, "Peeking at the head element...Value=%03d\n", *data);

    else
        fprintf(stdout, "Peeking at the head element...Value=NULL\n");

    print_queue(&queue);

    fprintf(stdout, "Dequeuing all elements\n");

    while (queue_size(&queue) > 0)
    {
        if (queue_dequeue(&queue, (void **)&data) == 0)
            free(data);
    }

    if ((data = queue_peek(&queue)) != NULL)
        fprintf(stdout, "Peeking at an empty queue...Value=%03d\n", *data);

    else
       fprintf(stdout, "Peeking at an empty queue...Value=NULL\n");

    fprintf(stdout, "Destroying the queue\n");
        queue_destroy(&queue);

    return 0;
}
