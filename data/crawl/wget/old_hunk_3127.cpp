  return 1;
}

/* Read the body of the request, but don't store it anywhere.  This is
   useful when reading error responses that are not logged anywhere,
   but which need to be read so the same connection can be reused.  */

static void
skip_body (int fd, long contlen)
{
  int oldverbose;
  long dummy;

  /* Skipping the body doesn't make sense if the content length is
     unknown because, in that case, persistent connections cannot be
     used.  (#### This is not the case with HTTP/1.1 where they can
     still be used with the magic of the "chunked" transfer!)  */
  if (contlen == -1)
    return;

  oldverbose = opt.verbose;
  opt.verbose = 0;
  fd_read_body (fd, NULL, contlen, 1, 0, &dummy, NULL);
  opt.verbose = oldverbose;
}

/* Persistent connections.  Currently, we cache the most recently used
