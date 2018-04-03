 		return 0;
 	default:
 		die(_("submodule entry '%s' (%s) is a %s, not a commit"),
-		    cb->path, oid_to_hex(oid), typename(type));
+		    cb->path, oid_to_hex(oid), type_name(type));
 	}
 }
 
