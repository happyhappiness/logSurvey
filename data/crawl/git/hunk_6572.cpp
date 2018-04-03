 		message_size = strlen(message);
 	}
 	tagger = memmem(buf, message ? message - buf : size, "\ntagger ", 8);
-	if (!tagger)
-		die ("No tagger for tag %s", sha1_to_hex(tag->object.sha1));
-	tagger++;
-	tagger_end = strchrnul(tagger, '\n');
+	if (!tagger) {
+		if (fake_missing_tagger)
+			tagger = "tagger Unspecified Tagger "
+				"<unspecified-tagger> 0 +0000";
+		else
+			tagger = "";
+		tagger_end = tagger + strlen(tagger);
+	} else {
+		tagger++;
+		tagger_end = strchrnul(tagger, '\n');
+	}
 
 	/* handle signed tags */
 	if (message) {
