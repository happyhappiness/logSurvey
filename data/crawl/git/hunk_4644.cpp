 			obj = parse_object(obj->sha1);
 		obj = deref_tag(obj, NULL, 0);
 		if (!obj)
-			die("invalid object '%s' given.", name);
+			die(_("invalid object '%s' given."), name);
 		if (obj->type == OBJ_COMMIT)
 			obj = &((struct commit *)obj)->tree->object;
 		if (obj->type == OBJ_TREE) {
 			if (ARRAY_SIZE(ent) <= ents)
-				die("more than %d trees given: '%s'",
+				die(_("more than %d trees given: '%s'"),
 				    (int) ARRAY_SIZE(ent), name);
 			obj->flags |= flags;
 			ent[ents].item = obj;
