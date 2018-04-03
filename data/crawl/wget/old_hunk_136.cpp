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
