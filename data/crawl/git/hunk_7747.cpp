 
 git config core.excludesFile excludes-file
 
-git runstatus | grep "^#	" > output
+git status | grep "^#	" > output
 
 cat > expect << EOF
 #	.gitignore
