    if (memcmp (record_start->buffer, p->magic, p->length) == 0)
      return p->type;

  if (short_file)
    ERROR ((0, 0, _("This does not look like a tar archive")));

  return ct_none;
}

