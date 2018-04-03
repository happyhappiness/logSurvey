 				prio_names[t->name->prio],
 				t->depth, t->name->path);
 		}
-		fprintf(stderr, "traversed %lu commits\n", seen_commits);
+		fprintf(stderr, _("traversed %lu commits\n"), seen_commits);
 		if (gave_up_on) {
 			fprintf(stderr,
-				"more than %i tags found; listed %i most recent\n"
-				"gave up search at %s\n",
+				_("more than %i tags found; listed %i most recent\n"
+				"gave up search at %s\n"),
 				max_candidates, max_candidates,
 				sha1_to_hex(gave_up_on->object.sha1));
 		}
