     else
         visible_appname_string = (char const *)APP_FULLNAME;
 
-#if USE_DNSSERVERS
-
+#if USE_DNSHELPER
     if (Config.dnsChildren.n_max < 1)
-        fatal("No dnsservers allocated");
-
+        fatal("No DNS helpers allocated");
 #endif
 
     if (Config.Program.redirect) {
