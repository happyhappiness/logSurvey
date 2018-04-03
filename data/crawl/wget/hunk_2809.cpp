   else /* do not CWD */
     logputs (LOG_VERBOSE, _("==> CWD not required.\n"));
 
-  if ((cmd & DO_RETR) && restval && *len == 0)
+  if ((cmd & DO_RETR) && *len == 0)
     {
       if (opt.verbose)
 	{
