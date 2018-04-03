
          assert(c->job_token != '-');
	  if (debug_flag)
	    printf ("Obtained token `%c' for child 0x%08lx (%s).\n",
		    c->job_token, (unsigned long int) c, c->file->name);
	}
#endif
