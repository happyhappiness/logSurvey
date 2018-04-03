        }
    }

  if (opt.post_data || opt.post_file_name)
    {
      request_set_header (req, "Content-Type",
                          "application/x-www-form-urlencoded", rel_none);
      if (opt.post_data)
        post_data_size = strlen (opt.post_data);
      else
        {
          post_data_size = file_size (opt.post_file_name);
          if (post_data_size == -1)
            {
              logprintf (LOG_NOTQUIET, _("POST data file %s missing: %s\n"),
                         quote (opt.post_file_name), strerror (errno));
              return FILEBADFILE;
            }
        }
      request_set_header (req, "Content-Length",
                          xstrdup (number_to_static_string (post_data_size)),
                          rel_value);
    }

 retry_with_auth:
