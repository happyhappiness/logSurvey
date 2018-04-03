      f = f->next;
    }
  fprintf (fp, "</pre>\n</body>\n</html>\n");
  xfree (htcldir);
  xfree (upwd);
  if (!output_stream)
    fclose (fp);
