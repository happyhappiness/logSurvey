 		data = read_object_with_reference(obj->sha1, tree_type,
 						  &size, NULL);
 		if (!data)
-			die("unable to read tree (%s)", sha1_to_hex(obj->sha1));
+			die(_("unable to read tree (%s)"), sha1_to_hex(obj->sha1));
 		init_tree_desc(&tree, data, size);
 		hit = grep_tree(opt, paths, &tree, name, "");
 		free(data);
 		return hit;
 	}
-	die("unable to grep from object of type %s", typename(obj->type));
+	die(_("unable to grep from object of type %s"), typename(obj->type));
 }
 
 static int grep_objects(struct grep_opt *opt, const char **paths,
