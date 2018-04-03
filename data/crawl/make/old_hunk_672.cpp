	++p;
    }

  if (save_char)
    string[length] = save_char;

  (void)variable_buffer_output (o, "", 1);
  return (variable_buffer + line_offset);
}

