   if (print)
     {
       const char *txt_addr = print_address (ip);
-      if (print && 0 != strcmp (print, txt_addr))
+      if (0 != strcmp (print, txt_addr))
         logprintf (LOG_VERBOSE, _("Connecting to %s|%s|:%d... "),
                    escnonprint_uri (print), txt_addr, port);
       else
 src/connect.c | 21 +++++++++++++++++++--
 1 file changed, 19 insertions(+), 2 deletions(-)
