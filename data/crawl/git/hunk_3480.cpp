 	! grep one output
 '
 
+test_expect_success 'rev-list A..B and rev-list ^A B are the same' '
+	git commit --allow-empty -m another &&
+	git tag -a -m "annotated" v1.0 &&
+	git rev-list --objects ^v1.0^ v1.0 >expect &&
+	git rev-list --objects v1.0^..v1.0 >actual &&
+	test_cmp expect actual
+'
+
 test_done