 	if (fill_mmfile(&mf1, one) < 0 || fill_mmfile(&mf2, two) < 0)
 		die("unable to read files to diff");
 
-	if (DIFF_OPT_TST(o, ALLOW_TEXTCONV)) {
-		textconv_one = get_textconv(one);
-		textconv_two = get_textconv(two);
-	}
-
 	if (!DIFF_OPT_TST(o, TEXT) &&
 	    ( (diff_filespec_is_binary(one) && !textconv_one) ||
 	      (diff_filespec_is_binary(two) && !textconv_two) )) {
