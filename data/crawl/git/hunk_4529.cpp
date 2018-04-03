 	if (!rla)
 		rla = sep = "";
 	if (snprintf(buf, size, "%s%s%s", rla, sep, action) >= size)
-		warning("Reflog action message too long: %.*s...", 50, buf);
+		warning(_("Reflog action message too long: %.*s..."), 50, buf);
 }
 
 static void die_if_unmerged_cache(int reset_type)
