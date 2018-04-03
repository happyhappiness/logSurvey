	    printf ("Live child 0x%08lx PID %d%s\n",
		    (unsigned long int) c,
		    c->pid, c->remote ? " (remote)" : "");
#ifdef VMS
	  break;
#endif
	}

      /* First, check for remote children.  */
