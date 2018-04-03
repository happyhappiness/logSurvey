   opt.restrict_files_os = restrict_windows;
 #endif
   opt.restrict_files_ctrl = 1;
+
+#ifdef ENABLE_IPV6
+# ifndef HAVE_GETADDRINFO_AI_ADDRCONFIG
+  /* If IPv6 is enabled, but AI_ADDRCONFIG is missing, check whether
+     we can create AF_INET6 sockets.  If we can't, turn on the
+     --inet4-only setting.  This is necessary because on some systems
+     (e.g. RHL 9) getaddrinfo resolves AAAA records, but socket()
+     can't even create an AF_INET6 socket, let alone connect to IPv6
+     hosts.  To avoid "address family not supported" error messages,
+     we set ipv4_only.
+
+     We do it as early as here, so that the user can revert the
+     settingn using --no-inet4-only, in case he wants to see the error
+     messages, for whatever reason.  */
+  {
+    int sock = socket (AF_INET6, SOCK_STREAM, 0);
+    if (sock < 0)
+      opt.ipv4_only = 1;
+    else
+      close (sock);
+  }
+# endif /* not HAVE_GETADDRINFO_AI_ADDRCONFIG */
+#endif /* ENABLE_IPV6 */
 }
 
 /* Return the user's home directory (strdup-ed), or NULL if none is
