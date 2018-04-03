    /* Do it only once.  */
    return;

  printf ("%sGNU Make version %s", precede, version_string);
  if (remote_description != 0 && *remote_description != '\0')
    printf ("-%s", remote_description);

  printf (_(", by Richard Stallman and Roland McGrath.\n\
%sBuilt for %s\n\
%sCopyright (C) 2002  Free Software Foundation, Inc.\n\
%sThis is free software; see the source for copying conditions.\n\
%sThere is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A\n\
%sPARTICULAR PURPOSE.\n\n\
%sReport bugs to <bug-make@gnu.org>.\n\n"),
          precede, make_host,
	  precede, precede, precede, precede, precede);

  printed_version = 1;

