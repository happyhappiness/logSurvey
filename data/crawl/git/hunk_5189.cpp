 	      (diff_filespec_is_binary(two) && !textconv_two) )) {
 		/* Quite common confusing case */
 		if (mf1.size == mf2.size &&
-		    !memcmp(mf1.ptr, mf2.ptr, mf1.size))
+		    !memcmp(mf1.ptr, mf2.ptr, mf1.size)) {
+			if (must_show_header)
+				fprintf(o->file, "%s", header.buf);
 			goto free_ab_and_return;
+		}
 		fprintf(o->file, "%s", header.buf);
 		strbuf_reset(&header);
 		if (DIFF_OPT_TST(o, BINARY))
