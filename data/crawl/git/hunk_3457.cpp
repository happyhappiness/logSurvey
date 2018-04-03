 		die(_("reference repository '%s' is not a local repository."),
 		    item->string);
 
+	if (!access(mkpath("%s/shallow", ref_git), F_OK))
+		die(_("reference repository '%s' is shallow"), item->string);
+
+	if (!access(mkpath("%s/info/grafts", ref_git), F_OK))
+		die(_("reference repository '%s' is grafted"), item->string);
+
 	strbuf_addf(&alternate, "%s/objects", ref_git);
 	add_to_alternates_file(alternate.buf);
 	strbuf_release(&alternate);