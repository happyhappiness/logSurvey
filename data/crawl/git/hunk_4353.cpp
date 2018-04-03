 	Read a line and strip off the trailing newline.
 	On failure or end of file, returns NULL.
 
-`buffer_read_string`::
-	Read `len` characters of input or up to the end of the
-	file, whichever comes first.  Returns NULL on error.
-	Returns whatever characters were read (possibly "")
-	for end of file.
-
 `buffer_copy_bytes`::
 	Read `len` bytes of input and dump them to the standard output
 	stream.  Returns early for error or end of file.