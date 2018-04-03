      xfree (val);
      break;
    default:
      fprintf (stderr, _("%s: Invalid --execute command `%s'\n"),
               exec_name, opt);
      exit (2);
    }
}
