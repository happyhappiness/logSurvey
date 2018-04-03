  register unsigned int i, nfiles, per_bucket;
  register struct file *file;

  puts ("\n# Files");

  per_bucket = nfiles = 0;
  for (i = 0; i < FILE_BUCKETS; ++i)
