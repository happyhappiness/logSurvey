	garbage
	EOF
	test_when_finished "rm -rf almost_*" &&
	git clean -f -d &&
	test_path_is_missing almost_git &&
	test_path_is_missing almost_bare_git &&
