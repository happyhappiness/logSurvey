		cd sub &&
		git submodule sync --recursive >../../output
	) &&
	test_i18ngrep "\\.\\./submodule/sub-submodule" output &&
	test -d "$(
		cd super-clone/submodule &&
		git config remote.origin.url
