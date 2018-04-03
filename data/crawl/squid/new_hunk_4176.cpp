	  fprintf(stderr, "%s| %s: fgets() failed! dying..... errno=%d (%s)\n", LogTime(), PROGRAM, ferror(stdin),
		 strerror(ferror(stdin)));

        fprintf(stdout, "BH input error\n");
	exit(1);    /* BIIG buffer */
      }
      fprintf(stdout, "BH input error\n");
      exit(0);
    }

