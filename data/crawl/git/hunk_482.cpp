 
 	if (SIMILAR_ENOUGH(best_similarity)) {
 		fprintf_ln(stderr,
-			   Q_("\nDid you mean this?",
-			      "\nDid you mean one of these?",
+			   Q_("\nThe most similar command is",
+			      "\nThe most similar commands are",
 			   n));
 
 		for (i = 0; i < n; i++)