
	git config status.relativePaths false
	(cd dir1 && git status) > output &&
	git diff expect output

'

