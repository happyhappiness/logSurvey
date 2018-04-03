 				return;
 			}
 			if (!(f = fopen(filename, "w")))
-				die("Could not open %s", filename);
+				die_errno("Could not open '%s'", filename);
 			if (obj->type == OBJ_BLOB) {
 				enum object_type type;
 				unsigned long size;
