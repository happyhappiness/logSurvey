  url_free (new_parsed);
  xfree (upos);

  return reason;
}


/* This function writes the rejected log header. */
static void
write_reject_log_header (FILE *f)
{
  if (!f)
    return;

  /* Note: Update this header when columns change in any way. */
  fprintf (f, "REASON\t"
    "U_URL\tU_SCHEME\tU_HOST\tU_PORT\tU_PATH\tU_PARAMS\tU_QUERY\tU_FRAGMENT\t"
    "P_URL\tP_SCHEME\tP_HOST\tP_PORT\tP_PATH\tP_PARAMS\tP_QUERY\tP_FRAGMENT\n");
}

/* This function writes a URL to the reject log. Internal use only. */
static void
write_reject_log_url (FILE *f, struct url *url)
{
  if (!f)
    return;

  char *escaped_str = url_escape (url->url);
  char const *scheme_str = 0;
  char empty_str[] = "";

  switch (url->scheme)
    {
      case SCHEME_HTTP:    scheme_str = "SCHEME_HTTP";    break;
      #ifdef HAVE_SSL
        case SCHEME_HTTPS: scheme_str = "SCHEME_HTTPS";   break;
      #endif
      case SCHEME_FTP:     scheme_str = "SCHEME_FTP";     break;
      case SCHEME_INVALID: scheme_str = "SCHEME_INVALID"; break;
    }

  fprintf (f, "%s\t%s\t%s\t%i\t%s\t%s\t%s\t%s",
    escaped_str,
    scheme_str,
    url->host,
    url->port,
    url->path,
    url->params ? url->params : empty_str,
    url->query ? url->query : empty_str,
    url->fragment ? url->fragment : empty_str);

  free (escaped_str);
}

/* This function writes out information on why a URL was rejected and its
   context from download_child such as the URL being rejected and it's
   parent's URL. The format it uses is comma separated values but with tabs. */
static void
write_reject_log_reason (FILE *f, reject_reason r, struct url *url,
                         struct url *parent)
{
  if (!f)
    return;

  char const *reason_str = 0;
  switch (r)
    {
      case SUCCESS:     reason_str = "SUCCESS";     break;
      case BLACKLIST:   reason_str = "BLACKLIST";   break;
      case NOTHTTPS:    reason_str = "NOTHTTPS";    break;
      case NONHTTP:     reason_str = "NONHTTP";     break;
      case ABSOLUTE:    reason_str = "ABSOLUTE";    break;
      case DOMAIN:      reason_str = "DOMAIN";      break;
      case PARENT:      reason_str = "PARENT";      break;
      case LIST:        reason_str = "LIST";        break;
      case REGEX:       reason_str = "REGEX";       break;
      case RULES:       reason_str = "RULES";       break;
      case SPANNEDHOST: reason_str = "SPANNEDHOST"; break;
      case ROBOTS:      reason_str = "ROBOTS";      break;
    }

  fprintf (f, "%s\t", reason_str);
  write_reject_log_url (f, url);
  fprintf (f, "\t");
  write_reject_log_url (f, parent);
  fprintf (f, "\n");
}

/* vim:set sts=2 sw=2 cino+={s: */
