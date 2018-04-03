		cp .git/refs/heads/master .git/refs/heads/broken...ref
	) &&
	git -C src push --mirror "file://$top/dest" &&
	git -C dest branch >output &&
	! grep -e "broken\.\.\.ref" output
'

