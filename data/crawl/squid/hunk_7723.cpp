 	    continue;
 	}
 	/* check if it's already an IP address in text form. */
-	if (sscanf(request, "%d.%d.%d.%d", &a1, &a2, &a3, &a4) == 4) {
+	if (inet_addr(request) != INADDR_NONE) {
 	    printf("$name %s\n", request);
 	    printf("$h_name %s\n", request);
 	    printf("$h_len %d\n", 4);
