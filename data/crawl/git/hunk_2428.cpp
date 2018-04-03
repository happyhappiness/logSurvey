 	struct bitmap_test_data *tdata = data;
 	int bitmap_pos;
 
-	bitmap_pos = bitmap_position(get_object_hash(*object));
+	bitmap_pos = bitmap_position(object->oid.hash);
 	if (bitmap_pos < 0)
 		die("Object not in bitmap: %s\n", oid_to_hex(&object->oid));
 
