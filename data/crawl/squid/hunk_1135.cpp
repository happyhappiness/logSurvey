     openlog("msnt_auth", LOG_PID, LOG_USER);
     setbuf(stdout, NULL);
 
-    /* Read configuration file. Abort wildly if error. */
-    if (OpenConfigFile() == 1)
-        return 1;
-
-    /*
-     * Read denied and allowed user files.
-     * If they fails, there is a serious problem.
-     * Check syslog messages. Deny all users while in this state.
-     * The msntauth process should then be killed.
-     */
-    if ((Read_denyusers() == 1) || (Read_allowusers() == 1)) {
-        while (1) {
-            memset(wstr, '\0', sizeof(wstr));
-            if (fgets(wstr, 255, stdin) == NULL)
-                break;
-            puts("ERR");
-        }
-        return 1;
+    for (int j = 1; j < argc; ++j) {
+    	std::string arg = argv[j];
+    	size_t pos=arg.find('/');
+    	if (arg.find('/',pos+1)) {
+    		std::cerr << "Error: can't understand domain controller specification '"
+    				<< arg << '"' << std::endl;
+    		exit(1);
+    	}
+    	domaincontroller dc;
+    	dc.domain = arg.substr(0,pos);
+    	dc.server = arg.substr(pos+1);
+    	if (dc.domain.length() == 0 || dc.server.length() == 0) {
+    		std::cerr << "Error: invalid domain specification in '" << arg <<
+    				"'" << std::endl;
+    		exit(1);
+    	}
+    	domaincontrollers.push_back(dc);
     }
 
-    /*
-     * Make Check_forchange() the handle for HUP signals.
-     * Don't use alarms any more. I don't think it was very
-     * portable between systems.
-     * XXX this should be sigaction()
-     */
-    signal(SIGHUP, Check_forchange);
-
     while (1) {
         int n;
         /* Read whole line from standard input. Terminate on break. */
