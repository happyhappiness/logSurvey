
          resp = resp_new (head);
          statcode = resp_status (resp, &message);
          hs->message = xstrdup (message);
          resp_free (resp);
          xfree (head);
