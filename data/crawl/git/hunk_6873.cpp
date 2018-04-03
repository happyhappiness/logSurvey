 						 branch1,
 						 branch2);
 				if (mfi.merge || !mfi.clean)
-					output(1, "Renamed %s->%s", src, ren1_dst);
+					output(1, "Renaming %s->%s", src, ren1_dst);
 
 				if (mfi.merge)
-					output(2, "Auto-merged %s", ren1_dst);
+					output(2, "Auto-merging %s", ren1_dst);
 
 				if (!mfi.clean) {
 					output(1, "CONFLICT (content): merge conflict in %s",
