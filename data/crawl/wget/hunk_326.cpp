 @code{Content-Disposition} headers to describe what the name of a
 downloaded file should be.
 
+@cindex Content On Error
+@item --content-on-error
+
+If this is set to on, wget will not skip the content when the server responds
+with a http status code that indicates error.
+
 @cindex Trust server names
 @item --trust-server-names
 
