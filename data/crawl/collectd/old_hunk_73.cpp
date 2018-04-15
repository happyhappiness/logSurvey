  return ENOTSUP;
}

void plugin_log (int level, char const *format, ...)
{
  char buffer[1024];
