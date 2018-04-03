	    for (wp = words; wp != 0; wp = wp->next)
	      if (function == function_filter ? wp->matched : !wp->matched)
		{
		  o = variable_buffer_output (o, wp->str, strlen (wp->str));
		  o = variable_buffer_output (o, " ", 1);
		  doneany = 1;
		}
