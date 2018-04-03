               * give up. */
            }
        }
      request_free (req);
      xfree_null (message);
      resp_free (resp);
      xfree (head);
      if (auth_err == RETROK)
        return AUTHFAILED;
      else
        return auth_err;
    }
  else /* statcode != HTTP_STATUS_UNAUTHORIZED */
    {
