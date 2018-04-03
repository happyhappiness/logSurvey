 	struct commit_list *p;
 	for (p = commit->parents; p ; p = p->next) {
 		struct commit *parent = p->item;
-		printf(" %s", find_unique_abbrev(get_object_hash(parent->object), abbrev));
+		printf(" %s", find_unique_abbrev(parent->object.oid.hash, abbrev));
 	}
 }
 
 static void show_children(struct rev_info *opt, struct commit *commit, int abbrev)
 {
 	struct commit_list *p = lookup_decoration(&opt->children, &commit->object);
 	for ( ; p; p = p->next) {
-		printf(" %s", find_unique_abbrev(get_object_hash(p->item->object), abbrev));
+		printf(" %s", find_unique_abbrev(p->item->object.oid.hash, abbrev));
 	}
 }
 
