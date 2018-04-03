	git log -2 > output &&
	test_cmp expect-multiline output
'
test_expect_success 'create -m and -F notes (setup)' '
	: > a4 &&
	git add a4 &&
	test_tick &&
	git commit -m 4th &&
	echo "xyzzy" > note5 &&
	git notes edit -m spam -F note5 -m "foo
bar
baz"
'

whitespace="    "
cat > expect-m-and-F << EOF
commit 15023535574ded8b1a89052b32673f84cf9582b8
Author: A U Thor <author@example.com>
Date:   Thu Apr 7 15:16:13 2005 -0700

    4th

Notes:
    spam
$whitespace
    xyzzy
$whitespace
    foo
    bar
    baz
EOF

printf "\n" >> expect-m-and-F
cat expect-multiline >> expect-m-and-F

test_expect_success 'show -m and -F notes' '
	git log -3 > output &&
	test_cmp expect-m-and-F output
'

test_done