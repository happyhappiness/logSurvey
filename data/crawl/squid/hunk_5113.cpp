 	fprintf(stderr, "\tIf you need to bind as a user to perform searches then use the\n\t-D binddn -w bindpasswd or -D binddn -W secretfile options\n\n");
 	exit(1);
     }
+
+/* On Windows ldap_start_tls_s is available starting from Windows XP, 
+   so we need to bind at run-time with the function entry point
+ */
+#ifdef _SQUID_MSWIN_
+    if (use_tls) {
+
+    	HMODULE WLDAP32Handle;
+
+	WLDAP32Handle = GetModuleHandle("wldap32");
+        if ((Win32_ldap_start_tls_s = (PFldap_start_tls_s) GetProcAddress(WLDAP32Handle, LDAP_START_TLS_S)) == NULL) {
+            fprintf( stderr, PROGRAM_NAME ": ERROR: TLS (-Z) not supported on this platform.\n");
+	    exit(1);
+        }
+    }
+#endif
+
     while (fgets(buf, 256, stdin) != NULL) {
 	user = strtok(buf, " \r\n");
 	passwd = strtok(NULL, "\r\n");