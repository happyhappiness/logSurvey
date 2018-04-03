        fprintf (fp, "-> %s", f->linkto ? f->linkto : "(nil)");
      putc ('\n', fp);
      xfree (htclfile);
      xfree (urlclfile);
      f = f->next;
    }
  fprintf (fp, "</pre>\n</body>\n</html>\n");
