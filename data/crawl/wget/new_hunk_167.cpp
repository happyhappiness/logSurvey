        }

      pconn.authorized = false;

      {
        auth_err = check_auth (u, user, passwd, resp, req,
                               &ntlm_seen, &retry,
                               &basic_auth_finished,
                               &auth_finished);
        if (auth_err == RETROK && retry)
          {
            xfree (hs->message);
            resp_free (resp);
            xfree (message);
            xfree (head);
            goto retry_with_auth;
          }
      }
      request_free (req);
      xfree (message);
      resp_free (resp);
