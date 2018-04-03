 		builtin_diff(name, other ? other : name,
 			     one, two, xfrm_msg, o, complete_rewrite);
 	else
-		printf("* Unmerged path %s\n", name);
+		fprintf(o->file, "* Unmerged path %s\n", name);
 }
 
 static void diff_fill_sha1_info(struct diff_filespec *one)
