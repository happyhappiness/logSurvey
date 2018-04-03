     printf("Content-type: text/html\r\n\r\n");
     if ((agent = getenv("HTTP_USER_AGENT")) != NULL) {
 	if (!strncasecmp(agent, "Mozilla", 7) ||
+	    !strncasecmp(agent, "OmniWeb/2", 9) ||
 	    !strncasecmp(agent, "Netscape", 8)) {
 	    hasTables = TRUE;
 	}
