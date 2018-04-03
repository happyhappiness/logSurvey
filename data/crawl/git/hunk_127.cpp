 	}
 }
 
-static void write_note_data(struct note_data *d, unsigned char *sha1)
+static void write_note_data(struct note_data *d, struct object_id *oid)
 {
-	if (write_sha1_file(d->buf.buf, d->buf.len, blob_type, sha1)) {
+	if (write_object_file(d->buf.buf, d->buf.len, blob_type, oid)) {
 		error(_("unable to write note object"));
 		if (d->edit_path)
 			error(_("the note contents have been left in %s"),
