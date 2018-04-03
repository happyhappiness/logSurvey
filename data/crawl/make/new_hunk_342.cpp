
      /* Run each pattern through the words, killing words.  */
      for (pp = pathead; pp != 0; pp = pp->next)
        {
          if (pp->percent)
            for (wp = wordhead; wp != 0; wp = wp->next)
              wp->matched |= pattern_matches (pp->str, pp->percent, wp->str);
          else if (hashing)
            {
              struct a_word a_word_key;
              a_word_key.str = pp->str;
              a_word_key.length = pp->length;
              wp = hash_find_item (&a_word_table, &a_word_key);
              while (wp)
                {
                  wp->matched |= 1;
                  wp = wp->chain;
                }
            }
          else
            for (wp = wordhead; wp != 0; wp = wp->next)
              wp->matched |= (wp->length == pp->length
                              && strneq (pp->str, wp->str, wp->length));
        }

      /* Output the words that matched (or didn't, for filter-out).  */
      for (wp = wordhead; wp != 0; wp = wp->next)
        if (is_filter ? wp->matched : !wp->matched)
          {
            o = variable_buffer_output (o, wp->str, strlen (wp->str));
            o = variable_buffer_output (o, " ", 1);
            doneany = 1;
          }

      if (doneany)
        /* Kill the last space.  */
        --o;
    }

  if (hashing)
