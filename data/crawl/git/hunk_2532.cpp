 	data = read_sha1_file(get_object_hash(item->object), &type, &size);
 	if (!data)
 		return error("Could not read %s",
-			     sha1_to_hex(item->object.sha1));
+			     oid_to_hex(&item->object.oid));
 	if (type != OBJ_TAG) {
 		free(data);
 		return error("Object %s not a tag",
-			     sha1_to_hex(item->object.sha1));
+			     oid_to_hex(&item->object.oid));
 	}
 	ret = parse_tag_buffer(item, data, size);
 	free(data);
