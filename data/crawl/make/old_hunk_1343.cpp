    {
      printf ("\n# %u files in %u hash buckets.\n", nfiles, FILE_BUCKETS);
#ifndef	NO_FLOAT
      printf ("# average %.1f files per bucket, max %u files in one bucket.\n",
	      ((double) nfiles) / ((double) FILE_BUCKETS) * 100.0, per_bucket);
#endif
    }
}
