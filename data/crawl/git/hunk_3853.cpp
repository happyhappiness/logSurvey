 		int branch_existed = 0, remote_tracking = 0;
 		struct strbuf buf = STRBUF_INIT;
 
+		if (!strcmp(argv[0], "HEAD"))
+			die(_("it does not make sense to create 'HEAD' manually"));
+
+		if (!branch)
+			die(_("no such branch '%s'"), argv[0]);
+
 		if (kinds != REF_LOCAL_BRANCH)
 			die(_("-a and -r options to 'git branch' do not make sense with a branch name"));
 
