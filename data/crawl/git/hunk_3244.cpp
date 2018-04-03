 	if (batch.enabled)
 		return batch_objects(&batch);
 
-	return cat_one_file(opt, exp_type, obj_name);
+	if (unknown_type && opt != 't' && opt != 's')
+		die("git cat-file --allow-unknown-type: use with -s or -t");
+	return cat_one_file(opt, exp_type, obj_name, unknown_type);
 }