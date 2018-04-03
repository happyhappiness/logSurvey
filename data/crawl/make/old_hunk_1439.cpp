	  exit_code = dos_status;
	  exit_sig = 0;
	  coredump = 0;
#else
	  /* Same on Amiga */
	  pid = amiga_pid - 1;
	  status = amiga_status;
	  exit_code = amiga_status;
	  exit_sig = 0;
	  coredump = 0;
#endif
#endif	/* Not MSDOS.  */
	}
      else
