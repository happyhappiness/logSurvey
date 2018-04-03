 
 		children = lookup_decoration(&revs->children, &commit->object);
 		while (children) {
-			printf(" %s", sha1_to_hex(children->item->object.sha1));
+			printf(" %s", oid_to_hex(&children->item->object.oid));
 			children = children->next;
 		}
 	}
