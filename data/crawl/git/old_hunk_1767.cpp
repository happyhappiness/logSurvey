	Skip move or rename actions which would lead to an error
	condition. An error happens when a source is neither existing nor
	controlled by Git, or when it would overwrite an existing
	file unless '-f' is given.
-n::
--dry-run::
	Do nothing; only show what would happen
