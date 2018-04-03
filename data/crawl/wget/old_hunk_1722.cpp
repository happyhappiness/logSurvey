      char *tmp = strchr (type, ';');
      if (tmp)
        {
          while (tmp > type && c_isspace (tmp[-1]))
            --tmp;
          *tmp = '\0';
        }
    }
  hs->newloc = resp_header_strdup (resp, "Location");
