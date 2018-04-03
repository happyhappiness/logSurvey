  switch (v->origin)
    {
    case o_default:
      origin = "default";
      break;
    case o_env:
      origin = "environment";
      break;
    case o_file:
      origin = "makefile";
      break;
    case o_env_override:
      origin = "environment under -e";
      break;
    case o_command:
      origin = "command line";
      break;
    case o_override:
      origin = "`override' directive";
      break;
    case o_automatic:
      origin = "automatic";
      break;
    case o_invalid:
    default:
      abort ();
    }
  printf ("# %s\n", origin);

  fputs (prefix, stdout);

  /* Is this a `define'?  */
