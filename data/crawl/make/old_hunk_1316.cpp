    }

  /* No `endef'!!  */
  makefile_fatal (filename, lineno, "missing `endef', unterminated `define'");

  /* NOTREACHED */
  return 0;
}

/* Interpret conditional commands "ifdef", "ifndef", "ifeq",
