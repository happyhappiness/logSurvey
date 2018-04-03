 
 			printf(" * [%s] %s\n", dry_run ? "would prune" : "pruned",
 			       abbrev_ref(refname, "refs/remotes/"));
+			warn_dangling_symref(dangling_msg, refname);
 		}
 
 		/* NEEDSWORK: free remote */
