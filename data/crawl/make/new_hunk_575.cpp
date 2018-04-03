    *comment = '\0';
}

/* Execute a `undefine' directive.
   The undefine line has already been read, and NAME is the name of
   the variable to be undefined. */

static void
do_undefine (char *name, enum variable_origin origin, struct ebuffer *ebuf)
{
  char *p, *var;

  /* Expand the variable name and find the beginning (NAME) and end.  */
  var = allocated_variable_expand (name);
  name = next_token (var);
  if (*name == '\0')
    fatal (&ebuf->floc, _("empty variable name"));
  p = name + strlen (name) - 1;
  while (p > name && isblank ((unsigned char)*p))
    --p;
  p[1] = '\0';

  undefine_variable_global (name, p - name + 1, origin);
}

/* Execute a `define' directive.
   The first line has already been read, and NAME is the name of
   the variable to be defined.  The following lines remain to be read.  */
