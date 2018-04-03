 #include "cache.h"
 #include "tree.h"
 #include "cache-tree.h"
+#include "parse-options.h"
 
-static const char write_tree_usage[] =
-"git write-tree [--missing-ok] [--prefix=<prefix>/]";
+static const char * const write_tree_usage[] = {
+	"git write-tree [--missing-ok] [--prefix=<prefix>/]",
+	NULL
+};
 
 int cmd_write_tree(int argc, const char **argv, const char *unused_prefix)
 {
 	int flags = 0, ret;
 	const char *prefix = NULL;
 	unsigned char sha1[20];
 	const char *me = "git-write-tree";
+	struct option write_tree_options[] = {
+		OPT_BIT(0, "missing-ok", &flags, "allow missing objects",
+			WRITE_TREE_MISSING_OK),
+		{ OPTION_STRING, 0, "prefix", &prefix, "<prefix>/",
+		  "write tree object for a subdirectory <prefix>" ,
+		  PARSE_OPT_LITERAL_ARGHELP },
+		{ OPTION_BIT, 0, "ignore-cache-tree", &flags, NULL,
+		  "only useful for debugging",
+		  PARSE_OPT_HIDDEN | PARSE_OPT_NOARG, NULL,
+		  WRITE_TREE_IGNORE_CACHE_TREE },
+		OPT_END()
+	};
 
 	git_config(git_default_config, NULL);
-	while (1 < argc) {
-		const char *arg = argv[1];
-		if (!strcmp(arg, "--missing-ok"))
-			flags |= WRITE_TREE_MISSING_OK;
-		else if (!prefixcmp(arg, "--prefix="))
-			prefix = arg + 9;
-		else if (!prefixcmp(arg, "--ignore-cache-tree"))
-			/*
-			 * This is only useful for debugging, so I
-			 * do not bother documenting it.
-			 */
-			flags |= WRITE_TREE_IGNORE_CACHE_TREE;
-		else
-			usage(write_tree_usage);
-		argc--; argv++;
-	}
-
-	if (argc > 2)
-		die("too many options");
+	argc = parse_options(argc, argv, unused_prefix, write_tree_options,
+			     write_tree_usage, 0);
 
 	ret = write_cache_as_tree(sha1, flags, prefix);
 	switch (ret) {