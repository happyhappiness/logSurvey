    }

  /* Writing succeeded. */
  if (save_context_p)
    saved_append (write_ptr);
  FPUTS (write_ptr, fp);
  if (warcfp != NULL)
    FPUTS (write_ptr, warcfp);
  if (state->bigmsg)
    xfree (state->bigmsg);

