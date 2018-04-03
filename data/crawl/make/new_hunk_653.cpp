static char *
func_sort (char *o, char **argv, const char *funcname UNUSED)
{
  const char *t;
  char **words;
  int wordi;
  char *p;
  unsigned int len;
  int i;

  /* Find the maximum number of words we'll have.  */
  t = argv[0];
  wordi = 1;
  while (*t != '\0')
    {
      char c = *(t++);

      if (! isspace ((unsigned char)c))
        continue;

      ++wordi;

      while (isspace ((unsigned char)*t))
        ++t;
    }

  words = xmalloc (wordi * sizeof (char *));

  /* Now assign pointers to each string in the array.  */
  t = argv[0];
  wordi = 0;
  while ((p = find_next_token (&t, &len)) != 0)
    {
      ++t;
      p[len] = '\0';
      words[wordi++] = p;
    }

  if (wordi)
    {
      /* Now sort the list of words.  */
      qsort (words, wordi, sizeof (char *), alpha_compare);

      /* Now write the sorted list, uniquified.  */
      for (i = 0; i < wordi; ++i)
        {
          len = strlen (words[i]);
          if (i == wordi - 1 || strlen (words[i + 1]) != len
              || strcmp (words[i], words[i + 1]))
            {
              o = variable_buffer_output (o, words[i], len);
              o = variable_buffer_output (o, " ", 1);
            }
        }

      /* Kill the last space.  */
      --o;
    }

  free (words);

