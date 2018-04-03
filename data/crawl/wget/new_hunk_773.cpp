  DEBUGP (("Enqueuing %s at depth %d\n", url, depth));
  DEBUGP (("Queue count %d, maxcount %d.\n", queue->count, queue->maxcount));

  /*printf ("[Enqueuing %s with %s\n", url, qel->remote_encoding);*/

  if (queue->tail)
    queue->tail->next = qel;
  queue->tail = qel;
