
  if (*len)
    {
      print_length (*len, restval, 1);
      expected_bytes = *len;	/* for get_contents/show_progress */
    }
  else if (expected_bytes)
    print_length (expected_bytes, restval, 0);

  /* Get the contents of the document.  */
  flags = 0;
