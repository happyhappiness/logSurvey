 {
 	struct object *obj = &blob->object;
 
+	if (!blob)
+		die("bad blob object");
 	if (obj->flags & SEEN)
 		return;
 	obj->flags |= SEEN;
