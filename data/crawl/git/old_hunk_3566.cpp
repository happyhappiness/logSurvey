
# $1 = local revision
# $2 = remote revision (tested to be equal to the local one)
check_pushed_commit () {
	git log -1 --format='%h %s' "$1" >expect &&
	git --git-dir=repo1 log -1 --format='%h %s' "$2" >actual &&
	test_cmp expect actual
}

# $1 = push.default value
# $2 = expected target branch for the push
test_push_success () {
	git -c push.default="$1" push &&
	check_pushed_commit HEAD "$2"
}

# $1 = push.default value