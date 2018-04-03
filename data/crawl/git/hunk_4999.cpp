 	unsigned long len;
 	void *dst;
 
+	if (!fragment)
+		return error("missing binary patch data for '%s'",
+			     patch->new_name ?
+			     patch->new_name :
+			     patch->old_name);
+
 	/* Binary patch is irreversible without the optional second hunk */
 	if (apply_in_reverse) {
 		if (!fragment->next)
