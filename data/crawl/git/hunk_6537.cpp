 		status = error("unable to parse %s header", sha1_to_hex(sha1));
 	else if (sizep)
 		*sizep = size;
-	inflateEnd(&stream);
+	git_inflate_end(&stream);
 	munmap(map, mapsize);
 	return status;
 }
