
git config core.excludesFile excludes-file

git status | grep "^#	" > output

cat > expect << EOF
#	.gitignore
