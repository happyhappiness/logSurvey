  return 1;
}

/* Directory contents, only for GNUTYPE_DUMPDIR.  */

static char *dumpdir_cursor;

static int
process_dumpdir (size_t bytes, char *buffer)
{
  if (memcmp (buffer, dumpdir_cursor, bytes))
    {
      report_difference (&current_stat_info, _("Contents differ"));
      return 0;
    }

  dumpdir_cursor += bytes;
  return 1;
}

/* Some other routine wants SIZE bytes in the archive.  For each chunk
   of the archive, call PROCESSOR with the size of the chunk, and the
   address of the chunk it can work with.  The PROCESSOR should return
   nonzero for success.  It it return error once, continue skipping
   without calling PROCESSOR anymore.  */

static void
