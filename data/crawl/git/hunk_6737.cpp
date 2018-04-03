 "You may want to amend it after fixing the message, or set the config\n"
 "variable i18n.commitencoding to the encoding your project uses.\n";
 
-static void add_parent(struct strbuf *sb, const unsigned char *sha1)
-{
-	struct object *obj = parse_object(sha1);
-	const char *parent = sha1_to_hex(sha1);
-	const char *cp;
-
-	if (!obj)
-		die("Unable to find commit parent %s", parent);
-	if (obj->type != OBJ_COMMIT)
-		die("Parent %s isn't a proper commit", parent);
-
-	for (cp = sb->buf; cp && (cp = strstr(cp, "\nparent ")); cp += 8) {
-		if (!memcmp(cp + 8, parent, 40) && cp[48] == '\n') {
-			error("duplicate parent %s ignored", parent);
-			return;
-		}
-	}
-	strbuf_addf(sb, "parent %s\n", parent);
-}
-
 int cmd_commit(int argc, const char **argv, const char *prefix)
 {
-	int header_len;
 	struct strbuf sb;
 	const char *index_file, *reflog_msg;
 	char *nl, *p;
 	unsigned char commit_sha1[20];
 	struct ref_lock *ref_lock;
+	struct commit_list *parents = NULL, **pptr = &parents;
 
 	git_config(git_commit_config, NULL);
 
