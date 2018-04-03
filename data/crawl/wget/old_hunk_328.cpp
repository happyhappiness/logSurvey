      int line_length = MAX_CHARS_PER_LINE;
      while ((line_length > 0) && (compiled_features[i] != NULL))
        {
          if (printf ("%s ", compiled_features[i]))
            exit (3);
          line_length -= strlen (compiled_features[i]) + 2;
          i++;
