 				continue;
 
 			if (data->name_only)
-				printf("%.*s%s", p_len - 40, p_start, name);
+				printf("%.*s%s", p_len - GIT_SHA1_HEXSZ, p_start, name);
 			else
 				printf("%.*s (%s)", p_len, p_start, name);
 			p_start = p + 1;
