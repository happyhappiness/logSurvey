	       into a temporary file and read from that.  */
	    FILE *outfile;

	    /* Make a unique filename.  */
#ifdef HAVE_MKTEMP

#ifdef VMS
	    static char name[] = "sys$scratch:GmXXXXXX";
#else
	    static char name[] = "/tmp/GmXXXXXX";
#endif
	    (void) mktemp (name);
#else
	    static char name[L_tmpnam];
	    (void) tmpnam (name);
#endif

            if (stdin_nm)
              fatal (NILF, _("Makefile from standard input specified twice."));

	    outfile = fopen (name, "w");
	    if (outfile == 0)
	      pfatal_with_name (_("fopen (temporary file)"));
	    while (!feof (stdin))
