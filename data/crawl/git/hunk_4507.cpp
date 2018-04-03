 
 	if (!remote) {
 		if (repo)
-			die("bad repository '%s'", repo);
-		die("No destination configured to push to.");
+			die(_("bad repository '%s'"), repo);
+		die(_("No destination configured to push to."));
 	}
 
 	if (remote->mirror)
 		flags |= (TRANSPORT_PUSH_MIRROR|TRANSPORT_PUSH_FORCE);
 
 	if ((flags & TRANSPORT_PUSH_ALL) && refspec) {
 		if (!strcmp(*refspec, "refs/tags/*"))
-			return error("--all and --tags are incompatible");
-		return error("--all can't be combined with refspecs");
+			return error(_("--all and --tags are incompatible"));
+		return error(_("--all can't be combined with refspecs"));
 	}
 
 	if ((flags & TRANSPORT_PUSH_MIRROR) && refspec) {
 		if (!strcmp(*refspec, "refs/tags/*"))
-			return error("--mirror and --tags are incompatible");
-		return error("--mirror can't be combined with refspecs");
+			return error(_("--mirror and --tags are incompatible"));
+		return error(_("--mirror can't be combined with refspecs"));
 	}
 
 	if ((flags & (TRANSPORT_PUSH_ALL|TRANSPORT_PUSH_MIRROR)) ==
 				(TRANSPORT_PUSH_ALL|TRANSPORT_PUSH_MIRROR)) {
-		return error("--all and --mirror are incompatible");
+		return error(_("--all and --mirror are incompatible"));
 	}
 
 	if (!refspec && !(flags & TRANSPORT_PUSH_ALL)) {
