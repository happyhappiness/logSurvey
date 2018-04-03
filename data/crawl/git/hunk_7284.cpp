 					spec->dst ? ":" : "",
 					skip_prefix(spec->dst, "refs/heads/"));
 			}
+			printf("\n");
 		}
 cleanup_states:
 		/* NEEDSWORK: free remote */
