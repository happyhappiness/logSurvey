 					  local, remote);
 		}
 	}
+
+	return 0;
+
+out_err:
+	strbuf_release(&key);
+	error(_("Unable to write upstream branch configuration"));
+
+	advise(_(tracking_advice),
+	       origin ? origin : "",
+	       origin ? "/" : "",
+	       shortname ? shortname : remote);
+
+	return -1;
 }
 
 /*
  * This is called when new_ref is branched off of orig_ref, and tries
  * to infer the settings for branch.<new_ref>.{remote,merge} from the
  * config.
  */
-static int setup_tracking(const char *new_ref, const char *orig_ref,
-			  enum branch_track track, int quiet)
+static void setup_tracking(const char *new_ref, const char *orig_ref,
+			   enum branch_track track, int quiet)
 {
 	struct tracking tracking;
 	int config_flags = quiet ? 0 : BRANCH_CONFIG_VERBOSE;
 
 	memset(&tracking, 0, sizeof(tracking));
 	tracking.spec.dst = (char *)orig_ref;
 	if (for_each_remote(find_tracked_branch, &tracking))
-		return 1;
+		return;
 
 	if (!tracking.matches)
 		switch (track) {
