 #include "cache.h"
 #include "refs.h"
 #include "builtin.h"
+#include "parse-options.h"
 
-static const char git_update_ref_usage[] =
-"git-update-ref [-m <reason>] (-d <refname> <value> | [--no-deref] <refname> <value> [<oldval>])";
+static const char * const git_update_ref_usage[] = {
+	"git-update-ref [options] -d <refname> <oldval>",
+	"git-update-ref [options]    <refname> <newval> [<oldval>]",
+	NULL
+};
 
 int cmd_update_ref(int argc, const char **argv, const char *prefix)
 {
-	const char *refname=NULL, *value=NULL, *oldval=NULL, *msg=NULL;
+	const char *refname, *value, *oldval, *msg=NULL;
 	unsigned char sha1[20], oldsha1[20];
-	int i, delete, ref_flags;
+	int delete = 0, no_deref = 0;
+	struct option options[] = {
+		OPT_STRING( 'm', NULL, &msg, "reason", "reason of the update"),
+		OPT_BOOLEAN('d', NULL, &delete, "deletes the reference"),
+		OPT_BOOLEAN( 0 , "no-deref", &no_deref,
+					"update <refname> not the one it points to"),
+		OPT_END(),
+	};
 
-	delete = 0;
-	ref_flags = 0;
 	git_config(git_default_config);
+	argc = parse_options(argc, argv, options, git_update_ref_usage, 0);
+	if (msg && !*msg)
+		die("Refusing to perform update with empty message.");
 
-	for (i = 1; i < argc; i++) {
-		if (!strcmp("-m", argv[i])) {
-			if (i+1 >= argc)
-				usage(git_update_ref_usage);
-			msg = argv[++i];
-			if (!*msg)
-				die("Refusing to perform update with empty message.");
-			continue;
-		}
-		if (!strcmp("-d", argv[i])) {
-			delete = 1;
-			continue;
-		}
-		if (!strcmp("--no-deref", argv[i])) {
-			ref_flags |= REF_NODEREF;
-			continue;
-		}
-		if (!refname) {
-			refname = argv[i];
-			continue;
-		}
-		if (!value) {
-			value = argv[i];
-			continue;
-		}
-		if (!oldval) {
-			oldval = argv[i];
-			continue;
-		}
-	}
-	if (!refname || !value)
-		usage(git_update_ref_usage);
+	if (argc < 2 || argc > 3)
+		usage_with_options(git_update_ref_usage, options);
+	refname = argv[0];
+	value   = argv[1];
+	oldval  = argv[2];
 
 	if (get_sha1(value, sha1))
 		die("%s: not a valid SHA1", value);
 
 	if (delete) {
 		if (oldval)
-			usage(git_update_ref_usage);
+			usage_with_options(git_update_ref_usage, options);
 		return delete_ref(refname, sha1);
 	}
 
