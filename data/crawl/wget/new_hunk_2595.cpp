  else if (!strcasecmp (params, "giga"))
    {
      /* "Giga" retrieval, for retrieving very very *very* long files;
         each dot is 1M, 8 dots in a cluster, 4 clusters (32M) in a
         line.  */
      opt.dot_bytes = (1L << 20);
      opt.dot_spacing = 8;
      opt.dots_in_line = 32;
    }
  else
    fprintf (stderr,
             _("Invalid dot style specification `%s'; leaving unchanged.\n"),
             params);
}

/* "Thermometer" (bar) progress. */
