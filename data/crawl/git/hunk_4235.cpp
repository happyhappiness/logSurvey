 
 NAME
 ----
-git-shortlog - Summarize 'git-log' output
+git-shortlog - Summarize 'git log' output
 
 SYNOPSIS
 --------
 [verse]
 git log --pretty=short | 'git shortlog' [-h] [-n] [-s] [-e] [-w]
-git shortlog [-n|--numbered] [-s|--summary] [-e|--email] [-w[<width>[,<indent1>[,<indent2>]]]] [<committish>...]
+'git shortlog' [-n|--numbered] [-s|--summary] [-e|--email] [-w[<width>[,<indent1>[,<indent2>]]]] [<committish>...]
 
 DESCRIPTION
 -----------
-Summarizes 'git-log' output in a format suitable for inclusion
+Summarizes 'git log' output in a format suitable for inclusion
 in release announcements. Each commit will be grouped by author and
 the first line of the commit message will be shown.
 
