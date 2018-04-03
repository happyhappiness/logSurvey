    /* Do it only once.  */
    return;

  /* Print this untranslated.  The coding standards recommend translating the
     (C) to the copyright symbol, but this string is going to change every
     year, and none of the rest of it should be translated (including the
     word "Copyright", so it hardly seems worth it.  */

  printf ("%sGNU Make %s\n\
%sCopyright (C) 2002  Free Software Foundation, Inc.\n",
          precede, version_string, precede);

  printf (_("%sThis is free software; see the source for copying conditions.\n\
%sThere is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A\n\
%sPARTICULAR PURPOSE.\n"),
            precede, precede, precede);

  printed_version = 1;

