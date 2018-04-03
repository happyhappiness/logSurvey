 		die("The remote end hung up unexpectedly");
 }
 
-int packet_read_line(int fd, char *buffer, unsigned size)
+static int packet_length(const char *linelen)
 {
 	int n;
-	unsigned len;
-	char linelen[4];
-
-	safe_read(fd, linelen, 4);
+	int len = 0;
 
-	len = 0;
 	for (n = 0; n < 4; n++) {
 		unsigned char c = linelen[n];
 		len <<= 4;
