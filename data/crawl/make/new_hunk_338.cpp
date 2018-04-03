
      tp = find_next_token (&list1_iterator, &len1);
      if (tp != 0)
        o = variable_buffer_output (o, tp, len1);

      pp = find_next_token (&list2_iterator, &len2);
      if (pp != 0)
        o = variable_buffer_output (o, pp, len2);

      if (tp != 0 || pp != 0)
        {
          o = variable_buffer_output (o, " ", 1);
          doneany = 1;
        }
    }
  while (tp != 0 || pp != 0);
  if (doneany)
