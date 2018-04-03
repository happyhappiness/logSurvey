 	is_tag_ref = !prefixcmp(path, "refs/tags/");
 
 	/* ALWAYS pack refs that were already packed or are tags */
-	if (!cb->all && !is_tag_ref && !(flags & REF_ISPACKED))
+	if (!(cb->flags & PACK_REFS_ALL) && !is_tag_ref && !(flags & REF_ISPACKED))
 		return 0;
 
 	fprintf(cb->refs_file, "%s %s\n", sha1_to_hex(sha1), path);
