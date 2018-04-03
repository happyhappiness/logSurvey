      sprintf (a, "%s:%lu", flocp->filenm, flocp->lineno);
      nm = a;
    }
  message (0, _("%s: recipe for target `%s' failed"), nm, file->name);

#ifdef VMS
  if (!(exit_code & 1))
