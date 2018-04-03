      words[wordi++] = savestring (p, len);
    }

  if (wordi > 0)
    {
      int i;
      /* Now sort the list of words.  */
      qsort ((char *) words, wordi, sizeof (char *), alpha_compare);

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
    }

  free ((char *) words);
  return o;
}

