 		die("No REQUEST_METHOD from server");
 	if (!strcmp(method, "HEAD"))
 		method = "GET";
-	if (!dir)
-		die("No PATH_TRANSLATED from server");
+	dir = getdir();
 
 	for (i = 0; i < ARRAY_SIZE(services); i++) {
 		struct service_cmd *c = &services[i];