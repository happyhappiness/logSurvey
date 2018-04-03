	  "die q(badrename) if ((stat(q(.git/config)))[2] & 07777) != 0600"
'

test_expect_success 'set up --show-origin tests' '
	INCLUDE_DIR="$HOME/include" &&
	mkdir -p "$INCLUDE_DIR" &&
	cat >"$INCLUDE_DIR"/absolute.include <<-\EOF &&
		[user]
			absolute = include
	EOF
	cat >"$INCLUDE_DIR"/relative.include <<-\EOF &&
		[user]
			relative = include
	EOF
	cat >"$HOME"/.gitconfig <<-EOF &&
		[user]
			global = true
			override = global
		[include]
			path = "$INCLUDE_DIR/absolute.include"
	EOF
	cat >.git/config <<-\EOF
		[user]
			local = true
			override = local
		[include]
			path = ../include/relative.include
	EOF
'

test_expect_success '--show-origin with --list' '
	cat >expect <<-EOF &&
		file:$HOME/.gitconfig	user.global=true
		file:$HOME/.gitconfig	user.override=global
		file:$HOME/.gitconfig	include.path=$INCLUDE_DIR/absolute.include
		file:$INCLUDE_DIR/absolute.include	user.absolute=include
		file:.git/config	user.local=true
		file:.git/config	user.override=local
		file:.git/config	include.path=../include/relative.include
		file:.git/../include/relative.include	user.relative=include
		command line:	user.cmdline=true
	EOF
	git -c user.cmdline=true config --list --show-origin >output &&
	test_cmp expect output
'

test_expect_success '--show-origin with --list --null' '
	cat >expect <<-EOF &&
		file:$HOME/.gitconfigQuser.global
		trueQfile:$HOME/.gitconfigQuser.override
		globalQfile:$HOME/.gitconfigQinclude.path
		$INCLUDE_DIR/absolute.includeQfile:$INCLUDE_DIR/absolute.includeQuser.absolute
		includeQfile:.git/configQuser.local
		trueQfile:.git/configQuser.override
		localQfile:.git/configQinclude.path
		../include/relative.includeQfile:.git/../include/relative.includeQuser.relative
		includeQcommand line:Quser.cmdline
		trueQ
	EOF
	git -c user.cmdline=true config --null --list --show-origin >output.raw &&
	nul_to_q <output.raw >output &&
	# The here-doc above adds a newline that the --null output would not
	# include. Add it here to make the two comparable.
	echo >>output &&
	test_cmp expect output
'

test_expect_success '--show-origin with single file' '
	cat >expect <<-\EOF &&
		file:.git/config	user.local=true
		file:.git/config	user.override=local
		file:.git/config	include.path=../include/relative.include
	EOF
	git config --local --list --show-origin >output &&
	test_cmp expect output
'

test_expect_success '--show-origin with --get-regexp' '
	cat >expect <<-EOF &&
		file:$HOME/.gitconfig	user.global true
		file:.git/config	user.local true
	EOF
	git config --show-origin --get-regexp "user\.[g|l].*" >output &&
	test_cmp expect output
'

test_expect_success '--show-origin getting a single key' '
	cat >expect <<-\EOF &&
		file:.git/config	local
	EOF
	git config --show-origin user.override >output &&
	test_cmp expect output
'

test_expect_success 'set up custom config file' '
	CUSTOM_CONFIG_FILE="file\" (dq) and spaces.conf" &&
	cat >"$CUSTOM_CONFIG_FILE" <<-\EOF
		[user]
			custom = true
	EOF
'

test_expect_success '--show-origin escape special file name characters' '
	cat >expect <<-\EOF &&
		file:"file\" (dq) and spaces.conf"	user.custom=true
	EOF
	git config --file "$CUSTOM_CONFIG_FILE" --show-origin --list >output &&
	test_cmp expect output
'

test_expect_success '--show-origin stdin' '
	cat >expect <<-\EOF &&
		standard input:	user.custom=true
	EOF
	git config --file - --show-origin --list <"$CUSTOM_CONFIG_FILE" >output &&
	test_cmp expect output
'

test_expect_success '--show-origin stdin with file include' '
	cat >"$INCLUDE_DIR"/stdin.include <<-EOF &&
		[user]
			stdin = include
	EOF
	cat >expect <<-EOF &&
		file:$INCLUDE_DIR/stdin.include	include
	EOF
	echo "[include]path=\"$INCLUDE_DIR\"/stdin.include" \
		| git config --show-origin --includes --file - user.stdin >output &&
	test_cmp expect output
'

test_expect_success '--show-origin blob' '
	cat >expect <<-\EOF &&
		blob:a9d9f9e555b5c6f07cbe09d3f06fe3df11e09c08	user.custom=true
	EOF
	blob=$(git hash-object -w "$CUSTOM_CONFIG_FILE") &&
	git config --blob=$blob --show-origin --list >output &&
	test_cmp expect output
'

test_expect_success '--show-origin blob ref' '
	cat >expect <<-\EOF &&
		blob:"master:file\" (dq) and spaces.conf"	user.custom=true
	EOF
	git add "$CUSTOM_CONFIG_FILE" &&
	git commit -m "new config file" &&
	git config --blob=master:"$CUSTOM_CONFIG_FILE" --show-origin --list >output &&
	test_cmp expect output
'

test_done