 #include "refs.h"
 #include "strbuf.h"
 
-int get_tree = 0;
-int get_history = 0;
-int get_all = 0;
-int get_verbosely = 0;
-int get_recover = 0;
 static unsigned char current_commit_sha1[20];
 
-void pull_say(const char *fmt, const char *hex)
+void walker_say(struct walker *walker, const char *fmt, const char *hex)
 {
-	if (get_verbosely)
+	if (walker->get_verbosely)
 		fprintf(stderr, fmt, hex);
 }
 
