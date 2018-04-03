 
 	memset(&data, 0, sizeof(data));
 	data.entry = entry;
-	data.st = open_istream(entry->idx.sha1, &type, &size, NULL);
+	data.st = open_istream(entry->idx.oid.hash, &type, &size, NULL);
 	if (!data.st)
 		return -1;
 	if (size != entry->size || type != entry->type)
 		die(_("SHA1 COLLISION FOUND WITH %s !"),
-		    sha1_to_hex(entry->idx.sha1));
+		    oid_to_hex(&entry->idx.oid));
 	unpack_data(entry, compare_objects, &data);
 	close_istream(data.st);
 	free(data.buf);
