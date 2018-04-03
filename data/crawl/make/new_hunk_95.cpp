        }
      fn = next_token (fn);

      if (fn[0] == '\0')
        O (fatal, *expanding_var, _("file: missing filename"));

      ENULLLOOP (fp, fopen (fn, mode));
      if (fp == NULL)
        OSS (fatal, reading_file, _("open: %s: %s"), fn, strerror (errno));

      if (argv[1])
        {
          int l = strlen (argv[1]);
          int nl = l == 0 || argv[1][l-1] != '\n';

          if (fputs (argv[1], fp) == EOF || (nl && fputc ('\n', fp) == EOF))
            OSS (fatal, reading_file, _("write: %s: %s"), fn, strerror (errno));
        }
      if (fclose (fp))
        OSS (fatal, reading_file, _("close: %s: %s"), fn, strerror (errno));
    }
  else if (fn[0] == '<')
    {
      char *preo = o;
      FILE *fp;

      fn = next_token (++fn);
      if (fn[0] == '\0')
        O (fatal, *expanding_var, _("file: missing filename"));

      if (argv[1])
        O (fatal, *expanding_var, _("file: too many arguments"));

      ENULLLOOP (fp, fopen (fn, "r"));
      if (fp == NULL)
        {
          if (errno == ENOENT)
            return o;
          OSS (fatal, reading_file, _("open: %s: %s"), fn, strerror (errno));
        }

      while (1)
        {
          char buf[1024];
          size_t l = fread (buf, 1, sizeof (buf), fp);
          if (l > 0)
            o = variable_buffer_output (o, buf, l);

          if (ferror (fp))
            if (errno != EINTR)
              OSS (fatal, reading_file, _("read: %s: %s"), fn, strerror (errno));
          if (feof (fp))
            break;
        }
      if (fclose (fp))
        OSS (fatal, reading_file, _("close: %s: %s"), fn, strerror (errno));

      /* Remove trailing newline.  */
      if (o > preo && o[-1] == '\n')
        if (--o > preo && o[-1] == '\r')
          --o;
    }
  else
    OS (fatal, *expanding_var, _("file: invalid file operation: %s"), fn);

  return o;
}
