                      &child->pid, &child->cstatus, &child->efn,
                      vmsHandleChildTerm, child,
                      0, 0, 0);
#endif

  if (!(status & 1))
    {
      printf (_("Error spawning, %d\n") ,status);
      fflush (stdout);
      switch (status)
        {
        case 0x1c:
          errno = EPROCLIM;
          break;
        default:
