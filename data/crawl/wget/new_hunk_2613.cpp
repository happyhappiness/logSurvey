{
  printf ("GNU Wget %s\n\n", version_string);
  fputs (_("\
Copyright (C) 2007 Free Software Foundation, Inc.\n"), stdout);
  fputs (_("\
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n\
This is free software: you are free to change and redistribute it.\n\
There is NO WARRANTY, to the extent permitted by law.\n", stdout);
  fputs (_("\nOriginally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"),
         stdout);
  fputs (_("Currently maintained by Micah Cowan <micah@cowan.name>.\n"),
         stdout);
  exit (0);
}
