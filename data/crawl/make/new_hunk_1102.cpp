  }

  if (debug_flag)
    printf (_("Released token `%c' for child 0x%08lx (%s).\n"),
            child->job_token, (unsigned long int) child, child->file->name);

  child->job_token = '-';
