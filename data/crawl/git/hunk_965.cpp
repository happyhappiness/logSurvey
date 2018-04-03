 	}
 }
 
-static void print_ref_status(char flag, const char *summary, struct ref *to, struct ref *from, const char *msg, int porcelain)
+static void print_ref_status(char flag, const char *summary,
+			     struct ref *to, struct ref *from, const char *msg,
+			     int porcelain, int summary_width)
 {
 	if (porcelain) {
 		if (from)
