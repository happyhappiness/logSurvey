 EOF
 
 test_expect_success 'update' '
-
-	(cd one &&
-	 git remote add drosophila ../two &&
-	 git remote add apis ../mirror &&
-	 git remote update &&
-	 git branch -r > output &&
-	 test_cmp expect output)
-
+	(
+		cd one &&
+		git remote add drosophila ../two &&
+		git remote add apis ../mirror &&
+		git remote update &&
+		git branch -r >output &&
+		test_cmp expect output
+	)
 '
 
-cat > one/expect << EOF
+cat >one/expect <<\EOF
   drosophila/another
   drosophila/master
   drosophila/side
