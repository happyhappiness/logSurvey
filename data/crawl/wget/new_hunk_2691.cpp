  fclose (fp);
}

/* Save cookies, in format described above, to FILE. */

void
cookie_jar_save (struct cookie_jar *jar, const char *file)
{
  FILE *fp;
  hash_table_iterator iter;

  DEBUGP (("Saving cookies to %s.\n", file));

