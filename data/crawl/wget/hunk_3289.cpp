   al = lookup_host (host, flags | LH_SILENT | LH_PASSIVE);
   if (al == NULL)
     {
+      /* #### We should print the error message here. */
       logprintf (LOG_NOTQUIET,
-		 _("Unable to convert `%s' to a bind address.  Reverting to ANY.\n"),
-		 opt.bind_address);
+		 _("%s: unable to resolve bind address `%s'; disabling bind.\n"),
+		 exec_name, opt.bind_address);
       return 0;
     }
 
