   if (!env && (bad || print_usage_flag))
     {
       /* Print a nice usage message.  */
+      FILE *usageto;
 
       if (print_version_flag)
 	print_version ();
 
-      fprintf (stderr, "Usage: %s [options] [target] ...\n", program);
+      usageto = bad ? stderr : stdout;
 
-      fputs ("Options:\n", stderr);
+      fprintf (usageto, "Usage: %s [options] [target] ...\n", program);
+
+      fputs ("Options:\n", usageto);
       for (cs = switches; cs->c != '\0'; ++cs)
 	{
 	  char buf[1024], shortarg[50], longarg[50], *p;
