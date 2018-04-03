
  if (cond_get)
    {
      /* Handle the case when server ignores If-Modified-Since header.  */
      if (statcode == HTTP_STATUS_OK && hs->remote_time)
        {
          time_t tmr = http_atotm (hs->remote_time);

