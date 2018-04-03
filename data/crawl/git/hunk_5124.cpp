 	else if (ents == 2)
 		result = builtin_diff_tree(&rev, argc, argv, ent);
 	else if (ent[0].item->flags & UNINTERESTING) {
-		/*
-		 * Perhaps the user gave us A...B, which expands
-		 * to a list of negative merge bases followed by
-		 * A (symmetric-left) and B?  Let's make sure...
-		 */
-		for (i = 1; i < ents; i++)
-			if (!(ent[i].item->flags & UNINTERESTING))
-				break;
-		if (ents != i + 2 ||
-		    (ent[i+1].item->flags & UNINTERESTING) ||
-		    (!(ent[i].item->flags & SYMMETRIC_LEFT)) ||
-		    (ent[i+1].item->flags & SYMMETRIC_LEFT))
-			die("what do you mean by that?");
 		/*
 		 * diff A...B where there is at least one merge base
 		 * between A and B.  We have ent[0] == merge-base,