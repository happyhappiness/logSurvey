              /* Avoid recursive Metalink from HTTP headers.  */
              bool _metalink_http = opt.metalink_over_http;

              /* If output_stream is not NULL, then we have failed on
                 previous resource and are retrying. Thus, continue
                 with the next resource.  Do not close output_stream
