 	)
 '
 
+test_expect_success 'reset submodule URLs' '
+	reset_submodule_urls super-clone
+'
+
+test_expect_success '"git submodule sync" should update submodule URLs - subdirectory' '
+	(
+		cd super-clone &&
+		git pull --no-recurse-submodules &&
+		mkdir -p sub &&
+		cd sub &&
+		git submodule sync >../../output
+	) &&
+	grep "\\.\\./submodule" output &&
+	test -d "$(
+		cd super-clone/submodule &&
+		git config remote.origin.url
+	)" &&
+	test ! -d "$(
+		cd super-clone/submodule/sub-submodule &&
+		git config remote.origin.url
+	)" &&
+	(
+		cd super-clone/submodule &&
+		git checkout master &&
+		git pull
+	) &&
+	(
+		cd super-clone &&
+		test -d "$(git config submodule.submodule.url)"
+	)
+'
+
+test_expect_success '"git submodule sync --recursive" should update all submodule URLs - subdirectory' '
+	(
+		cd super-clone &&
+		(
+			cd submodule &&
+			git pull --no-recurse-submodules
+		) &&
+		mkdir -p sub &&
+		cd sub &&
+		git submodule sync --recursive >../../output
+	) &&
+	grep "\\.\\./submodule/sub-submodule" output &&
+	test -d "$(
+		cd super-clone/submodule &&
+		git config remote.origin.url
+	)" &&
+	test -d "$(
+		cd super-clone/submodule/sub-submodule &&
+		git config remote.origin.url
+	)" &&
+	(
+		cd super-clone/submodule/sub-submodule &&
+		git checkout master &&
+		git pull
+	)
+'
+
 test_expect_success '"git submodule sync" should update known submodule URLs' '
 	(
 		cd empty-clone &&
