}

static void
bar_finish (void *progress)
{
  struct bar_progress *bp = progress;
  long elapsed = wtimer_elapsed (bp->timer);

  if (elapsed == 0)
    /* If the download was faster than the granularity of the timer,
       fake some output so that we don't get the ugly "----.--" rate
       at the download finish.  */
    elapsed = 1;

  create_image (bp, elapsed);
  display_image (bp->buffer);

  logputs (LOG_VERBOSE, "\n\n");

  xfree (bp->buffer);
  wtimer_delete (bp->timer);
  xfree (bp);
}

