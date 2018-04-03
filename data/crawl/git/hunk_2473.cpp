 			o = parse_object(get_object_hash(*t->tagged));
 			if (!o)
 				ret = error(_("Could not read object %s"),
-					    sha1_to_hex(t->tagged->sha1));
+					    oid_to_hex(&t->tagged->oid));
 			objects[i].item = o;
 			i--;
 			break;
