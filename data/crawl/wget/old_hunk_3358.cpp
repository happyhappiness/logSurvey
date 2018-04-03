    }
  else if (status == 0)
    {
      fprintf (stderr, "Invalid command `%s'\n", opt);
      exit (2);
    }
}

/* Generic helper functions, for use with `commands'. */

static int myatoi PARAMS ((const char *s));

/* Store the boolean value from VAL to CLOSURE.  COM is ignored,
   except for error messages.  */
