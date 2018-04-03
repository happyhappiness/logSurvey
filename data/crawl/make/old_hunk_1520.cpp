
      /* Advance T past the string to be replaced.  */
      t = p + slen;
    }

  /* Output everything left on the end.  */
  if (*t != '\0')
    o = variable_buffer_output (o, t, strlen (t));

  return o;
}
