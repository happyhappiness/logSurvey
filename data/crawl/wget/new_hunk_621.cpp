
  /* Writing succeeded. */
  saved_append (write_ptr);
  FPUTS (write_ptr, fp);
  if (state->bigmsg)
    xfree (state->bigmsg);

