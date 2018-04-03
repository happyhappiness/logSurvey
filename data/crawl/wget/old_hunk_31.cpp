      if (fp)
        {
          fputs ("# dummy comment\n", fp);
          fprintf (fp, "foo.example.com\t0\t1\t%ld\t123\n",(long) created);
          fprintf (fp, "bar.example.com\t0\t0\t%ld\t456\n", (long) created);
          fprintf (fp, "test.example.com\t8080\t0\t%ld\t789\n", (long) created);
          fclose (fp);

          table = hsts_store_open (file);
