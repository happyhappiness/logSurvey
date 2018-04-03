    ++line;
  if (*line == '\0')
    return 0;
#endif /* WINDOWS32 */
  {
    /* SHELL may be a multi-word command.  Construct a command line
