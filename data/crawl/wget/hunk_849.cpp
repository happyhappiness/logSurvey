           break;
         }
       htclfile = html_quote_string (f->name);
+      urlclfile = url_escape_unsafe_and_reserved (f->name);
       fprintf (fp, "<a href=\"ftp://%s%s:%d", upwd, u->host, u->port);
       if (*u->dir != '/')
         putc ('/', fp);
       fprintf (fp, "%s", u->dir);
       if (*u->dir)
         putc ('/', fp);
-      fprintf (fp, "%s", htclfile);
+      fprintf (fp, "%s", urlclfile);
       if (f->type == FT_DIRECTORY)
         putc ('/', fp);
       fprintf (fp, "\">%s", htclfile);
