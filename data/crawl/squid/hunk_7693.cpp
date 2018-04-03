     if (getDnsChildren() < 1) {
 	printf("WARNING: dns_children was set to a bad value: %d\n",
 	    getDnsChildren());
-	printf("Setting it to the default (3).\n");
-	Config.dnsChildren = 3;
+	Config.dnsChildren = DefaultDnsChildren;
+	printf("Setting it to the default (%d).\n", DefaultDnsChildren);
     } else if (getDnsChildren() > DefaultDnsChildrenMax) {
 	printf("WARNING: dns_children was set to a bad value: %d\n",
 	    getDnsChildren());
 	printf("Setting it to the maximum (%d).\n", DefaultDnsChildrenMax);
 	Config.dnsChildren = DefaultDnsChildrenMax;
     }
+    if (getRedirectChildren() < 1) {
+	printf("WARNING: redirect_children was set to a bad value: %d\n",
+	    getRedirectChildren());
+	Config.redirectChildren = DefaultRedirectChildren;
+	printf("Setting it to the default (%d).\n", DefaultRedirectChildren);
+    } else if (getRedirectChildren() > DefaultRedirectChildrenMax) {
+	printf("WARNING: redirect_children was set to a bad value: %d\n",
+	    getRedirectChildren());
+	printf("Setting it to the maximum (%d).\n", DefaultRedirectChildrenMax);
+	Config.redirectChildren = DefaultRedirectChildrenMax;
+    }
     fclose(fp);
 
     configDoConfigure();
