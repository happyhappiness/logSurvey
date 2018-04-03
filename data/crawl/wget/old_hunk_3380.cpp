}

static int
cmd_spec_useragent (const char *com, const char *val, void *closure)
{
  /* Just check for empty string and newline, so we don't throw total
