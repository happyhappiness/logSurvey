 			    DIFF_STATUS_ADDED)
 				added = 0;
 		if (added)
-			printf("%snew file mode %06o",
-			       c_meta, elem->mode);
+			printf("%s%snew file mode %06o",
+			       line_prefix, c_meta, elem->mode);
 		else {
 			if (deleted)
-				printf("%sdeleted file ", c_meta);
+				printf("%s%sdeleted file ",
+				       line_prefix, c_meta);
 			printf("mode ");
 			for (i = 0; i < num_parent; i++) {
 				printf("%s%06o", i ? "," : "",
