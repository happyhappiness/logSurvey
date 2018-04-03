     register struct variable_set *set;
     char *prefix;
{
  register unsigned int i, nvariables, per_bucket;
  register struct variable *v;

  per_bucket = nvariables = 0;
  for (i = 0; i < set->buckets; ++i)
    {
      register unsigned int this_bucket = 0;

      for (v = set->table[i]; v != 0; v = v->next)
	{
	  ++this_bucket;
	  print_variable (v, prefix);
	}

      nvariables += this_bucket;
      if (this_bucket > per_bucket)
	per_bucket = this_bucket;
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
#endif
    }
}


/* Print the data base of variables.  */

void
