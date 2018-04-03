      DWORD susp_count = SuspendThread (main_thread);

      if (susp_count != 0)
	fprintf (stderr, "SuspendThread: suspend count = %ld\n", susp_count);
      else if (susp_count == (DWORD)-1)
	{
	  DWORD ierr = GetLastError ();

	  fprintf (stderr, "SuspendThread: error %ld: %s\n",
		   ierr, map_windows32_error_to_string (ierr));
	}
    }
#endif
  handling_fatal_signal = 1;
