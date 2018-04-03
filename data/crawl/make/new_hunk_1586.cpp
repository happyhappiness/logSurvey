  c->command_line = 0;
  c->command_ptr = 0;
  c->environment = 0;

  start_waiting_job (c);

  if (job_slots == 1)
    /* Since there is only one job slot, make things run linearly.
