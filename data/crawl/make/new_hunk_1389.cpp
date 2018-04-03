      text = expand_argument (text, end);

      p2 = text;
      while (*p2 != '\0')
	{
          while (isspace(*p2))
            ++p2;
          p = p2;
          for (i=0; *p2 != '\0' && !isspace(*p2); ++p2, ++i)
            {}
          if (!i)
            break;
	  o = variable_buffer_output (o, p, i);
	  o = variable_buffer_output (o, " ", 1);
	  doneany = 1;
