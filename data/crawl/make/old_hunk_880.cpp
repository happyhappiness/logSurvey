#if defined (SIGNOFP)
  init_sig (SIGNOFP, "NOFP", _("Floating point co-processor not available"));
#endif
}

/* Return the abbreviation for signal NUMBER.  */

char *
sig_abbrev (number)
     int number;
{
  int i;

  if (sig_table_nelts == 0)
    signame_init ();

  for (i = 0; i < sig_table_nelts; i++)
    if (sig_table[i].number == number)
      return (char *)sig_table[i].abbrev;
  return NULL;
}

/* Return the signal number for an ABBREV, or -1 if there is no
   signal by that name.  */

int
sig_number (abbrev)
     const char *abbrev;
{
  int i;

  if (sig_table_nelts == 0)
    signame_init ();

  /* Skip over "SIG" if present.  */
  if (abbrev[0] == 'S' && abbrev[1] == 'I' && abbrev[2] == 'G')
    abbrev += 3;

  for (i = 0; i < sig_table_nelts; i++)
    if (abbrev[0] == sig_table[i].abbrev[0]
	&& strcmp (abbrev, sig_table[i].abbrev) == 0)
      return sig_table[i].number;
  return -1;
}

#ifndef HAVE_PSIGNAL
/* Print to standard error the name of SIGNAL, preceded by MESSAGE and
   a colon, and followed by a newline.  */

void
psignal (signal, message)
     int signal;
     const char *message;
{
  if (signal <= 0 || signal >= NSIG)
    fprintf (stderr, "%s: unknown signal", message);
  else
    fprintf (stderr, "%s: %s\n", message, sys_siglist[signal]);
}
#endif

#ifndef HAVE_STRSIGNAL
/* Return the string associated with the signal number.  */

char *
strsignal (signal)
