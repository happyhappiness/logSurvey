 
 	if (!revs->blob_objects)
 		return;
+	if (!obj)
+		die("bad blob object");
 	if (obj->flags & (UNINTERESTING | SEEN))
 		return;
 	obj->flags |= SEEN;
