{
  char *copy;
  BOUNDED_TO_ALLOCA(b, e, copy);
  logprintf (LOG_ALWAYS, "%s%s\n", prefix, escnonprint(copy));
}

/* Print the server response, line by line, omitting the trailing CRLF
