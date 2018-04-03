}

static bool
cmd_spec_htmlify (const char *com, const char *val, void *place_ignored)
{
  int flag = cmd_boolean (com, val, &opt.htmlify);
