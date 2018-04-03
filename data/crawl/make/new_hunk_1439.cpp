	  exit_code = dos_status;
	  exit_sig = 0;
	  coredump = 0;
#endif /* __MSDOS__ */
#ifdef _AMIGA
	  /* Same on Amiga */
	  pid = amiga_pid - 1;
	  status = amiga_status;
	  exit_code = amiga_status;
	  exit_sig = 0;
	  coredump = 0;
#endif /* _AMIGA */
#ifdef WIN32
         {
           HANDLE hPID;
           int err;
    
           /* wait for anything to finish */
           if (hPID = process_wait_for_any()) {
    
             /* was an error found on this process? */
             err = process_last_err(hPID);
    
             /* get exit data */
             exit_code = process_exit_code(hPID);
    
             if (err)
               fprintf(stderr, "make (e=%d): %s",
                       exit_code, map_win32_error_to_string(exit_code));
    
             exit_sig = process_signal(hPID);
    
             /* cleanup process */
             process_cleanup(hPID);
    
             if (dos_batch_file) {
               remove (dos_bname);
               remove (dos_bename);
               dos_batch_file = 0;
             }
    
             coredump = 0;
           }
           pid = (int) hPID;
         }
#endif /* WIN32 */
#endif	/* Not MSDOS.  */
	}
      else
