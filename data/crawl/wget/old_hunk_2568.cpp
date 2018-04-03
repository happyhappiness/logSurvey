    {
    case line_ok:
      if (!setval_internal (comind, com, val))
	exit (2);
      xfree (com);
      xfree (val);
      break;
    default:
      fprintf (stderr, _("%s: Invalid --execute command `%s'\n"),
	       exec_name, opt);
      exit (2);
    }
}
