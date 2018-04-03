	test_cmp expect-m-and-F output
'

cat >expect << EOF
commit 15023535574ded8b1a89052b32673f84cf9582b8
tree e070e3af51011e47b183c33adf9736736a525709
parent 1584215f1d29c65e99c6c6848626553fdd07fd75
author A U Thor <author@example.com> 1112912173 -0700
committer C O Mitter <committer@example.com> 1112912173 -0700

    4th
EOF
test_expect_success 'git log --pretty=raw does not show notes' '
	git log -1 --pretty=raw >output &&
	test_cmp expect output
'

cat >>expect <<EOF

Notes:
    spam
$whitespace
    xyzzy
$whitespace
    foo
    bar
    baz
EOF
test_expect_success 'git log --show-notes' '
	git log -1 --pretty=raw --show-notes >output &&
	test_cmp expect output
'

test_expect_success 'git log --no-notes' '
	git log -1 --no-notes >output &&
	! grep spam output
'

test_expect_success 'git format-patch does not show notes' '
	git format-patch -1 --stdout >output &&
	! grep spam output
'

test_expect_success 'git format-patch --show-notes does show notes' '
	git format-patch --show-notes -1 --stdout >output &&
	grep spam output
'

for pretty in "" raw short medium full fuller format:%s
do
	case "$pretty" in
	"") p= not= negate="" ;;
	?*) p="--pretty=$pretty" not=" not" negate="!" ;;
	esac
	test_expect_success "git show $pretty does$not show notes" '
		git show $p >output &&
		eval "$negate grep spam output"
	'
done

test_done