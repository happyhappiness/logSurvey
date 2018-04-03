   && (ISSPACE (line[sizeof (string_constant) - 1])			\
       || !line[sizeof (string_constant) - 1]))

#define SET_USER_AGENT(req)						\
  if (opt.useragent)							\
    request_set_header (req, "User-Agent", opt.useragent, rel_none);	\
  else									\
    request_set_header (req, "User-Agent",				\
			aprintf ("Wget/%s", version_string), rel_value);


/* Retrieve a document through HTTP protocol.  It recognizes status
   code, and correctly handles redirections.  It closes the network
