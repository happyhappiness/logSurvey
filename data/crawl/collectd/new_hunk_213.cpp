
  status = lcc_getval (c, &ident,
      &ret_values_num, &ret_values, &ret_values_names);
  if (status != 0) {
    fprintf (stderr, "ERROR: %s\n", lcc_strerror (c));
    BAIL_OUT (-1);
  }

  for (i = 0; i < ret_values_num; ++i)
    printf ("%s=%e\n", ret_values_names[i], ret_values[i]);
