  else if (expected_bytes)
    print_length (expected_bytes, restval, false);

  /* Get the contents of the document.  */
  flags = 0;
  if (restval && rest_failed)
