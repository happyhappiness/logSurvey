 
 EOF
 
-touch empty
-
 test_expect_success 'R: quiet option results in no stats being output' '
     cat input | git fast-import 2> output &&
     test_cmp empty output