'set';;		when the attribute is defined as true.
<value>;;	when a value has been assigned to the attribute.

Buffering happens as documented under the `GIT_FLUSH` option in
linkgit:git[1].  The caller is responsible for avoiding deadlocks
caused by overfilling an input buffer or reading from an empty output
buffer.

EXAMPLES
--------

