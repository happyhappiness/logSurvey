 
 	bitmap_pos = bitmap_position(get_object_hash(*object));
 	if (bitmap_pos < 0)
-		die("Object not in bitmap: %s\n", sha1_to_hex(object->sha1));
+		die("Object not in bitmap: %s\n", oid_to_hex(&object->oid));
 
 	bitmap_set(tdata->base, bitmap_pos);
 	display_progress(tdata->prg, ++tdata->seen);
