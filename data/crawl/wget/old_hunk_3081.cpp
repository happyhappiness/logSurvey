    request_set_header (req, "Pragma", "no-cache", rel_none);
  if (hs->restval)
    request_set_header (req, "Range",
			aprintf ("bytes=%ld-", hs->restval), rel_value);
  if (opt.useragent)
    request_set_header (req, "User-Agent", opt.useragent, rel_none);
  else
