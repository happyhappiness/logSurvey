              /* Avoid recursive Metalink from HTTP headers.  */
              bool _metalink_http = opt.metalink_over_http;

              /* FIXME: could be useless.  */
              if (strcmp (url->file, basename))
                logprintf (LOG_VERBOSE,
                           _("URL file name %s and Metalink file name %s are different.\n"),
                           quote_n (0, url->file), quote_n (1, basename));

              /* If output_stream is not NULL, then we have failed on
                 previous resource and are retrying. Thus, continue
                 with the next resource.  Do not close output_stream
