        restrict_case = restrict_uppercase;
      else if (VAL_IS ("nocontrol"))
        restrict_ctrl = false;
      else if (VAL_IS ("ascii"))
        restrict_nonascii = true;
      else
        {
          fprintf (stderr, _("\
%s: %s: Invalid restriction %s,\n\
    use [unix|windows],[lowercase|uppercase],[nocontrol],[ascii].\n"),
                   exec_name, com, quote (val));
          return false;
        }
