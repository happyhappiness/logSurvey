	git format-patch --ignore-if-in-upstream HEAD
'

git_version="$(git --version | sed "s/.* //")"

signature() {
	printf "%s\n%s\n\n" "-- " "${1:-$git_version}"
}

test_expect_success 'format-patch default signature' '
	git format-patch --stdout -1 | tail -n 3 >output &&
	signature >expect &&
	test_cmp expect output
'

test_expect_success 'format-patch --signature' '
	git format-patch --stdout --signature="my sig" -1 | tail -n 3 >output &&
	signature "my sig" >expect &&
	test_cmp expect output
'

test_expect_success 'format-patch with format.signature config' '
