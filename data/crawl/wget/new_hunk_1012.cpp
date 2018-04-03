      char *tmp = strchr (type, ';');
      if (tmp)
        {
          /* sXXXav: only needed if IRI support is enabled */
          char *tmp2 = tmp + 1;

          while (tmp > type && c_isspace (tmp[-1]))
            --tmp;
          *tmp = '\0';

          /* Try to get remote encoding if needed */
          if (opt.enable_iri && !opt.encoding_remote)
            /* xxx = */ parse_charset (tmp2);
        }
    }
  hs->newloc = resp_header_strdup (resp, "Location");
