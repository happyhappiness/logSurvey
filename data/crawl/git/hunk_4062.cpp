 		o->flags |= OUR_REF;
 		nr_our_refs++;
 	}
-	if (o->type == OBJ_TAG) {
-		o = deref_tag_noverify(o);
-		if (o)
-			packet_write(1, "%s %s^{}\n", sha1_to_hex(o->sha1), refname_nons);
-	}
+	if (!peel_ref(refname, peeled))
+		packet_write(1, "%s %s^{}\n", sha1_to_hex(peeled), refname_nons);
 	return 0;
 }
 