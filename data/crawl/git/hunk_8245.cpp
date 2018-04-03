 e*
 EOF
 
-git-config core.excludesFile excludes-file
+git config core.excludesFile excludes-file
 
-git-runstatus | grep "^#	" > output
+git runstatus | grep "^#	" > output
 
 cat > expect << EOF
 #	.gitignore
