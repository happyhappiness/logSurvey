 
 . ./test-lib.sh
 
+test_did_you_mean ()
+{
+	printf "fatal: Path '$2$3' $4, but not ${5:-'$3'}.\n" >expected &&
+	printf "Did you mean '$1:$2$3'?\n" >>expected &&
+	test_cmp expected error
+}
+
 HASH_file=
 
 test_expect_success 'set up basic repo' '
