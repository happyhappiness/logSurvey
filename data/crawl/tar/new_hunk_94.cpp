  return 1;
}

/* Some other routine wants SIZE bytes in the archive.  For each chunk
   of the archive, call PROCESSOR with the size of the chunk, and the
   address of the chunk it can work with.  The PROCESSOR should return
   nonzero for success.  Once it returns error, continue skipping
   without calling PROCESSOR anymore.  */

static void
