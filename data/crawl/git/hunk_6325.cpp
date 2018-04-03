 				return 0;
 	}
 	if (MAX_REVS <= ref_name_cnt) {
-		fprintf(stderr, "warning: ignoring %s; "
-			"cannot handle more than %d refs\n",
+		warning("ignoring %s; cannot handle more than %d refs",
 			refname, MAX_REVS);
 		return 0;
 	}