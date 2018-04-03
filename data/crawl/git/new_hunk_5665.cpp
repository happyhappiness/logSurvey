test_debug 'cat gitweb.output'


# ----------------------------------------------------------------------
# snapshot hash ids

test_expect_success 'snapshots: good tree-ish id' '
	gitweb_run "p=.git;a=snapshot;h=master;sf=tgz" &&
	grep "Status: 200 OK" gitweb.output
'
test_debug 'cat gitweb.output'

test_expect_success 'snapshots: bad tree-ish id' '
	gitweb_run "p=.git;a=snapshot;h=frizzumFrazzum;sf=tgz" &&
	grep "404 - Object does not exist" gitweb.output
'
test_debug 'cat gitweb.output'

test_expect_success 'snapshots: bad tree-ish id (tagged object)' '
	echo object > tag-object &&
	git add tag-object &&
	git commit -m "Object to be tagged" &&
	git tag tagged-object `git hash-object tag-object` &&
	gitweb_run "p=.git;a=snapshot;h=tagged-object;sf=tgz" &&
	grep "400 - Object is not a tree-ish" gitweb.output
'
test_debug 'cat gitweb.output'

test_expect_success 'snapshots: good object id' '
	ID=`git rev-parse --verify HEAD` &&
	gitweb_run "p=.git;a=snapshot;h=$ID;sf=tgz" &&
	grep "Status: 200 OK" gitweb.output
'
test_debug 'cat gitweb.output'

test_expect_success 'snapshots: bad object id' '
	gitweb_run "p=.git;a=snapshot;h=abcdef01234;sf=tgz" &&
	grep "404 - Object does not exist" gitweb.output
'
test_debug 'cat gitweb.output'


test_done