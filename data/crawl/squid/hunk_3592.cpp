     return token;
 }
 
-int main(int argc, char *argv[])
+int
+main(int argc, char *argv[])
 {
 
     const char *Token;
+    int count;
 
-    if (argc < 1) {
-        fprintf(stderr, "%s| %s: Error: No proxy server name given\n", LogTime(), PROGRAM);
-        exit(99);
+    if (argc < 2) {
+	fprintf(stderr, "%s| %s: Error: No proxy server name given\n",
+	    LogTime(), PROGRAM);
+	exit(99);
+    }
+    if (argc == 3) {
+	count = atoi(argv[2]);
+	while (count > 0) {
+	    Token = (const char *) squid_kerb_proxy_auth(argv[1]);
+	    fprintf(stdout, "YR %s\n", Token ? Token : "NULL");
+	    count--;
+	}
+	fprintf(stdout, "QQ\n");
+    } else {
+	Token = (const char *) squid_kerb_proxy_auth(argv[1]);
+	fprintf(stdout, "Token: %s\n", Token ? Token : "NULL");
     }
-    Token = (const char *)squid_kerb_proxy_auth(argv[1]);
-    fprintf(stdout,"Token: %s\n",Token?Token:"NULL");
 
     exit(0);
 }
-
+#endif /* HAVE_GSSAPI */