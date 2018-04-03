          char *redirected = NULL;
          struct url *url_parsed = url_parse (url, &url_err, i, true);

          status = retrieve_url (url_parsed, url, &file, &redirected, referer,
                                 &dt, false, i, true);

          if (html_allowed && file && status == RETROK
              && (dt & RETROKF) && (dt & TEXTHTML))
            {
              descend = true;
              is_css = false;
            }

          /* a little different, css_allowed can override content type
             lots of web servers serve css with an incorrect content type
          */
          if (file && status == RETROK
              && (dt & RETROKF) &&
              ((dt & TEXTCSS) || css_allowed))
            {
              descend = true;
              is_css = true;
            }

          if (redirected)
            {
              /* We have been redirected, possibly to another host, or
                 different path, or wherever.  Check whether we really
                 want to follow it.  */
              if (descend)
                {
                  if (!descend_redirect_p (redirected, url_parsed, depth,
                                           start_url_parsed, blacklist, i))
                    descend = false;
                  else
                    /* Make sure that the old pre-redirect form gets
                       blacklisted. */
                    blacklist_add (blacklist, url);
                }

              xfree (url);
              url = redirected;
            }
          else
            {
              xfree (url);
              url = xstrdup (url_parsed->url);
            }
          url_free (url_parsed);
        }

      if (opt.spider)
