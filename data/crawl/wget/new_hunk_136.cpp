        case SCHEME_HTTPS: scheme_str = "SCHEME_HTTPS";   break;
      #endif
      case SCHEME_FTP:     scheme_str = "SCHEME_FTP";     break;
      default:             scheme_str = "SCHEME_INVALID"; break;
    }

  fprintf (fp, "%s\t%s\t%s\t%i\t%s\t%s\t%s\t%s",
    escaped_str,
    scheme_str,
    url->host,
    url->port,
    url->path,
    url->params ? url->params : "",
    url->query ? url->query : "",
    url->fragment ? url->fragment : "");

  xfree (escaped_str);
}

/* This function writes out information on why a URL was rejected and its
   context from download_child such as the URL being rejected and it's
   parent's URL. The format it uses is comma separated values but with tabs. */
static void
write_reject_log_reason (FILE *fp, reject_reason reason,
                         const struct url *url, const struct url *parent)
{
  const char *reason_str;

  if (!fp)
    return;

  switch (reason)
    {
      case SUCCESS:     reason_str = "SUCCESS";     break;
      case BLACKLIST:   reason_str = "BLACKLIST";   break;
