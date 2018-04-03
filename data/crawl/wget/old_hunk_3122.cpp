    }
  fprintf (fp, "</pre>\n</body>\n</html>\n");
  xfree (upwd);
  if (!opt.dfp)
    fclose (fp);
  else
    fflush (fp);
