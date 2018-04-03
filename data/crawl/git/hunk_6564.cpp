 		upstream = argv[1];
 		break;
 	default:
-		usage(cherry_usage);
+		current_branch = branch_get(NULL);
+		if (!current_branch || !current_branch->merge
+					|| !current_branch->merge[0]
+					|| !current_branch->merge[0]->dst) {
+			fprintf(stderr, "Could not find a tracked"
+					" remote branch, please"
+					" specify <upstream> manually.\n");
+			usage(cherry_usage);
+		}
+
+		upstream = current_branch->merge[0]->dst;
 	}
 
 	init_revisions(&revs, prefix);