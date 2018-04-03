 		message = "(revision walker failed)";
 
 	if (dirty_submodule & DIRTY_SUBMODULE_UNTRACKED)
-		fprintf(f, "Submodule %s contains untracked content\n", path);
+		fprintf(f, "%sSubmodule %s contains untracked content\n",
+			line_prefix, path);
 	if (dirty_submodule & DIRTY_SUBMODULE_MODIFIED)
-		fprintf(f, "Submodule %s contains modified content\n", path);
+		fprintf(f, "%sSubmodule %s contains modified content\n",
+			line_prefix, path);
 
 	if (!hashcmp(one, two)) {
 		strbuf_release(&sb);
 		return;
 	}
 
-	strbuf_addf(&sb, "%sSubmodule %s %s..", meta, path,
+	strbuf_addf(&sb, "%s%sSubmodule %s %s..", line_prefix, meta, path,
 			find_unique_abbrev(one, DEFAULT_ABBREV));
 	if (!fast_backward && !fast_forward)
 		strbuf_addch(&sb, '.');
