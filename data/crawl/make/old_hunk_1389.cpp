      text = expand_argument (text, end);

      p2 = text;
      while ((p = find_next_token (&p2, &i)) != 0)
	{
	  o = variable_buffer_output (o, p, i);
	  o = variable_buffer_output (o, " ", 1);
	  doneany = 1;
