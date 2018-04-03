 
 			data = lock_and_read_sha1_file(entry.sha1, &type, &size);
 			if (!data)
-				die("unable to read tree (%s)",
+				die(_("unable to read tree (%s)"),
 				    sha1_to_hex(entry.sha1));
 			init_tree_desc(&sub, data, size);
 			hit |= grep_tree(opt, paths, &sub, tree_name, down);
