 
   usageto = bad ? stderr : stdout;
 
-  fprintf (usageto, "Usage: %s [options] [target] ...\n", program);
+  fprintf (usageto, _("Usage: %s [options] [target] ...\n"), program);
 
   fputs (_("Options:\n"), usageto);
   for (cs = switches; cs->c != '\0'; ++cs)
