
  bp->initial_length = initial;
  bp->total_length   = total;
  bp->width = screen_width;
  bp->buffer = xmalloc (bp->width + 1);

  logputs (LOG_VERBOSE, "\n\n");

  create_image (bp, 0);
  display_image (bp->buffer);
