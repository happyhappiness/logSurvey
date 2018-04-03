EOF

test_expect_success 'show' '
	(
		cd test &&
		git config --add remote.origin.fetch refs/heads/master:refs/heads/upstream &&
		git fetch &&
		git checkout -b ahead origin/master &&
		echo 1 >>file &&
		test_tick &&
		git commit -m update file &&
		git checkout master &&
		git branch --track octopus origin/master &&
		git branch --track rebase origin/master &&
		git branch -d -r origin/master &&
		git config --add remote.two.url ../two &&
		git config --add remote.two.pushurl ../three &&
		git config branch.rebase.rebase true &&
		git config branch.octopus.merge "topic-a topic-b topic-c" &&
		(
			cd ../one &&
			echo 1 >file &&
			test_tick &&
			git commit -m update file
		) &&
		git config --add remote.origin.push : &&
		git config --add remote.origin.push refs/heads/master:refs/heads/upstream &&
		git config --add remote.origin.push +refs/tags/lastbackup &&
		git config --add remote.two.push +refs/heads/ahead:refs/heads/master &&
		git config --add remote.two.push refs/heads/master:refs/heads/another &&
		git remote show origin two >output &&
		git branch -d rebase octopus &&
		test_i18ncmp expect output
	)
'

cat >test/expect <<EOF
* remote origin
  Fetch URL: $(pwd)/one
  Push  URL: $(pwd)/one
