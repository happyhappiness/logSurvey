               fprintf(stderr, "\nCounted %d args in failed launch\n", i);
      }
  }
#endif /* WIN32 */
#endif	/* Not MSDOS.  */

  /* We are the parent side.  Set the state to
     say the commands are running and return.  */
