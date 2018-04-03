    }

  if (nvariables == 0)
    puts (_("# No variables."));
  else
    {
      printf (_("# %u variables in %u hash buckets.\n"),
	      nvariables, set->buckets);
#ifndef	NO_FLOAT
      printf (_("# average of %.1f variables per bucket, \
max %u in one bucket.\n"),
	      (double) nvariables / (double) set->buckets,
	      per_bucket);
#else
      {
	int f = (nvariables * 1000 + 5) / set->buckets;
	printf (_("# average of %d.%d variables per bucket, \
max %u in one bucket.\n"),
	      f/10, f%10,
	      per_bucket);
      }
