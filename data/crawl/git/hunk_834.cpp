 	return 0;
 }
 
-static int fsck_sha1(const unsigned char *sha1)
-{
-	struct object *obj = parse_object(sha1);
-	if (!obj) {
-		errors_found |= ERROR_OBJECT;
-		return error("%s: object corrupt or missing",
-			     sha1_to_hex(sha1));
-	}
-	obj->flags |= HAS_OBJ;
-	return fsck_obj(obj);
-}
-
 static int fsck_obj_buffer(const unsigned char *sha1, enum object_type type,
 			   unsigned long size, void *buffer, int *eaten)
 {
