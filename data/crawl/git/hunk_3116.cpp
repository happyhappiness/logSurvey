 		if (data->info.sizep && size != data->size)
 			die("object %s changed size!?", sha1_to_hex(sha1));
 
-		write_or_die(fd, contents, size);
+		batch_write(opt, contents, size);
 		free(contents);
 	}
 }
 
-
 static int batch_one_object(const char *obj_name, struct batch_options *opt,
 			    struct expand_data *data)
 {
