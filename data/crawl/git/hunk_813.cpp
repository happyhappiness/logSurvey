 	! grep branch output
 '
 
-test_expect_success PERL 'say no to the second file' '
+test_expect_success 'say no to the second file' '
 	(echo && echo n) >input &&
 	git difftool -x cat branch <input >output &&
 	grep master output &&
