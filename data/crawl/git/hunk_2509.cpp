 			continue;
 		}
 		die("unknown pending object %s (%s)",
-		    sha1_to_hex(obj->sha1), name);
+		    oid_to_hex(&obj->oid), name);
 	}
 	object_array_clear(&revs->pending);
 	strbuf_release(&base);
