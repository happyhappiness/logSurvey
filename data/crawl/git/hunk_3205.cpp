 	strbuf_release(&buf);
 }
 
+static int dead;
 static NORETURN void die_webcgi(const char *err, va_list params)
 {
-	static int dead;
+	if (dead <= 1) {
+		vreportf("fatal: ", err, params);
 
-	if (!dead) {
-		dead = 1;
 		http_status(500, "Internal Server Error");
 		hdr_nocache();
 		end_headers();
-
-		vreportf("fatal: ", err, params);
 	}
 	exit(0); /* we successfully reported a failure ;-) */
 }
 
+static int die_webcgi_recursing(void)
+{
+	return dead++ > 1;
+}
+
 static char* getdir(void)
 {
 	struct strbuf buf = STRBUF_INIT;
