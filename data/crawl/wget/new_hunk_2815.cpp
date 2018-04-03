    /* See bar_update() for explanation. */
    bp->total_length = bp->initial_length + bp->count;

  create_image (bp, dltime, true);
  display_image (bp->buffer);

  logputs (LOG_VERBOSE, "\n\n");
