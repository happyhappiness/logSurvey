 
 		diff_fill_sha1_info(p->one);
 		diff_fill_sha1_info(p->two);
-		if (fill_mmfile(&mf1, p->one) < 0 ||
-				fill_mmfile(&mf2, p->two) < 0)
-			return error("unable to read files to diff");
 
 		len1 = remove_space(p->one->path, strlen(p->one->path));
 		len2 = remove_space(p->two->path, strlen(p->two->path));
