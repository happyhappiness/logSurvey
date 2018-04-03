 	return ret;
 }
 
-int fetch(unsigned char *sha1)
+static int fetch(struct walker *walker, unsigned char *sha1)
 {
-	struct alt_base *altbase = alt;
+	struct walker_data *data = walker->data;
+	struct alt_base *altbase = data->alt;
 
-	if (!fetch_object(altbase, sha1))
+	if (!fetch_object(walker, altbase, sha1))
 		return 0;
 	while (altbase) {
-		if (!fetch_pack(altbase, sha1))
+		if (!fetch_pack(walker, altbase, sha1))
 			return 0;
-		fetch_alternates(alt->base);
+		fetch_alternates(walker, data->alt->base);
 		altbase = altbase->next;
 	}
 	return error("Unable to find %s under %s", sha1_to_hex(sha1),
-		     alt->base);
+		     data->alt->base);
 }
 
 static inline int needs_quote(int ch)
