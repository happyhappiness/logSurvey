    if (memcmp (record_start->buffer, p->magic, p->length) == 0)
      return p->type;

  return ct_none;
}

