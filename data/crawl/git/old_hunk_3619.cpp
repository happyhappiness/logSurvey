#include "commit.h"
#include "prio-queue.h"

void clear_prio_queue(struct prio_queue *queue)
{
	free(queue->array);
