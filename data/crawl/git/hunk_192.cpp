  */
 #include "git-compat-util.h"
 #include "builtin.h"
+#include "diff.h"
 
 static const char builtin_merge_ours_usage[] =
 	"git merge-ours <base>... -- HEAD <remote>...";
 
-static const char *diff_index_args[] = {
-	"diff-index", "--quiet", "--cached", "HEAD", "--", NULL
-};
-#define NARGS (ARRAY_SIZE(diff_index_args) - 1)
-
 int cmd_merge_ours(int argc, const char **argv, const char *prefix)
 {
 	if (argc == 2 && !strcmp(argv[1], "-h"))
 		usage(builtin_merge_ours_usage);
 
 	/*
-	 * We need to exit with 2 if the index does not match our HEAD tree,
-	 * because the current index is what we will be committing as the
-	 * merge result.
+	 * The contents of the current index becomes the tree we
+	 * commit.  The index must match HEAD, or this merge cannot go
+	 * through.
 	 */
-	if (cmd_diff_index(NARGS, diff_index_args, prefix))
+	if (read_cache() < 0)
+		die_errno("read_cache failed");
+	if (index_differs_from("HEAD", 0, 0))
 		exit(2);
 	exit(0);
 }