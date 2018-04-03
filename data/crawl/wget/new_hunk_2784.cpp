
  if (write_error < 0)
    {
      CLOSE_INVALIDATE (sock);
      request_free (req);
      return WRITEFAILED;
