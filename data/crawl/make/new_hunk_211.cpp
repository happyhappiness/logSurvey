            char *template, *tmpdir;

            if (stdin_nm)
              O (fatal, NILF,
                 _("Makefile from standard input specified twice."));

#ifdef VMS
# define DEFAULT_TMPDIR     "sys$scratch:"
