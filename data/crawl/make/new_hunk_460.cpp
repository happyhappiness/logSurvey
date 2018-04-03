      if (nlines < 0)
        break;

      line = ebuf->buffer;

      /* If this is the first line, check for a UTF-8 BOM and skip it.  */
      if (ebuf->floc.lineno == 1 && line[0] == (char)0xEF
          && line[1] == (char)0xBB && line[2] == (char)0xBF)
        {
          line += 3;
          if (ISDB(DB_BASIC))
            {
              if (ebuf->floc.filenm)
                printf (_("Skipping UTF-8 BOM in makefile '%s'\n"),
                        ebuf->floc.filenm);
              else
                printf (_("Skipping UTF-8 BOM in makefile buffer\n"));
            }
        }

      /* If this line is empty, skip it.  */
      if (line[0] == '\0')
        continue;

