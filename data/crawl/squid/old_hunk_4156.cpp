	  fprintf(stderr, "%s| %s: fgets() failed! dying..... errno=%d (%s)\n", LogTime(), PROGRAM, ferror(stdin),
		 strerror(ferror(stdin)));

	exit(1);    /* BIIG buffer */
      }
      exit(0);
    }

