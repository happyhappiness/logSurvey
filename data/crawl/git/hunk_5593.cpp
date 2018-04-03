 		if (!prefixcmp(buf.buf, "fetch ")) {
 			parse_fetch(&buf);
 
-		} else if (!strcmp(buf.buf, "list")) {
-			struct ref *refs = get_refs();
-			struct ref *posn;
-			for (posn = refs; posn; posn = posn->next) {
-				if (posn->symref)
-					printf("@%s %s\n", posn->symref, posn->name);
-				else
-					printf("%s %s\n", sha1_to_hex(posn->old_sha1), posn->name);
-			}
-			printf("\n");
-			fflush(stdout);
+		} else if (!strcmp(buf.buf, "list") || !prefixcmp(buf.buf, "list ")) {
+			output_refs(get_refs());
+
+		} else if (!prefixcmp(buf.buf, "push ")) {
+			parse_push(&buf);
+
 		} else if (!prefixcmp(buf.buf, "option ")) {
 			char *name = buf.buf + strlen("option ");
 			char *value = strchr(name, ' ');
