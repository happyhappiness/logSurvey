      switch (*p)
        {
        case '$':
          /* $$ seen means output one $ to the variable output buffer.  */
          o = variable_buffer_output (o, p, 1);
          break;

        case '(':
