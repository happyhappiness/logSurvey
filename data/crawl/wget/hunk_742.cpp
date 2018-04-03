   fprintf (fp, _("Index of /%s on %s:%d"), htcldir, u->host, u->port);
   fprintf (fp, "</h1>\n<hr>\n<pre>\n");
 
-  xfree (htcldir);
   while (f)
     {
       fprintf (fp, "  ");
