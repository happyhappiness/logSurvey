		cd sub &&
		git submodule sync --recursive >../../output
	) &&
	grep "\\.\\./submodule/sub-submodule" output &&
	test -d "$(
		cd super-clone/submodule &&
		git config remote.origin.url
