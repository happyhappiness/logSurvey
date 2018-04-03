 	else
 		parent = commit->parents->item;
 
+	if (allow_ff && !hashcmp(parent->object.sha1, head))
+		return fast_forward_to(commit->object.sha1, head);
+
 	if (!(message = commit->buffer))
 		die ("Cannot get commit message for %s",
 				sha1_to_hex(commit->object.sha1));
