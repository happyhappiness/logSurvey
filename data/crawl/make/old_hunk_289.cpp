        filename = expanded;
    }

  ebuf.fp = fopen (filename, "r");
  /* Save the error code so we print the right message later.  */
  makefile_errno = errno;

  /* If the makefile wasn't found and it's either a makefile from
     the 'MAKEFILES' variable or an included makefile,
     search the included makefile search path for this makefile.  */
