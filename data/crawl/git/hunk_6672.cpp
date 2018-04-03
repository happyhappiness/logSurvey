 	if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
 		die("unable to read files to diff");
 
+	textconv_one = get_textconv(one);
+	textconv_two = get_textconv(two);
+
 	if (!DIFF_OPT_TST(o, TEXT) &&
-	    (diff_filespec_is_binary(one) || diff_filespec_is_binary(two))) {
+	    ( (diff_filespec_is_binary(one) && !textconv_one) ||
+	      (diff_filespec_is_binary(two) && !textconv_two) )) {
 		/* Quite common confusing case */
 		if (mf1.size == mf2.size &&
 		    !memcmp(mf1.ptr, mf2.ptr, mf1.size))
