 
 	if (transform_stdin) {
 		char buffer[2048];
-		char *p, *p_start;
 
 		while (!feof(stdin)) {
-			int forty = 0;
-			p = fgets(buffer, sizeof(buffer), stdin);
+			char *p = fgets(buffer, sizeof(buffer), stdin);
 			if (!p)
 				break;
-
-			for (p_start = p; *p; p++) {
-#define ishex(x) (isdigit((x)) || ((x) >= 'a' && (x) <= 'f'))
-				if (!ishex(*p))
-					forty = 0;
-				else if (++forty == 40 &&
-						!ishex(*(p+1))) {
-					unsigned char sha1[40];
-					const char *name = NULL;
-					char c = *(p+1);
-
-					forty = 0;
-
-					*(p+1) = 0;
-					if (!get_sha1(p - 39, sha1)) {
-						struct object *o =
-							lookup_object(sha1);
-						if (o)
-							name = get_rev_name(o);
-					}
-					*(p+1) = c;
-
-					if (!name)
-						continue;
-
-					fwrite(p_start, p - p_start + 1, 1, stdout);
-					printf(" (%s)", name);
-					p_start = p + 1;
-				}
-			}
-
-			/* flush */
-			if (p_start != p)
-				fwrite(p_start, p - p_start, 1, stdout);
+			name_rev_line(p, &data);
 		}
 	} else if (all) {
 		int i, max;