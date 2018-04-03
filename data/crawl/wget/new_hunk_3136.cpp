#endif /* HAVE_SSL */
    }

  /* Send the request to server.  */
  write_error = request_send (req, sock);

  if (write_error >= 0)
    {
