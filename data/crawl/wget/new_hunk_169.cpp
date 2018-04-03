    }


  {
    uerr_t ret = check_file_output (u, hs, resp, hdrval, sizeof hdrval);
    if (ret != RETROK)
      {
        request_free (req);
        resp_free (resp);
        xfree (head);
        xfree (message);
        return ret;
      }
  }
  request_free (req);

  hs->statcode = statcode;
