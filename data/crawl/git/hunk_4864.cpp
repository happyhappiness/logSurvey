 			}
 		}
 
+		if (opts.force_detach)
+			die("git checkout: --detach does not take a path argument");
+
 		if (1 < !!opts.writeout_stage + !!opts.force + !!opts.merge)
 			die("git checkout: --ours/--theirs, --force and --merge are incompatible when\nchecking out of the index.");
 
