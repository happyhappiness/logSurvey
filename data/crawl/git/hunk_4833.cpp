 	}
 
 	if (diff_filespec_is_binary(one) || diff_filespec_is_binary(two)) {
-		if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
-			die("unable to read files to diff");
 		data->is_binary = 1;
-		data->added = mf2.size;
-		data->deleted = mf1.size;
+		data->added = diff_filespec_size(two);
+		data->deleted = diff_filespec_size(one);
 	}
 
 	else if (complete_rewrite) {