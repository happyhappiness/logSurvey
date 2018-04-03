 }
 
 static int
-resolve_bind_address (const char *host, struct sockaddr *sa, int flags)
+resolve_bind_address (struct sockaddr *sa)
 {
   struct address_list *al;
 
-  /* #### Shouldn't we do this only once?  opt.bind_address won't
-     change during a Wget run!  */
+  /* Make sure this is called only once.  opt.bind_address doesn't
+     change during a Wget run.  */
+  static int called, should_bind;
+  static ip_address ip;
+  if (called)
+    {
+      if (should_bind)
+	sockaddr_set_data (sa, &ip, 0);
+      return should_bind;
+    }
+  called = 1;
 
-  al = lookup_host (host, flags | LH_SILENT | LH_PASSIVE);
-  if (al == NULL)
+  al = lookup_host_passive (opt.bind_address);
+  if (!al)
     {
-      /* #### We should print the error message here. */
+      /* #### We should be able to print the error message here. */
       logprintf (LOG_NOTQUIET,
 		 _("%s: unable to resolve bind address `%s'; disabling bind.\n"),
 		 exec_name, opt.bind_address);
+      should_bind = 0;
       return 0;
     }
 
   /* Pick the first address in the list and use it as bind address.
-     Perhaps we should try multiple addresses, but I don't think
-     that's necessary in practice.  */
-  sockaddr_set_data (sa, address_list_address_at (al, 0), 0);
+     Perhaps we should try multiple addresses in succession, but I
+     don't think that's necessary in practice.  */
+  ip = *address_list_address_at (al, 0);
   address_list_release (al);
+
+  sockaddr_set_data (sa, &ip, 0);
+  should_bind = 1;
   return 1;
 }
 
