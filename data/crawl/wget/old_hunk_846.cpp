      fprintf (fp, "<a href=\"ftp://%s%s:%d", upwd, u->host, u->port);
      if (*u->dir != '/')
        putc ('/', fp);
      fprintf (fp, "%s", u->dir);
      if (*u->dir)
        putc ('/', fp);
      fprintf (fp, "%s", urlclfile);
