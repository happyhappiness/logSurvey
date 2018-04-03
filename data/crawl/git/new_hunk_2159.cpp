	cp .git/refs/heads/master .git/refs/heads/broken...ref &&
	test_when_finished "rm -f .git/refs/heads/broken...ref" &&
	git branch >output 2>error &&
	test_i18ngrep -e "ignoring ref with broken name refs/heads/broken\.\.\.ref" error &&
	! grep -e "broken\.\.\.ref" output
'

