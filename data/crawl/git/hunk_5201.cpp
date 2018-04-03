 
 '
 
+cat >expect <<\EOF
+## <GREEN>master<RESET>
+ <RED>M<RESET> dir1/modified
+<GREEN>A<RESET>  dir2/added
+<BLUE>??<RESET> dir1/untracked
+<BLUE>??<RESET> dir2/modified
+<BLUE>??<RESET> dir2/untracked
+<BLUE>??<RESET> expect
+<BLUE>??<RESET> output
+<BLUE>??<RESET> untracked
+EOF
+
+test_expect_success 'status -s -b with color.status' '
+
+	git status -s -b | test_decode_color >output &&
+	test_cmp expect output
+
+'
+
 cat >expect <<\EOF
  M dir1/modified
 A  dir2/added
