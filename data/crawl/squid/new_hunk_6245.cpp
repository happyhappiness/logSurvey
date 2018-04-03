static long fqdncache_low = 180;
static long fqdncache_high = 200;

/* removes the given fqdncache entry */
static void
fqdncache_release(fqdncache_entry * f)
