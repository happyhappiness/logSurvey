    {
    case cs_running:
      c->next = children;
      children = c;
      /* One more job slot is in use.  */
      ++job_slots_used;
