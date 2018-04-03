	grep "file => foo .* 0 *$" 0000-cover-letter.patch

'

cat > expect << EOF
  This is an excessively long subject line for a message due to the
    habit some projects have of not having a short, one-line subject at
    the start of the commit message, but rather sticking a whole
    paragraph right at the start as the only thing in the commit
    message. It had better not become the filename for the patch.
  foo

EOF

test_expect_success 'shortlog of cover-letter wraps overly-long onelines' '

	git format-patch --cover-letter -2 &&
	sed -e "1,/A U Thor/d" -e "/^$/q" < 0000-cover-letter.patch > output &&
	git diff expect output

'

test_done