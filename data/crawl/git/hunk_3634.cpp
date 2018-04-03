 		if (obj->type == OBJ_COMMIT)
 			obj = &((struct commit *)obj)->tree->object;
 		if (obj->type == OBJ_TREE) {
-			if (ARRAY_SIZE(ent) <= ents)
-				die(_("more than %d trees given: '%s'"),
-				    (int) ARRAY_SIZE(ent), name);
 			obj->flags |= flags;
-			ent[ents].item = obj;
-			ent[ents].name = name;
-			ents++;
+			add_object_array(obj, name, &ent);
 			continue;
 		}
 		if (obj->type == OBJ_BLOB) {
