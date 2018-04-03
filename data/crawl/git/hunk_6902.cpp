 			if (!name)
 				continue;
 
-			if (data->name_only) {
-				fwrite(p_start, p - p_start + 1 - 40, 1, stdout);
-				printf(name);
-			} else {
-				fwrite(p_start, p - p_start + 1, 1, stdout);
-				printf(" (%s)", name);
-			}
+			if (data->name_only)
+				printf("%.*s%s", p_len - 40, p_start, name);
+			else
+				printf("%.*s (%s)", p_len, p_start, name);
 			p_start = p + 1;
 		}
 	}