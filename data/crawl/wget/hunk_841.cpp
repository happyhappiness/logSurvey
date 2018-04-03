       fprintf (fp, "<a href=\"ftp://%s%s:%d", upwd, u->host, u->port);
       if (*u->dir != '/')
         putc ('/', fp);
-      fprintf (fp, "%s", u->dir);
+      /* XXX: Should probably URL-escape dir components here, rather
+       * than just HTML-escape, for consistency with the next bit where
+       * we use urlclfile for the file component. Anyway, this is safer
+       * than what we had... */
+      fprintf (fp, "%s", htcldir);
       if (*u->dir)
         putc ('/', fp);
       fprintf (fp, "%s", urlclfile);
