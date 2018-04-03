 
 static int nfsnprintf( char *buf, int blen, const char *fmt, ... );
 
+static int nfvasprintf(char **strp, const char *fmt, va_list ap)
+{
+	int len;
+	char tmp[8192];
+
+	len = vsnprintf(tmp, sizeof(tmp), fmt, ap);
+	if (len < 0)
+		die("Fatal: Out of memory\n");
+	if (len >= sizeof(tmp))
+		die("imap command overflow !\n");
+	*strp = xmemdupz(tmp, len);
+	return len;
+}
 
 static void arc4_init( void );
 static unsigned char arc4_getbyte( void );
