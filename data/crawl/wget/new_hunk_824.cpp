      if ((p = strchr (scheme, ':')))
        *p = '\0';
      if (!strcasecmp (scheme, "https"))
        error = aprintf (_("HTTPS support not compiled in"));
      else
        error = aprintf (_(parse_errors[error_code]), quote (scheme));
      xfree (scheme);

      return error;
doc/ChangeLog | 5 +++++
doc/wget.texi | 2 +-
2 files changed, 6 insertions(+), 1 deletion(-)
