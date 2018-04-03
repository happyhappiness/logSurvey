  child->efn = 0;
  while (child->efn < 32 || child->efn > 63)
    {
      status = lib$get_ef(&child->efn);
      if (!(status & 1))
	return 0;
    }

  sys$clref(child->efn);

  vms_jobsefnmask |= (1 << (child->efn - 32));

#ifndef DONTWAITFORCHILD
  status = lib$spawn(&cmddsc,0,0,&spflags,0,&child->pid,&child->cstatus,
		       &child->efn,0,0);
  vmsHandleChildTerm(child);
#else
  status = lib$spawn(&cmddsc,0,0,&spflags,0,&child->pid,&child->cstatus,
		       &child->efn,vmsHandleChildTerm,child);
#endif

  if (!(status & 1))
    {
      printf(_("Error spawning, %d\n"),status);
      fflush(stdout);
    }

  unlink (comname);

  return (status & 1);
}
