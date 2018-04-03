  hs->error = NULL;
}

#define BEGINS_WITH(line, string_constant)                               \
  (!strncasecmp (line, string_constant, sizeof (string_constant) - 1)    \
   && (c_isspace (line[sizeof (string_constant) - 1])                      \
