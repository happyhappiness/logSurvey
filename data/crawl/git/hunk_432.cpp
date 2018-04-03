 		*file = o->file;
 }
 
-/*
- * Origin is refcounted and usually we keep the blob contents to be
- * reused.
- */
-static inline struct blame_origin *blame_origin_incref(struct blame_origin *o)
-{
-	if (o)
-		o->refcnt++;
-	return o;
-}
-
-static void blame_origin_decref(struct blame_origin *o)
-{
-	if (o && --o->refcnt <= 0) {
-		struct blame_origin *p, *l = NULL;
-		if (o->previous)
-			blame_origin_decref(o->previous);
-		free(o->file.ptr);
-		/* Should be present exactly once in commit chain */
-		for (p = o->commit->util; p; l = p, p = p->next) {
-			if (p == o) {
-				if (l)
-					l->next = p->next;
-				else
-					o->commit->util = p->next;
-				free(o);
-				return;
-			}
-		}
-		die("internal error in blame_origin_decref");
-	}
-}
-
 static void drop_origin_blob(struct blame_origin *o)
 {
 	if (o->file.ptr) {
