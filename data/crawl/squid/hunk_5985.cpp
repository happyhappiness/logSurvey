     idnsParseNameservers();
     if (0 == nns)
 	idnsParseResolvConf();
+    if (0 == nns)
+	fatal("Could not find any nameservers.\n"
+	    "       Please check your /etc/resolv.conf file\n"
+	    "       or use the 'dns_nameservers' option in squid.conf.");
     if (!init) {
 	memDataInit(MEM_IDNS_QUERY, "idns_query", sizeof(idns_query), 0);
 	cachemgrRegister("idns",
