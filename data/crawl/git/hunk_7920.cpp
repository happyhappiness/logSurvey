 	struct ref_lock *lock;
 
 	if (!prefixcmp(name, "refs/") && check_ref_format(name + 5)) {
-		error("refusing to create funny ref '%s' locally", name);
+		error("refusing to create funny ref '%s' remotely", name);
 		return "funny refname";
 	}
 