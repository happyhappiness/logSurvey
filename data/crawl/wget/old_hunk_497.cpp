        restrict_case = restrict_uppercase;
      else if (VAL_IS ("nocontrol"))
        restrict_ctrl = false;
      else
        {
          fprintf (stderr,
                   _("%s: %s: Invalid restriction %s, use [unix|windows],[lowercase|uppercase],[nocontrol].\n"),
                   exec_name, com, quote (val));
          return false;
        }
