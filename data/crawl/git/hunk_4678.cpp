 			reflog_msg = "commit (amend)";
 		commit = lookup_commit(head_sha1);
 		if (!commit || parse_commit(commit))
-			die("could not parse HEAD commit");
+			die(_("could not parse HEAD commit"));
 
 		for (c = commit->parents; c; c = c->next)
 			pptr = &commit_list_insert(c->item, pptr)->next;
