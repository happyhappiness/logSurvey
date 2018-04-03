 	struct bitmap_test_data *tdata = data;
 	int bitmap_pos;
 
-	bitmap_pos = bitmap_position(commit->object.sha1);
+	bitmap_pos = bitmap_position(get_object_hash(commit->object));
 	if (bitmap_pos < 0)
 		die("Object not in bitmap: %s\n", sha1_to_hex(commit->object.sha1));
 
