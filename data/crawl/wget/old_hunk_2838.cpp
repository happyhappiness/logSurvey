    {
      fprintf (stderr, _("%s: %s: Invalid byte value `%s'\n"),
	       exec_name, com, val);
      return 0;
    }
  *(wgint *)place = (wgint)byte_value;
  return 1;
}

/* Like cmd_bytes, but PLACE is interpreted as a pointer to
