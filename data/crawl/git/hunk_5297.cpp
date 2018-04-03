 			strbuf_reset(&header);
 		}
 
-		if (textconv_one) {
-			size_t size;
-			mf1.ptr = run_textconv(textconv_one, one, &size);
-			if (!mf1.ptr)
-				die("unable to read files to diff");
-			mf1.size = size;
-		}
-		if (textconv_two) {
-			size_t size;
-			mf2.ptr = run_textconv(textconv_two, two, &size);
-			if (!mf2.ptr)
-				die("unable to read files to diff");
-			mf2.size = size;
-		}
+		mf1.size = fill_textconv(textconv_one, one, &mf1.ptr);
+		mf2.size = fill_textconv(textconv_two, two, &mf2.ptr);
 
 		pe = diff_funcname_pattern(one);
 		if (!pe)
