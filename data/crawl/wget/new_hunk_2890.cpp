   && (ISSPACE (line[sizeof (string_constant) - 1])			\
       || !line[sizeof (string_constant) - 1]))

#define SET_USER_AGENT(req) do {					\
  if (!opt.useragent)							\
    request_set_header (req, "User-Agent",				\
			aprintf ("Wget/%s", version_string), rel_value); \
  else if (*opt.useragent)						\
    request_set_header (req, "User-Agent", opt.useragent, rel_none);	\
} while (0)

/* Retrieve a document through HTTP protocol.  It recognizes status
   code, and correctly handles redirections.  It closes the network
