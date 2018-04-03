 		printf("%-15s ", refname);
 
 		sp = buf = read_sha1_file(sha1, &type, &size);
-		if (!buf || !size)
+		if (!buf)
 			return 0;
+		if (!size) {
+			free(buf);
+			return 0;
+		}
 		/* skip header */
 		while (sp + 1 < buf + size &&
 				!(sp[0] == '\n' && sp[1] == '\n'))
 			sp++;
 		/* only take up to "lines" lines, and strip the signature */
-		for (i = 0, sp += 2; i < filter->lines && sp < buf + size &&
+		for (i = 0, sp += 2;
+				i < filter->lines && sp < buf + size &&
 				prefixcmp(sp, PGP_SIGNATURE "\n");
 				i++) {
 			if (i)
