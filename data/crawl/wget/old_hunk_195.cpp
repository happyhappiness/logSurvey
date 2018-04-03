              auth_stat = xmalloc (sizeof (uerr_t));
              *auth_stat = RETROK;

              value =  create_authorization_line (www_authenticate,
                                                  user, passwd,
                                                  request_method (req),
