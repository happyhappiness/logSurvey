    to limit the findings to changes that involve the named object.
    (merge 4d8c51aa19 sb/diff-blobfind-pickaxe later to maint).
 
+ * "git format-patch" learned to give 72-cols to diffstat, which is
+   consistent with other line length limits the subcommand uses for
+   its output meant for e-mails.
+
+ * The log from "git daemon" can be redirected with a new option; one
+   relevant use case is to send the log to standard error (instead of
+   syslog) when running it from inetd.
+
+ * "git rebase" learned to take "--allow-empty-message" option.
 
 Performance, Internal Implementation, Development Support etc.
 
