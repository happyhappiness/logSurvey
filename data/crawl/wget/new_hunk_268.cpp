        }
    }

  if (opt.method)
    {

      if (opt.body_data || opt.body_file)
        {
          request_set_header (req, "Content-Type",
                              "application/x-www-form-urlencoded", rel_none);

          if (opt.body_data)
            body_data_size = strlen (opt.body_data);
          else
            {
              body_data_size = file_size (opt.body_file);
              if (body_data_size == -1)
                {
                  logprintf (LOG_NOTQUIET, _("BODY data file %s missing: %s\n"),
                             quote (opt.body_file), strerror (errno));
                  return FILEBADFILE;
                }
            }
          request_set_header (req, "Content-Length",
                              xstrdup (number_to_static_string (body_data_size)),
                              rel_value);
        }
    }

 retry_with_auth:
