
      if (shell_function_completed == -1)
	{
	  /* This likely means that the execvp failed, so we should just
	     write the error message in the pipe from the child.  */
	  fputs (buffer, stderr);
	  fflush (stderr);
	}
      else
	{
	  /* The child finished normally.  Replace all newlines in its output
	     with spaces, and put that in the variable output buffer.  */
	  fold_newlines (buffer, &i);
	  o = variable_buffer_output (o, buffer, i);
	}
