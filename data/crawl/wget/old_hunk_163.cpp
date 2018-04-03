      /* warc_write_request_record has also closed warc_tmp. */
    }


read_header:
  head = read_http_response_head (sock);
  if (!head)
    {
      if (errno == 0)
        {
          logputs (LOG_NOTQUIET, _("No data received.\n"));
          CLOSE_INVALIDATE (sock);
          request_free (req);
          return HEOF;
        }
      else
        {
          logprintf (LOG_NOTQUIET, _("Read error (%s) in headers.\n"),
                     fd_errstr (sock));
          CLOSE_INVALIDATE (sock);
          request_free (req);
          return HERR;
        }
    }
  DEBUGP (("\n---response begin---\n%s---response end---\n", head));

  resp = resp_new (head);

  /* Check for status line.  */
  message = NULL;
  statcode = resp_status (resp, &message);
  if (statcode < 0)
    {
      char *tms = datetime_str (time (NULL));
      logprintf (LOG_VERBOSE, "%d\n", statcode);
      logprintf (LOG_NOTQUIET, _("%s ERROR %d: %s.\n"), tms, statcode,
                 quotearg_style (escape_quoting_style,
                                 _("Malformed status line")));
      CLOSE_INVALIDATE (sock);
      resp_free (resp);
      request_free (req);
      xfree (head);
      return HERR;
    }

  if (H_10X (statcode))
    {
      DEBUGP (("Ignoring response\n"));
      resp_free (resp);
      xfree (head);
      goto read_header;
    }

  xfree(hs->message);
  hs->message = xstrdup (message);
