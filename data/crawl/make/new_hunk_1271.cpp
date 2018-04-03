	}

      if (count >= 0)
        fatal (reading_file,
               "unterminated call to function `%s': missing `%c'",
               function_table[code].name, closeparen);

      /* We found the end; expand the function call.  */

