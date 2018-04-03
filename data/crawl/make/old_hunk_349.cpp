          int l = strlen (argv[1]);
          int nl = (l == 0 || argv[1][l-1] != '\n');

          if (fputs (argv[1], fp) == EOF || (nl && fputc('\n', fp) == EOF))
            fatal (reading_file, _("write: %s: %s"), fn, strerror (errno));

          fclose (fp);
