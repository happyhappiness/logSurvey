	test_must_fail git notes show HEAD^
'

cat >expect <<EOF
d423f8c refs/notes/commits@{0}: notes: Notes added by 'git notes add'
EOF