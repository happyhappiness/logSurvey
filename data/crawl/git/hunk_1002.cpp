 		return fast_forward_to(commit->object.oid.hash, head, unborn, opts);
 
 	if (parent && parse_commit(parent) < 0)
-		/* TRANSLATORS: The first %s will be "revert" or
-		   "cherry-pick", the second %s a SHA1 */
+		/* TRANSLATORS: The first %s will be a "todo" command like
+		   "revert" or "pick", the second %s a SHA1. */
 		return error(_("%s: cannot parse parent commit %s"),
-			action_name(opts), oid_to_hex(&parent->object.oid));
+			command_to_string(command),
+			oid_to_hex(&parent->object.oid));
 
 	if (get_message(commit, &msg) != 0)
 		return error(_("Cannot get commit message for %s"),
