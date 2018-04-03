 		strstr(server_capabilities, feature) != NULL;
 }
 
-int get_ack(int fd, unsigned char *result_sha1)
-{
-	static char line[1000];
-	int len = packet_read_line(fd, line, sizeof(line));
-
-	if (!len)
-		die("git fetch-pack: expected ACK/NAK, got EOF");
-	if (line[len-1] == '\n')
-		line[--len] = 0;
-	if (!strcmp(line, "NAK"))
-		return 0;
-	if (!prefixcmp(line, "ACK ")) {
-		if (!get_sha1_hex(line+4, result_sha1)) {
-			if (strstr(line+45, "continue"))
-				return 2;
-			return 1;
-		}
-	}
-	die("git fetch_pack: expected ACK/NAK, got '%s'", line);
-}
-
 int path_match(const char *path, int nr, char **match)
 {
 	int i;