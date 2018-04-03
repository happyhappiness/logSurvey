
  /* Writing succeeded. */
  saved_append (write_ptr);
  fputs (write_ptr, logfp);
  if (state->bigmsg)
    xfree (state->bigmsg);

