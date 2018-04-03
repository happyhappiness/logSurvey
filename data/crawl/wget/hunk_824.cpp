       if ((p = strchr (scheme, ':')))
         *p = '\0';
       if (!strcasecmp (scheme, "https"))
-        asprintf (&error, _("HTTPS support not compiled in"));
+        error = aprintf (_("HTTPS support not compiled in"));
       else
-        asprintf (&error, _(parse_errors[error_code]), quote (scheme));
+        error = aprintf (_(parse_errors[error_code]), quote (scheme));
       xfree (scheme);
 
       return error;
 doc/ChangeLog | 5 +++++
 doc/wget.texi | 2 +-
 2 files changed, 6 insertions(+), 1 deletion(-)
