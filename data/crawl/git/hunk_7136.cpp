 	test-parse-options a1 --string 123 b1 --boolean -j 13 -- --boolean \
 		> output 2> output.err &&
 	test ! -s output.err &&
-	git diff expect output
+	test_cmp expect output
 '
 
 cat > expect << EOF