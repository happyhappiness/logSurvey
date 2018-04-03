	  else
	    printf ("%s[%u]: ", program, makelevel);
	}
      va_start (args, fmt);
      vfprintf (stdout, fmt, args);
      va_end (args);
      putchar ('\n');

      if (output_sync)
