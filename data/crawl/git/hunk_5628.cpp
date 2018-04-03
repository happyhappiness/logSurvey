 		display_name(n);
 		if (longformat)
 			show_suffix(0, n->tag ? n->tag->tagged->sha1 : sha1);
+		if (dirty)
+			printf("%s", dirty);
 		printf("\n");
 		return;
 	}
