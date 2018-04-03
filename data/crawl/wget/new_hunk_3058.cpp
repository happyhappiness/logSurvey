  if (b < e && e[-1] == '\r')
    --e;
  BOUNDED_TO_ALLOCA (b, e, ln);
  logprintf (LOG_VERBOSE, "%s%s\n", prefix, escnonprint (ln));
}

/* Print the server response, line by line, omitting the trailing CR
