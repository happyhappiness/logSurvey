      if ((p = strchr (scheme, ':')))
        *p = '\0';
      if (!strcasecmp (scheme, "https"))
        asprintf (&error, _("HTTPS support not compiled in"));
      else
        asprintf (&error, _(parse_errors[error_code]), quote (scheme));
      xfree (scheme);

      return error;
