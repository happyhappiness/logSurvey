
  OUTPUT_SET (&child->output);

  message (0, _("%s: recipe for target '%s' failed"), nm, f->name);

#ifdef VMS
  if ((exit_code & 1) != 0)
