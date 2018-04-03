		cd sub &&
		git submodule sync >../../output
	) &&
	grep "\\.\\./submodule" output &&
	test -d "$(
		cd super-clone/submodule &&
		git config remote.origin.url
