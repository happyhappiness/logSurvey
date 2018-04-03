	       and thus re-read the makefiles, we read standard input
	       into a temporary file and read from that.  */
	    FILE *outfile;
            char *template, *tmpdir;

            if (stdin_nm)
              fatal (NILF, _("Makefile from standard input specified twice."));

#ifdef VMS
# define DEFAULT_TMPDIR     "sys$scratch:"
#else
# ifdef P_tmpdir
#  define DEFAULT_TMPDIR    P_tmpdir
# else
#  define DEFAULT_TMPDIR    "/tmp"
# endif
#endif
#define DEFAULT_TMPFILE     "GmXXXXXX"

	    if (((tmpdir = getenv ("TMPDIR")) == NULL || *tmpdir == '\0')
#if defined __MSDOS__ || defined(WINDOWS32)
                /* These are also used commonly on these platforms.  */
                && ((tmpdir = getenv ("TEMP")) == NULL || *tmpdir == '\0')
                && ((tmpdir = getenv ("TMP")) == NULL || *tmpdir == '\0')
#endif
               )
	      tmpdir = DEFAULT_TMPDIR;

            template = (char *) alloca (strlen (tmpdir)
                                        + sizeof (DEFAULT_TMPFILE) + 1);
	    strcpy (template, tmpdir);

#if defined __MSDOS__ || defined(WINDOWS32)
	    if (strchr ("/\\", template[strlen (template) - 1]) == NULL)
	      strcat (template, "/");
#else
#ifndef VMS
	    if (template[strlen (template) - 1] != '/')
	      strcat (template, "/");
#endif /* !VMS */
#endif /* __MSDOS__ || WINDOWS32 */

	    strcat (template, DEFAULT_TMPFILE);
	    outfile = open_tmpfile (&stdin_nm, template);
	    if (outfile == 0)
	      pfatal_with_name (_("fopen (temporary file)"));
	    while (!feof (stdin))
