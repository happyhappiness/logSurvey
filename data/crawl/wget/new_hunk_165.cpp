      return RETRFINISHED;
    }

  err = open_output_stream (hs, count, &fp);
  if (err != RETROK)
    {
      xfree (type);
      xfree (head);
      CLOSE_INVALIDATE (sock);
      return err;
    }

  err = read_response_body (hs, sock, fp, contlen, contrange,
                            chunked_transfer_encoding,
