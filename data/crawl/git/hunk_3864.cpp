 	char line[1000];
 	int ret = 0;
 	int len = packet_read_line(in, line, sizeof(line));
-	if (len < 10 || memcmp(line, "unpack ", 7))
+	if (prefixcmp(line, "unpack "))
 		return error("did not receive remote status");
-	if (memcmp(line, "unpack ok\n", 10)) {
+	if (strcmp(line, "unpack ok\n")) {
 		char *p = line + strlen(line) - 1;
 		if (*p == '\n')
 			*p = '\0';
