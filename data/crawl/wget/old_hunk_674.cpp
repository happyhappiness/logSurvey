              continue;
            }
          /* Maybe we should always keep track of broken links, not just in
           * spider mode.  */
          else if (opt.spider)
            {
              /* #### Again: ugly ugly ugly! */
              if (!hurl) 
                hurl = url_string (u, URL_AUTH_HIDE_PASSWD);
              nonexisting_url (hurl);
              logprintf (LOG_NOTQUIET, _("\
