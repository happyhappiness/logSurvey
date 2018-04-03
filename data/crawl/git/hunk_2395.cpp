 	o2 = rev->pending.objects[1].item;
 	flags1 = o1->flags;
 	flags2 = o2->flags;
-	c1 = lookup_commit_reference(get_object_hash(*o1));
-	c2 = lookup_commit_reference(get_object_hash(*o2));
+	c1 = lookup_commit_reference(o1->oid.hash);
+	c2 = lookup_commit_reference(o2->oid.hash);
 
 	if ((flags1 & UNINTERESTING) == (flags2 & UNINTERESTING))
 		die(_("Not a range."));
