     }
   else
     upwd = xstrdup ("");
+
+  htcldir = html_quote_string (u->dir);
+
   fprintf (fp, "<!DOCTYPE HTML PUBLIC \"-//IETF//DTD HTML 2.0//EN\">\n");
   fprintf (fp, "<html>\n<head>\n<title>");
-  fprintf (fp, _("Index of /%s on %s:%d"), u->dir, u->host, u->port);
+  fprintf (fp, _("Index of /%s on %s:%d"), htcldir, u->host, u->port);
   fprintf (fp, "</title>\n</head>\n<body>\n<h1>");
-  fprintf (fp, _("Index of /%s on %s:%d"), u->dir, u->host, u->port);
+  fprintf (fp, _("Index of /%s on %s:%d"), htcldir, u->host, u->port);
   fprintf (fp, "</h1>\n<hr>\n<pre>\n");
+
+  xfree (htcldir);
   while (f)
     {
       fprintf (fp, "  ");
 src/ChangeLog | 2 +-
 src/ftp-ls.c  | 8 ++++++--
 2 files changed, 7 insertions(+), 3 deletions(-)
