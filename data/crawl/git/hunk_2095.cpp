 			*read_good = "good";
 			return;
 		} else {
-			die("could not read file '%s': %s", filename,
-				strerror(errno));
+			die_errno("could not read file '%s'", filename);
 		}
 	} else {
 		strbuf_getline_lf(&str, fp);