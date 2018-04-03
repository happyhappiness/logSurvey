
  logputs (LOG_VERBOSE, "\n");

  create_image (bp, 0);
  display_image (bp->buffer);

  return bp;
}

static void update_speed_ring (struct bar_progress *, wgint, double);

static void
bar_update (void *progress, wgint howmuch, double dltime)
