 	if (prefixcmp(entry->name, base))
 		return 0;
 
-	if (!(flags & DO_FOR_EACH_INCLUDE_BROKEN)) {
-		if (entry->flag & REF_ISBROKEN)
-			return 0; /* ignore broken refs e.g. dangling symref */
-		if (!has_sha1_file(entry->u.value.sha1)) {
-			error("%s does not point to a valid object!", entry->name);
-			return 0;
-		}
-	}
+	if (!(flags & DO_FOR_EACH_INCLUDE_BROKEN) &&
+	      !ref_resolves_to_object(entry))
+		return 0;
+
 	current_ref = entry;
 	retval = fn(entry->name + trim, entry->u.value.sha1, entry->flag, cb_data);
 	current_ref = NULL;