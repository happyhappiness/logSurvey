 			if (cutoff > commit->date)
 				cutoff = commit->date;
 		}
+
+		if (peel_tag) {
+			if (!commit) {
+				fprintf(stderr, "Could not get commit for %s. Skipping.\n",
+					*argv);
+				continue;
+			}
+			object = (struct object *)commit;
+		}
 		add_object_array(object, *argv, &revs);
 	}
 
