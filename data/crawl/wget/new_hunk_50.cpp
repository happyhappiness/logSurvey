              res_count++;
            }
        } /* Handle resource link (rel=duplicate).  */

      /* Handle Metalink/XML resources.  */
      else if (reltype && !strcmp (reltype, "application/metalink4+xml"))
        {
          metalink_metaurl_t murl = {0};
          char *pristr;

          /*
             Valid ranges for the "pri" attribute are from
             1 to 999999.  Mirror servers with a lower value of the "pri"
             attribute have a higher priority, while mirrors with an undefined
             "pri" attribute are considered to have a value of 999999, which is
             the lowest priority.

             rfc6249 section 3.1
           */
          murl.priority = DEFAULT_PRI;
          if (find_key_value (url_end, val_end, "pri", &pristr))
            {
              long pri;
              char *end_pristr;
              /* Do not care for errno since 0 is error in this case.  */
              pri = strtol (pristr, &end_pristr, 10);
              if (end_pristr != pristr + strlen (pristr) ||
                  !VALID_PRI_RANGE (pri))
                {
                  /* This is against the specification, so let's inform the user.  */
                  logprintf (LOG_NOTQUIET,
                             _("Invalid pri value. Assuming %d.\n"),
                             DEFAULT_PRI);
                }
              else
                murl.priority = pri;
              xfree (pristr);
            }

          murl.mediatype = xstrdup (reltype);

          DEBUGP (("MEDIATYPE=%s\n", murl.mediatype));

          /* At this point we have validated the new resource.  */

          find_key_value (url_end, val_end, "name", &murl.name);

          murl.url = urlstr;
          urlstr = NULL;

          /* 1 slot from new resource, 1 slot for null-termination.  */
          mfile->metaurls = xrealloc (mfile->metaurls,
                                       sizeof (metalink_metaurl_t *) * (meta_count + 2));
          mfile->metaurls[meta_count] = xnew0 (metalink_metaurl_t);
          *mfile->metaurls[meta_count] = murl;
          meta_count++;
        } /* Handle resource link (rel=describedby).  */
      else
        DEBUGP (("This link header was not used for Metalink\n"));

