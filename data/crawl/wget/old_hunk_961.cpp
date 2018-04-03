      goto redirected;
    }

  if (local_file)
    {
      if (*dt & RETROKF)
        {
          register_download (u->url, local_file);
          if (redirection_count && 0 != strcmp (origurl, u->url))
            register_redirection (origurl, u->url);
          if (*dt & TEXTHTML)
            register_html (u->url, local_file);
        }
    }

  if (file)
