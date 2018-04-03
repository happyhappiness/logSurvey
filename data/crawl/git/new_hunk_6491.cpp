	test_cmp expect actual
'

# Extended mailmap configurations should give us the following output for shortlog
cat >expect <<\EOF
A U Thor <author@example.com> (1):
      initial

CTO <cto@company.xx> (1):
      seventh

Other Author <other@author.xx> (2):
      third
      fourth

Santa Claus <santa.claus@northpole.xx> (2):
      fifth
      sixth

Some Dude <some@dude.xx> (1):
      second

EOF

test_expect_success 'Shortlog output (complex mapping)' '
	echo three >>one &&
	git add one &&
	test_tick &&
	git commit --author "nick2 <bugs@company.xx>" -m third &&

	echo four >>one &&
	git add one &&
	test_tick &&
	git commit --author "nick2 <nick2@company.xx>" -m fourth &&

	echo five >>one &&
	git add one &&
	test_tick &&
	git commit --author "santa <me@company.xx>" -m fifth &&

	echo six >>one &&
	git add one &&
	test_tick &&
	git commit --author "claus <me@company.xx>" -m sixth &&

	echo seven >>one &&
	git add one &&
	test_tick &&
	git commit --author "CTO <cto@coompany.xx>" -m seventh &&

	mkdir internal_mailmap &&
	echo "Committed <committer@example.com>" > internal_mailmap/.mailmap &&
	echo "<cto@company.xx>                       <cto@coompany.xx>" >> internal_mailmap/.mailmap &&
	echo "Some Dude <some@dude.xx>         nick1 <bugs@company.xx>" >> internal_mailmap/.mailmap &&
	echo "Other Author <other@author.xx>   nick2 <bugs@company.xx>" >> internal_mailmap/.mailmap &&
	echo "Other Author <other@author.xx>         <nick2@company.xx>" >> internal_mailmap/.mailmap &&
	echo "Santa Claus <santa.claus@northpole.xx> <me@company.xx>" >> internal_mailmap/.mailmap &&
	echo "Santa Claus <santa.claus@northpole.xx> <me@company.xx>" >> internal_mailmap/.mailmap &&

	git shortlog -e HEAD >actual &&
	test_cmp expect actual

'

# git log with --pretty format which uses the name and email mailmap placemarkers
cat >expect <<\EOF
Author CTO <cto@coompany.xx> maps to CTO <cto@company.xx>
Committer C O Mitter <committer@example.com> maps to Committed <committer@example.com>

Author claus <me@company.xx> maps to Santa Claus <santa.claus@northpole.xx>
Committer C O Mitter <committer@example.com> maps to Committed <committer@example.com>

Author santa <me@company.xx> maps to Santa Claus <santa.claus@northpole.xx>
Committer C O Mitter <committer@example.com> maps to Committed <committer@example.com>

Author nick2 <nick2@company.xx> maps to Other Author <other@author.xx>
Committer C O Mitter <committer@example.com> maps to Committed <committer@example.com>

Author nick2 <bugs@company.xx> maps to Other Author <other@author.xx>
Committer C O Mitter <committer@example.com> maps to Committed <committer@example.com>

Author nick1 <bugs@company.xx> maps to Some Dude <some@dude.xx>
Committer C O Mitter <committer@example.com> maps to Committed <committer@example.com>

Author A U Thor <author@example.com> maps to A U Thor <author@example.com>
Committer C O Mitter <committer@example.com> maps to Committed <committer@example.com>
EOF

test_expect_success 'Log output (complex mapping)' '
	git log --pretty=format:"Author %an <%ae> maps to %aN <%aE>%nCommitter %cn <%ce> maps to %cN <%cE>%n" >actual &&
	test_cmp expect actual
'

# git blame
cat >expect <<\EOF
^3a2fdcb (A U Thor     2005-04-07 15:13:13 -0700 1) one
7de6f99b (Some Dude    2005-04-07 15:13:13 -0700 2) two
5815879d (Other Author 2005-04-07 15:14:13 -0700 3) three
ff859d96 (Other Author 2005-04-07 15:15:13 -0700 4) four
5ab6d4fa (Santa Claus  2005-04-07 15:16:13 -0700 5) five
38a42d8b (Santa Claus  2005-04-07 15:17:13 -0700 6) six
8ddc0386 (CTO          2005-04-07 15:18:13 -0700 7) seven
EOF

test_expect_success 'Blame output (complex mapping)' '
	git blame one >actual &&
	test_cmp expect actual
'

test_done