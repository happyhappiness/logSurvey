
  OUTPUT_SET (&child->output);

  message (0, l + strlen (nm),
           _("%s: recipe for target '%s' failed"), nm, f->name);

  l += strlen (pre) + strlen (post);

#ifdef VMS
  if ((exit_code & 1) != 0)
