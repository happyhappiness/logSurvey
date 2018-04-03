 
 	if (unset)
 		strbuf_setlen(buf, 0);
-	else {
+	else if (arg) {
 		strbuf_addf(buf, "%s\n\n", arg);
 		have_message = 1;
-	}
+	} else
+		return error("switch `m' requires a value");
 	return 0;
 }
 
