 			return checkout_entry(active_cache[pos], state, NULL);
 		pos++;
 	}
-	return error("path '%s' does not have %s version",
-		     ce->name,
-		     (stage == 2) ? "our" : "their");
+	if (stage == 2)
+		return error(_("path '%s' does not have our version"), ce->name);
+	else
+		return error(_("path '%s' does not have their version"), ce->name);
 }
 
 static int checkout_merged(int pos, struct checkout *state)