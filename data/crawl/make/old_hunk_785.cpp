
  /* Process the remaining rules in the double colon chain so they're marked
     considered.  Start their prerequisites, too.  */
  for (; f != 0 ; f = f->prev)
    {
      struct dep *d;

      f->considered = considered;

      for (d = f->deps; d != 0; d = d->next)
        status |= update_file (d->file, depth + 1);
    }

  return status;
}

/* Consider a single `struct file' and update it as appropriate.  */

static int
