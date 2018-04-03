        {
          DEBUGP (("[POST data: %s]\n", opt.post_data));
          write_error = fd_write (sock, opt.post_data, post_data_size, -1);
        }
      else if (opt.post_file_name && post_data_size != 0)
        write_error = post_file (sock, opt.post_file_name, post_data_size);
    }

  if (write_error < 0)
    {
      CLOSE_INVALIDATE (sock);
      request_free (req);
      return WRITEFAILED;
    }
  logprintf (LOG_VERBOSE, _("%s request sent, awaiting response... "),
             proxy ? "Proxy" : "HTTP");
