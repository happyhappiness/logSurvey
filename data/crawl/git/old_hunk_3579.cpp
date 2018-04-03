EOF

test_expect_success 'update default' '

	(cd one &&
	 for b in $(git branch -r)
	 do
		git branch -r -d $b || break
	 done &&
	 git config remote.drosophila.skipDefaultUpdate true &&
	 git remote update default &&
	 git branch -r > output &&
	 test_cmp expect output)

'

cat > one/expect << EOF
  drosophila/another
  drosophila/master
  drosophila/side
EOF

test_expect_success 'update default (overridden, with funny whitespace)' '

	(cd one &&
	 for b in $(git branch -r)
	 do
		git branch -r -d $b || break
	 done &&
	 git config remotes.default "$(printf "\t drosophila  \n")" &&
	 git remote update default &&
	 git branch -r > output &&
	 test_cmp expect output)

'

test_expect_success 'update (with remotes.default defined)' '

	(cd one &&
	 for b in $(git branch -r)
	 do
		git branch -r -d $b || break
	 done &&
	 git config remotes.default "drosophila" &&
	 git remote update &&
	 git branch -r > output &&
	 test_cmp expect output)

'

test_expect_success '"remote show" does not show symbolic refs' '

	git clone one three &&
	(cd three &&
	 git remote show origin > output &&
	 ! grep "^ *HEAD$" < output &&
	 ! grep -i stale < output)

'

test_expect_success 'reject adding remote with an invalid name' '

	test_must_fail git remote add some:url desired-name

'

# The first three test if the tracking branches are properly renamed,
# the last two ones check if the config is updated.

test_expect_success 'rename a remote' '

	git clone one four &&
	(cd four &&
	 git remote rename origin upstream &&
	 rmdir .git/refs/remotes/origin &&
	 test "$(git symbolic-ref refs/remotes/upstream/HEAD)" = "refs/remotes/upstream/master" &&
	 test "$(git rev-parse upstream/master)" = "$(git rev-parse master)" &&
	 test "$(git config remote.upstream.fetch)" = "+refs/heads/*:refs/remotes/upstream/*" &&
	 test "$(git config branch.master.remote)" = "upstream")

'

test_expect_success 'rename does not update a non-default fetch refspec' '

	git clone one four.one &&
	(cd four.one &&
	 git config remote.origin.fetch +refs/heads/*:refs/heads/origin/* &&
	 git remote rename origin upstream &&
	 test "$(git config remote.upstream.fetch)" = "+refs/heads/*:refs/heads/origin/*" &&
	 git rev-parse -q origin/master)

'

test_expect_success 'rename a remote with name part of fetch spec' '

	git clone one four.two &&
	(cd four.two &&
	 git remote rename origin remote &&
	 git remote rename remote upstream &&
	 test "$(git config remote.upstream.fetch)" = "+refs/heads/*:refs/remotes/upstream/*")

'

test_expect_success 'rename a remote with name prefix of other remote' '

	git clone one four.three &&
	(cd four.three &&
	 git remote add o git://example.com/repo.git &&
	 git remote rename o upstream &&
	 test "$(git rev-parse origin/master)" = "$(git rev-parse master)")

'

cat > remotes_origin << EOF
URL: $(pwd)/one
Push: refs/heads/master:refs/heads/upstream
Pull: refs/heads/master:refs/heads/origin
