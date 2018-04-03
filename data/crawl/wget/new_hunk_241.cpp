  create_image (bp, dltime, true);
  display_image (bp->buffer);

  logputs (LOG_VERBOSE, "\n");
  logputs (LOG_PROGRESS, "\n");

  xfree (bp->buffer);
  xfree (bp);
