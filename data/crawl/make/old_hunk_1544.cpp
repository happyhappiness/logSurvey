	}

      if (count >= 0)
	makefile_fatal (reading_filename, *reading_lineno_ptr,
			"unterminated call to function `%s': missing `%c'",
			function_table[code].name, closeparen);

      /* We found the end; expand the function call.  */

