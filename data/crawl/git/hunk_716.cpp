 
 	int fd = odb_mkstemp(tmp_file, sizeof(tmp_file), "pack/tmp_bitmap_XXXXXX");
 
-	if (fd < 0)
-		die_errno("unable to create '%s'", tmp_file);
 	f = sha1fd(fd, tmp_file);
 
 	memcpy(header.magic, BITMAP_IDX_SIGNATURE, sizeof(BITMAP_IDX_SIGNATURE));
