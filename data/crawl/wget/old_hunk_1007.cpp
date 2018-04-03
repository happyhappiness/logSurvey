  DEBUGP (("Queue count %d, maxcount %d.\n", queue->count, queue->maxcount));

  if (i)
    printf ("[Enqueuing %s with %s\n", url, i->uri_encoding);

  if (queue->tail)
    queue->tail->next = qel;
