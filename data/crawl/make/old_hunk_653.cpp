static char *
func_sort (char *o, char **argv, const char *funcname UNUSED)
{
  char **words = 0;
  int nwords = 0;
  register int wordi = 0;

  /* Chop ARGV[0] into words and put them in WORDS.  */
  char *t = argv[0];
  char *p;
  unsigned int len;
  int i;

  while ((p = find_next_token (&t, &len)) != 0)
    {
      if (wordi >= nwords - 1)
	{
	  nwords = (2 * nwords) + 5;
	  words = xrealloc (words, nwords * sizeof (char *));
	}
      words[wordi++] = savestring (p, len);
    }

  if (!wordi)
    return o;

  /* Now sort the list of words.  */
  qsort (words, wordi, sizeof (char *), alpha_compare);

  /* Now write the sorted list.  */
  for (i = 0; i < wordi; ++i)
    {
      len = strlen (words[i]);
      if (i == wordi - 1 || strlen (words[i + 1]) != len
          || strcmp (words[i], words[i + 1]))
        {
          o = variable_buffer_output (o, words[i], len);
          o = variable_buffer_output (o, " ", 1);
        }
      free (words[i]);
    }
  /* Kill the last space.  */
  --o;

  free (words);

