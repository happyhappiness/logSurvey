 #include "exec_cmd.h"
 
 static const char *pgm;
-static const char *arguments[9];
 static int one_shot, quiet;
 static int err;
 
-static void run_program(void)
-{
-	struct child_process child;
-	memset(&child, 0, sizeof(child));
-	child.argv = arguments;
-	if (run_command(&child)) {
-		if (one_shot) {
-			err++;
-		} else {
-			if (!quiet)
-				die("merge program failed");
-			exit(1);
-		}
-	}
-}
-
 static int merge_entry(int pos, const char *path)
 {
 	int found;
+	const char *arguments[] = { pgm, "", "", "", path, "", "", "", NULL };
+	char hexbuf[4][60];
+	char ownbuf[4][60];
 
 	if (pos >= active_nr)
 		die("git merge-index: %s not in the cache", path);
-	arguments[0] = pgm;
-	arguments[1] = "";
-	arguments[2] = "";
-	arguments[3] = "";
-	arguments[4] = path;
-	arguments[5] = "";
-	arguments[6] = "";
-	arguments[7] = "";
-	arguments[8] = NULL;
 	found = 0;
 	do {
-		static char hexbuf[4][60];
-		static char ownbuf[4][60];
 		struct cache_entry *ce = active_cache[pos];
 		int stage = ce_stage(ce);
 
