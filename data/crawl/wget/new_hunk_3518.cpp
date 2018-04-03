}

static void
bar_finish (void *progress, long dltime)
{
  struct bar_progress *bp = progress;

  if (dltime == 0)
    /* If the download was faster than the granularity of the timer,
       fake some output so that we don't get the ugly "----.--" rate
       at the download finish.  */
    dltime = 1;

  create_image (bp, dltime);
  display_image (bp->buffer);

  logputs (LOG_VERBOSE, "\n\n");

  xfree (bp->buffer);
  xfree (bp);
}

