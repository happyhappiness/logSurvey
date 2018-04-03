	  /* If the job failed, and the -k flag was not given, die.  */
	  if (child_failed && !keep_going_flag)
	    die (1);
	}

      /* Only block for one child.  */
      block = 0;
    }
}

/* Free the storage allocated for CHILD.  */
