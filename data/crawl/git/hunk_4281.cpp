 		name = xstrdup(buf);
 		if (fgetc(in) != '\t')
 			die("corrupt MERGE_RR");
-		for (i = 0; i < sizeof(buf) && (buf[i] = fgetc(in)); i++)
-			; /* do nothing */
+		for (i = 0; i < sizeof(buf); i++) {
+			int c = fgetc(in);
+			if (c < 0)
+				die("corrupt MERGE_RR");
+			buf[i] = c;
+			if (c == 0)
+				 break;
+		}
 		if (i == sizeof(buf))
 			die("filename too long");
 		string_list_insert(rr, buf)->util = name;