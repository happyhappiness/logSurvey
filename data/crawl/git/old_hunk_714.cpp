	)
}

test_expect_success 'setup' '
	test_create_repo_with_commit sub &&
	echo output > .gitignore &&
