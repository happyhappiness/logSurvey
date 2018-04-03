
  OUTPUT_SET (&child->output);

  show_goal_error ();

  if (exit_sig == 0)
    error (NILF, l + INTSTR_LENGTH,
           _("%s[%s: %s] Error %d%s"), pre, nm, f->name, exit_code, post);
