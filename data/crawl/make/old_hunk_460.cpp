      if (nlines < 0)
        break;

      /* If this line is empty, skip it.  */
      line = ebuf->buffer;
      if (line[0] == '\0')
        continue;

