 	add_refspec(refspec.buf);
 }
 
+static const char *warn_unconfigured_push_msg[] = {
+	"You did not specify any refspecs to push, and the current remote",
+	"has not configured any push refspecs. The default action in this",
+	"case is to push all matching refspecs, that is, all branches",
+	"that exist both locally and remotely will be updated.  This may",
+	"not necessarily be what you want to happen.",
+	"",
+	"You can specify what action you want to take in this case, and",
+	"avoid seeing this message again, by configuring 'push.default' to:",
+	"  'nothing'  : Do not push anythig",
+	"  'matching' : Push all matching branches (default)",
+	"  'tracking' : Push the current branch to whatever it is tracking",
+	"  'current'  : Push the current branch"
+};
+
+static void warn_unconfigured_push(void)
+{
+	int i;
+	for (i = 0; i < ARRAY_SIZE(warn_unconfigured_push_msg); i++)
+		warning("%s", warn_unconfigured_push_msg[i]);
+}
+
 static void setup_default_push_refspecs(void)
 {
 	git_config(git_default_config, NULL);
 	switch (push_default) {
 	case PUSH_DEFAULT_UNSPECIFIED:
+		warn_unconfigured_push();
 		/* fallthrough */
 
 	case PUSH_DEFAULT_MATCHING: