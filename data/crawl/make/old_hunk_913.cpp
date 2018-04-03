	       and thus re-read the makefiles, we read standard input
	       into a temporary file and read from that.  */
	    FILE *outfile;

            if (stdin_nm)
              fatal (NILF, _("Makefile from standard input specified twice."));

#ifdef VMS
# define TMP_TEMPLATE   "sys$scratch:GmXXXXXX"
#else
# define TMP_TEMPLATE   "/tmp/GmXXXXXX"
#endif

	    outfile = open_tmpfile (&stdin_nm, TMP_TEMPLATE);
	    if (outfile == 0)
	      pfatal_with_name (_("fopen (temporary file)"));
	    while (!feof (stdin))
