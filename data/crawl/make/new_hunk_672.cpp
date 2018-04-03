	++p;
    }

  if (abuf)
    free (abuf);

  variable_buffer_output (o, "", 1);
  return (variable_buffer + line_offset);
}

