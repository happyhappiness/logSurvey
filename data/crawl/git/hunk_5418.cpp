 		 merge:1;
 };
 
-static void fill_mm(const unsigned char *sha1, mmfile_t *mm)
-{
-	unsigned long size;
-	enum object_type type;
-
-	if (!hashcmp(sha1, null_sha1)) {
-		mm->ptr = xstrdup("");
-		mm->size = 0;
-		return;
-	}
-
-	mm->ptr = read_sha1_file(sha1, &type, &size);
-	if (!mm->ptr || type != OBJ_BLOB)
-		die("unable to read blob object %s", sha1_to_hex(sha1));
-	mm->size = size;
-}
-
 static int merge_3way(struct merge_options *o,
 		      mmbuffer_t *result_buf,
 		      struct diff_filespec *one,
