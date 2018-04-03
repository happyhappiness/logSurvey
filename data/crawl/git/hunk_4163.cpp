 		    "\n"
 		    "    git push %s HEAD:<name-of-remote-branch>\n"),
 		    remote->name);
-	if (!branch->merge_nr || !branch->merge)
+	if (!branch->merge_nr || !branch->merge || !branch->remote_name)
 		die(_("The current branch %s has no upstream branch.\n"
 		    "To push the current branch and set the remote as upstream, use\n"
 		    "\n"
