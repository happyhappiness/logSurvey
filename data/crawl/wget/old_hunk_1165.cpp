{
  char *copy;
  BOUNDED_TO_ALLOCA(b, e, copy);
  logprintf (LOG_VERBOSE, "%s%s\n", prefix, escnonprint(copy));
}

/* Print the server response, line by line, omitting the trailing CRLF
src/ChangeLog | 6 ++++++
src/openssl.c | 7 +++++++
2 files changed, 13 insertions(+)
