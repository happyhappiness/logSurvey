 		format_commit_message(commit, "%an <%ae>", &buf, &ctx);
 		return strbuf_detach(&buf, NULL);
 	}
-	die("No existing author found with '%s'", name);
+	die(_("No existing author found with '%s'"), name);
 }
 
 
