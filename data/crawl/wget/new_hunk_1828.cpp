{
  char *copy;
  BOUNDED_TO_ALLOCA(b, e, copy);
  logprintf (LOG_VERBOSE, "%s%s\n", prefix, 
             quotearg_style (escape_quoting_style, copy));
}

/* Print the server response, line by line, omitting the trailing CRLF
