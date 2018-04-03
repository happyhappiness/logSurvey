	  any_remote |= c->remote;
	  any_local |= ! c->remote;
	  if (debug_flag)
	    printf ("Live child 0x%08lx PID %ld%s\n",
		    (unsigned long int) c,
		    (long) c->pid, c->remote ? " (remote)" : "");
#ifdef VMS
	  break;
#endif
