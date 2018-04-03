	{
	  any_remote |= c->remote;
	  any_local |= ! c->remote;
	  DB (DB_JOBS, (_("Live child 0x%08lx (%s) PID %ld %s\n"),
                        (unsigned long int) c, c->file->name,
                        (long) c->pid, c->remote ? _(" (remote)") : ""));
#ifdef VMS
	  break;
#endif
