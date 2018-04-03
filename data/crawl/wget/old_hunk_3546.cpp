}

static int
cmd_spec_recursive (const char *com, const char *val, void *closure)
{
  if (!cmd_boolean (com, val, &opt.recursive))
