 EOF
 
 test_expect_success 'show -n' '
-	(mv one one.unreachable &&
-	 cd test &&
-	 git remote show -n origin > output &&
-	 mv ../one.unreachable ../one &&
-	 test_i18ncmp expect output)
+	mv one one.unreachable &&
+	(
+		cd test &&
+		git remote show -n origin >output &&
+		mv ../one.unreachable ../one &&
+		test_i18ncmp expect output
+	)
 '
 
 test_expect_success 'prune' '
-	(cd one &&
-	 git branch -m side side2) &&
-	(cd test &&
-	 git fetch origin &&
-	 git remote prune origin &&
-	 git rev-parse refs/remotes/origin/side2 &&
-	 test_must_fail git rev-parse refs/remotes/origin/side)
+	(
+		cd one &&
+		git branch -m side side2
+	) &&
+	(
+		cd test &&
+		git fetch origin &&
+		git remote prune origin &&
+		git rev-parse refs/remotes/origin/side2 &&
+		test_must_fail git rev-parse refs/remotes/origin/side
+	)
 '
 
 test_expect_success 'set-head --delete' '
-	(cd test &&
-	 git symbolic-ref refs/remotes/origin/HEAD &&
-	 git remote set-head --delete origin &&
-	 test_must_fail git symbolic-ref refs/remotes/origin/HEAD)
+	(
+		cd test &&
+		git symbolic-ref refs/remotes/origin/HEAD &&
+		git remote set-head --delete origin &&
+		test_must_fail git symbolic-ref refs/remotes/origin/HEAD
+	)
 '
 
 test_expect_success 'set-head --auto' '
-	(cd test &&
-	 git remote set-head --auto origin &&
-	 echo refs/remotes/origin/master >expect &&
-	 git symbolic-ref refs/remotes/origin/HEAD >output &&
-	 test_cmp expect output
+	(
+		cd test &&
+		git remote set-head --auto origin &&
+		echo refs/remotes/origin/master >expect &&
+		git symbolic-ref refs/remotes/origin/HEAD >output &&
+		test_cmp expect output
 	)
 '
 
-cat >test/expect <<EOF
+cat >test/expect <<\EOF
 error: Multiple remote HEAD branches. Please choose one explicitly with:
   git remote set-head two another
   git remote set-head two master
 EOF
 
 test_expect_success 'set-head --auto fails w/multiple HEADs' '
-	(cd test &&
-	 test_must_fail git remote set-head --auto two >output 2>&1 &&
-	test_i18ncmp expect output)
+	(
+		cd test &&
+		test_must_fail git remote set-head --auto two >output 2>&1 &&
+		test_i18ncmp expect output
+	)
 '
 
-cat >test/expect <<EOF
+cat >test/expect <<\EOF
 refs/remotes/origin/side2
 EOF
 
 test_expect_success 'set-head explicit' '
-	(cd test &&
-	 git remote set-head origin side2 &&
-	 git symbolic-ref refs/remotes/origin/HEAD >output &&
-	 git remote set-head origin master &&
-	 test_cmp expect output)
+	(
+		cd test &&
+		git remote set-head origin side2 &&
+		git symbolic-ref refs/remotes/origin/HEAD >output &&
+		git remote set-head origin master &&
+		test_cmp expect output
+	)
 '
 
-cat > test/expect << EOF
+cat >test/expect <<EOF
 Pruning origin
 URL: $(pwd)/one
  * [would prune] origin/side2
 EOF
 
 test_expect_success 'prune --dry-run' '
-	(cd one &&
-	 git branch -m side2 side) &&
-	(cd test &&
-	 git remote prune --dry-run origin > output &&
-	 git rev-parse refs/remotes/origin/side2 &&
-	 test_must_fail git rev-parse refs/remotes/origin/side &&
-	(cd ../one &&
-	 git branch -m side side2) &&
-	 test_i18ncmp expect output)
+	(
+		cd one &&
+		git branch -m side2 side) &&
+	(
+		cd test &&
+		git remote prune --dry-run origin >output &&
+		git rev-parse refs/remotes/origin/side2 &&
+		test_must_fail git rev-parse refs/remotes/origin/side &&
+	(
+		cd ../one &&
+		git branch -m side side2) &&
+		test_i18ncmp expect output
+	)
 '
 
 test_expect_success 'add --mirror && prune' '
-	(mkdir mirror &&
-	 cd mirror &&
-	 git init --bare &&
-	 git remote add --mirror -f origin ../one) &&
-	(cd one &&
-	 git branch -m side2 side) &&
-	(cd mirror &&
-	 git rev-parse --verify refs/heads/side2 &&
-	 test_must_fail git rev-parse --verify refs/heads/side &&
-	 git fetch origin &&
-	 git remote prune origin &&
-	 test_must_fail git rev-parse --verify refs/heads/side2 &&
-	 git rev-parse --verify refs/heads/side)
+	mkdir mirror &&
+	(
+		cd mirror &&
+		git init --bare &&
+		git remote add --mirror -f origin ../one
+	) &&
+	(
+		cd one &&
+		git branch -m side2 side
+	) &&
+	(
+		cd mirror &&
+		git rev-parse --verify refs/heads/side2 &&
+		test_must_fail git rev-parse --verify refs/heads/side &&
+		git fetch origin &&
+		git remote prune origin &&
+		test_must_fail git rev-parse --verify refs/heads/side2 &&
+		git rev-parse --verify refs/heads/side
+	)
 '
 
 test_expect_success 'add --mirror=fetch' '
 	mkdir mirror-fetch &&
 	git init mirror-fetch/parent &&
-	(cd mirror-fetch/parent &&
-	 test_commit one) &&
+	(
+		cd mirror-fetch/parent &&
+		test_commit one
+	) &&
 	git init --bare mirror-fetch/child &&
-	(cd mirror-fetch/child &&
-	 git remote add --mirror=fetch -f parent ../parent)
+	(
+		cd mirror-fetch/child &&
+		git remote add --mirror=fetch -f parent ../parent
+	)
 '
 
 test_expect_success 'fetch mirrors act as mirrors during fetch' '
-	(cd mirror-fetch/parent &&
-	 git branch new &&
-	 git branch -m master renamed
+	(
+		cd mirror-fetch/parent &&
+		git branch new &&
+		git branch -m master renamed
 	) &&
-	(cd mirror-fetch/child &&
-	 git fetch parent &&
-	 git rev-parse --verify refs/heads/new &&
-	 git rev-parse --verify refs/heads/renamed
+	(
+		cd mirror-fetch/child &&
+		git fetch parent &&
+		git rev-parse --verify refs/heads/new &&
+		git rev-parse --verify refs/heads/renamed
 	)
 '
 
 test_expect_success 'fetch mirrors can prune' '
-	(cd mirror-fetch/child &&
-	 git remote prune parent &&
-	 test_must_fail git rev-parse --verify refs/heads/master
+	(
+		cd mirror-fetch/child &&
+		git remote prune parent &&
+		test_must_fail git rev-parse --verify refs/heads/master
 	)
 '
 
 test_expect_success 'fetch mirrors do not act as mirrors during push' '
-	(cd mirror-fetch/parent &&
-	 git checkout HEAD^0
+	(
+		cd mirror-fetch/parent &&
+		git checkout HEAD^0
 	) &&
-	(cd mirror-fetch/child &&
-	 git branch -m renamed renamed2 &&
-	 git push parent :
+	(
+		cd mirror-fetch/child &&
+		git branch -m renamed renamed2 &&
+		git push parent :
 	) &&
-	(cd mirror-fetch/parent &&
-	 git rev-parse --verify renamed &&
-	 test_must_fail git rev-parse --verify refs/heads/renamed2
+	(
+		cd mirror-fetch/parent &&
+		git rev-parse --verify renamed &&
+		test_must_fail git rev-parse --verify refs/heads/renamed2
 	)
 '
 
 test_expect_success 'add fetch mirror with specific branches' '
 	git init --bare mirror-fetch/track &&
-	(cd mirror-fetch/track &&
-	 git remote add --mirror=fetch -t heads/new parent ../parent
+	(
+		cd mirror-fetch/track &&
+		git remote add --mirror=fetch -t heads/new parent ../parent
 	)
 '
 
 test_expect_success 'fetch mirror respects specific branches' '
-	(cd mirror-fetch/track &&
-	 git fetch parent &&
-	 git rev-parse --verify refs/heads/new &&
-	 test_must_fail git rev-parse --verify refs/heads/renamed
+	(
+		cd mirror-fetch/track &&
+		git fetch parent &&
+		git rev-parse --verify refs/heads/new &&
+		test_must_fail git rev-parse --verify refs/heads/renamed
 	)
 '
 
 test_expect_success 'add --mirror=push' '
 	mkdir mirror-push &&
 	git init --bare mirror-push/public &&
 	git init mirror-push/private &&
-	(cd mirror-push/private &&
-	 test_commit one &&
-	 git remote add --mirror=push public ../public
+	(
+		cd mirror-push/private &&
+		test_commit one &&
+		git remote add --mirror=push public ../public
 	)
 '
 
 test_expect_success 'push mirrors act as mirrors during push' '
-	(cd mirror-push/private &&
-	 git branch new &&
-	 git branch -m master renamed &&
-	 git push public
+	(
+		cd mirror-push/private &&
+		git branch new &&
+		git branch -m master renamed &&
+		git push public
 	) &&
-	(cd mirror-push/private &&
-	 git rev-parse --verify refs/heads/new &&
-	 git rev-parse --verify refs/heads/renamed &&
-	 test_must_fail git rev-parse --verify refs/heads/master
+	(
+		cd mirror-push/private &&
+		git rev-parse --verify refs/heads/new &&
+		git rev-parse --verify refs/heads/renamed &&
+		test_must_fail git rev-parse --verify refs/heads/master
 	)
 '
 
 test_expect_success 'push mirrors do not act as mirrors during fetch' '
-	(cd mirror-push/public &&
-	 git branch -m renamed renamed2 &&
-	 git symbolic-ref HEAD refs/heads/renamed2
+	(
+		cd mirror-push/public &&
+		git branch -m renamed renamed2 &&
+		git symbolic-ref HEAD refs/heads/renamed2
 	) &&
-	(cd mirror-push/private &&
-	 git fetch public &&
-	 git rev-parse --verify refs/heads/renamed &&
-	 test_must_fail git rev-parse --verify refs/heads/renamed2
+	(
+		cd mirror-push/private &&
+		git fetch public &&
+		git rev-parse --verify refs/heads/renamed &&
+		test_must_fail git rev-parse --verify refs/heads/renamed2
 	)
 '
 
 test_expect_success 'push mirrors do not allow you to specify refs' '
 	git init mirror-push/track &&
-	(cd mirror-push/track &&
-	 test_must_fail git remote add --mirror=push -t new public ../public
+	(
+		cd mirror-push/track &&
+		test_must_fail git remote add --mirror=push -t new public ../public
 	)
 '
 
 test_expect_success 'add alt && prune' '
-	(mkdir alttst &&
-	 cd alttst &&
-	 git init &&
-	 git remote add -f origin ../one &&
-	 git config remote.alt.url ../one &&
-	 git config remote.alt.fetch "+refs/heads/*:refs/remotes/origin/*") &&
-	(cd one &&
-	 git branch -m side side2) &&
-	(cd alttst &&
-	 git rev-parse --verify refs/remotes/origin/side &&
-	 test_must_fail git rev-parse --verify refs/remotes/origin/side2 &&
-	 git fetch alt &&
-	 git remote prune alt &&
-	 test_must_fail git rev-parse --verify refs/remotes/origin/side &&
-	 git rev-parse --verify refs/remotes/origin/side2)
+	mkdir alttst &&
+	(
+		cd alttst &&
+		git init &&
+		git remote add -f origin ../one &&
+		git config remote.alt.url ../one &&
+		git config remote.alt.fetch "+refs/heads/*:refs/remotes/origin/*"
+	) &&
+	(
+		cd one &&
+		git branch -m side side2
+	) &&
+	(
+		cd alttst &&
+		git rev-parse --verify refs/remotes/origin/side &&
+		test_must_fail git rev-parse --verify refs/remotes/origin/side2 &&
+		git fetch alt &&
+		git remote prune alt &&
+		test_must_fail git rev-parse --verify refs/remotes/origin/side &&
+		git rev-parse --verify refs/remotes/origin/side2
+	)
 '
 
 cat >test/expect <<\EOF
 some-tag
 EOF
 
 test_expect_success 'add with reachable tags (default)' '
-	(cd one &&
-	 >foobar &&
-	 git add foobar &&
-	 git commit -m "Foobar" &&
-	 git tag -a -m "Foobar tag" foobar-tag &&
-	 git reset --hard HEAD~1 &&
-	 git tag -a -m "Some tag" some-tag) &&
-	(mkdir add-tags &&
-	 cd add-tags &&
-	 git init &&
-	 git remote add -f origin ../one &&
-	 git tag -l some-tag >../test/output &&
-	 git tag -l foobar-tag >>../test/output &&
-	 test_must_fail git config remote.origin.tagopt) &&
+	(
+		cd one &&
+		>foobar &&
+		git add foobar &&
+		git commit -m "Foobar" &&
+		git tag -a -m "Foobar tag" foobar-tag &&
+		git reset --hard HEAD~1 &&
+		git tag -a -m "Some tag" some-tag
+	) &&
+	mkdir add-tags &&
+	(
+		cd add-tags &&
+		git init &&
+		git remote add -f origin ../one &&
+		git tag -l some-tag >../test/output &&
+		git tag -l foobar-tag >>../test/output &&
+		test_must_fail git config remote.origin.tagopt
+	) &&
 	test_cmp test/expect test/output
 '
 
