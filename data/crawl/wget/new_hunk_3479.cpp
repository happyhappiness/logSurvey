
  bp->initial_length = initial;
  bp->total_length   = total;

  /* - 1 because we don't want to use the last screen column. */
  bp->width = screen_width - 1;
  /* + 1 for the terminating zero. */
  bp->buffer = xmalloc (bp->width + 1);

  logputs (LOG_VERBOSE, "\n");
