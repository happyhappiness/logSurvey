 	int fd;
 };
 
-static int repack_without_ref_fn(const char *refname, const unsigned char *sha1,
-				 int flags, void *cb_data)
+static int repack_without_ref_fn(struct ref_entry *entry, void *cb_data)
 {
 	struct repack_without_ref_sb *data = cb_data;
 	char line[PATH_MAX + 100];
 	int len;
 
-	if (!strcmp(data->refname, refname))
+	if (!strcmp(data->refname, entry->name))
 		return 0;
+	if (!ref_resolves_to_object(entry))
+		return 0; /* Skip broken refs */
 	len = snprintf(line, sizeof(line), "%s %s\n",
-		       sha1_to_hex(sha1), refname);
+		       sha1_to_hex(entry->u.value.sha1), entry->name);
 	/* this should not happen but just being defensive */
 	if (len > sizeof(line))
-		die("too long a refname '%s'", refname);
+		die("too long a refname '%s'", entry->name);
 	write_or_die(data->fd, line, len);
 	return 0;
 }
