	++p;
    }

  if (save_char)
    string[length] = save_char;

  (void)variable_buffer_output (o, "", 1);
  return (variable_buffer + line_offset);
}

/* Scan LINE for variable references and expansion-function calls.
   Build in `variable_buffer' the result of expanding the references and calls.
   Return the address of the resulting string, which is null-terminated
   and is valid only until the next time this function is called.  */

char *
variable_expand (line)
     char *line;
{
  return variable_expand_string(NULL, line, -1);
}

/* Expand an argument for an expansion function.
