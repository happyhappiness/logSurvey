             the value "negotiate", and other(s) with data.  Loop over
             all the occurrences and pick the one we recognize.  */
          int wapos;
          char *buf;
          const char *www_authenticate = NULL;
          const char *wabeg, *waend;
          const char *digest = NULL, *basic = NULL, *ntlm = NULL;
          for (wapos = 0; !ntlm
               && (wapos = resp_header_locate (resp, "WWW-Authenticate", wapos,
                                            &wabeg, &waend)) != -1;
               ++wapos)
            {
              param_token name, value;

              BOUNDED_TO_ALLOCA (wabeg, waend, buf);
              www_authenticate = buf;

              for (;!ntlm;)
                {
                  /* extract the auth-scheme */
                  while (c_isspace (*www_authenticate)) www_authenticate++;
                  name.e = name.b = www_authenticate;
                  while (*name.e && !c_isspace (*name.e)) name.e++;

                  if (name.b == name.e)
                    break;

                  DEBUGP (("Auth scheme found '%.*s'\n", (int) (name.e - name.b), name.b));

                  if (known_authentication_scheme_p (name.b, name.e))
                    {
                      if (BEGINS_WITH (name.b, "NTLM"))
                        {
                          ntlm = name.b;
                          break; /* this is the most secure challenge, stop here */
                        }
                      else if (!digest && BEGINS_WITH (name.b, "Digest"))
                        digest = name.b;
                      else if (!basic && BEGINS_WITH (name.b, "Basic"))
                        basic = name.b;
                    }

                  /* now advance over the auth-params */
                  www_authenticate = name.e;
                  DEBUGP (("Auth param list '%s'\n", www_authenticate));
                  while (extract_param (&www_authenticate, &name, &value, ',', NULL) && name.b && value.b)
                    {
                      DEBUGP (("Auth param %.*s=%.*s\n",
                               (int) (name.e - name.b), name.b, (int) (value.e - value.b), value.b));
                    }
                }
            }

          if (!basic && !digest && !ntlm)
            {
              /* If the authentication header is missing or
                 unrecognized, there's no sense in retrying.  */
              logputs (LOG_NOTQUIET, _("Unknown authentication scheme.\n"));
            }
          else if (!basic_auth_finished
                   || !basic)
            {
              char *pth = url_full_path (u);
              const char *value;
