 		if (strbuf_check_branch_ref(&buf, opts.new_branch))
 			die("git checkout: we do not like '%s' as a branch name.",
 			    opts.new_branch);
-		if (!get_sha1(buf.buf, rev))
-			die("git checkout: branch %s already exists", opts.new_branch);
+		if (!get_sha1(buf.buf, rev)) {
+			opts.branch_exists = 1;
+			if (!opts.new_branch_force)
+				die("git checkout: branch %s already exists",
+				    opts.new_branch);
+		}
 		strbuf_release(&buf);
 	}
 
