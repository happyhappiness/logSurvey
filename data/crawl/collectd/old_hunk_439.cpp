      status = parse_option (&n, fields[i]);
      if (status != 0)
      {
	fprintf (fh, "-1 Error parsing option `%s'", fields[i]);
	break;
      }
    }
