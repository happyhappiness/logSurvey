	git fast-import >fast-import-output
====

A frontend set up this way can use `progress`, `get-mark`, `ls`, and
`cat-blob` commands to read information from the import in progress.

To avoid deadlock, such frontends must completely consume any
pending output from `progress`, `ls`, `get-mark`, and `cat-blob` before
performing writes to fast-import that might block.

Crash Reports
