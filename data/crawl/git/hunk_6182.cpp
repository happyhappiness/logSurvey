 	}
 }
 
+static void setup_push_tracking(void)
+{
+	struct strbuf refspec = STRBUF_INIT;
+	struct branch *branch = branch_get(NULL);
+	if (!branch)
+		die("You are not currently on a branch.");
+	if (!branch->merge_nr)
+		die("The current branch %s is not tracking anything.",
+		    branch->name);
+	if (branch->merge_nr != 1)
+		die("The current branch %s is tracking multiple branches, "
+		    "refusing to push.", branch->name);
+	strbuf_addf(&refspec, "%s:%s", branch->name, branch->merge[0]->src);
+	add_refspec(refspec.buf);
+}
+
+static const char *warn_unconfigured_push_msg[] = {
+	"You did not specify any refspecs to push, and the current remote",
+	"has not configured any push refspecs. The default action in this",
+	"case is to push all matching refspecs, that is, all branches",
+	"that exist both locally and remotely will be updated.  This may",
+	"not necessarily be what you want to happen.",
+	"",
+	"You can specify what action you want to take in this case, and",
+	"avoid seeing this message again, by configuring 'push.default' to:",
+	"  'nothing'  : Do not push anything",
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
+static void setup_default_push_refspecs(void)
+{
+	git_config(git_default_config, NULL);
+	switch (push_default) {
+	case PUSH_DEFAULT_UNSPECIFIED:
+		warn_unconfigured_push();
+		/* fallthrough */
+
+	case PUSH_DEFAULT_MATCHING:
+		add_refspec(":");
+		break;
+
+	case PUSH_DEFAULT_TRACKING:
+		setup_push_tracking();
+		break;
+
+	case PUSH_DEFAULT_CURRENT:
+		add_refspec("HEAD");
+		break;
+
+	case PUSH_DEFAULT_NOTHING:
+		die("You didn't specify any refspecs to push, and "
+		    "push.default is \"nothing\".");
+		break;
+	}
+}
+
 static int do_push(const char *repo, int flags)
 {
 	int i, errs;
