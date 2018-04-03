 	test_cmp expected actual
 '
 
+cat >expected <<EOF
+hello.c=	printf("Hello world.\n");
+hello.c:	return 0;
+hello.c-	/* char ?? */
+EOF
+
+test_expect_success 'grep -W with userdiff' '
+	test_when_finished "rm -f .gitattributes" &&
+	git config diff.custom.xfuncname "(printf.*|})$" &&
+	echo "hello.c diff=custom" >.gitattributes &&
+	git grep -W return >actual &&
+	test_cmp expected actual
+'
+
 test_expect_success 'grep from a subdirectory to search wider area (1)' '
 	mkdir -p s &&
 	(