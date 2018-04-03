 	test_must_fail git rev-parse :1:nothing.txt 2> error &&
 	grep "Path '"'"'nothing.txt'"'"' does not exist (neither on disk nor in the index)." error &&
 	test_must_fail git rev-parse :1:file.txt 2> error &&
-	grep "Did you mean '"'"':0:file.txt'"'"'?" error &&
+	test_did_you_mean ":0" "" file.txt "is in the index" "at stage 1" &&
 	(cd subdir &&
 	 test_must_fail git rev-parse :1:file.txt 2> error &&
-	 grep "Did you mean '"'"':0:file.txt'"'"'?" error &&
+	 test_did_you_mean ":0" "" file.txt "is in the index" "at stage 1" &&
 	 test_must_fail git rev-parse :file2.txt 2> error &&
-	 grep "Did you mean '"'"':0:subdir/file2.txt'"'"'?" error &&
+	 test_did_you_mean ":0" subdir/ file2.txt "is in the index" &&
 	 test_must_fail git rev-parse :2:file2.txt 2> error &&
-	 grep "Did you mean '"'"':0:subdir/file2.txt'"'"'?" error) &&
+	 test_did_you_mean :0 subdir/ file2.txt "is in the index") &&
 	test_must_fail git rev-parse :disk-only.txt 2> error &&
 	grep "fatal: Path '"'"'disk-only.txt'"'"' exists on disk, but not in the index." error
 '