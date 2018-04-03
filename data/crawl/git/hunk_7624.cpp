 		void *buf;
 		unsigned long size;
 
+		if (S_ISGITLINK(mode))
+			die("cannot read object %s '%s': It is a submodule!",
+			    sha1_to_hex(sha), path);
+
 		buf = read_sha1_file(sha, &type, &size);
 		if (!buf)
 			die("cannot read object %s '%s'", sha1_to_hex(sha), path);
