   if (fh == NULL)
     return (-1);
 
+  fputs ("\r\n", fh);
+  fflush (fh);
+
   while (fgets (buffer, sizeof (buffer), fh) != NULL)
   {
     buffer_len = strchomp (buffer);