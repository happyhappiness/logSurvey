	{
	  /* The child finished normally.  Replace all newlines in its output
	     with spaces, and put that in the variable output buffer.  */
	  fold_newlines (buffer, &i, trim_newlines);
	  o = variable_buffer_output (o, buffer, i);
	}

