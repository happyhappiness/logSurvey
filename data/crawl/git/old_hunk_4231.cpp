  This is added AA in the branch B.
  fatal: merge program failed

where the latter example shows how 'git-merge-index' will stop trying to
merge once anything has returned an error (i.e., `cat` returned an error
for the AA file, because it didn't exist in the original, and thus
'git-merge-index' didn't even try to merge the MM thing).

Author
------
