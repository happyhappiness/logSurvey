Fixes since v1.8.1
------------------

 * After failing to create a temporary file using mkstemp(), failing
   pathname was not reported correctly on some platforms.

 * http transport was wrong to ask for the username when the
   authentication is done by certificate identity.

 * After "git add -N" and then writing a tree object out of the
   index, the cache-tree data structure got corrupted.

 * "git pack-refs" that ran in parallel to another process that
   created new refs had a race that can lose new ones.

 * When a line to be wrapped has a solid run of non space characters
   whose length exactly is the wrap width, "git shortlog -w" failed
   to add a newline after such a line.

 * "gitweb", when sorting by age to show repositories with new
   activities first, used to sort repositories with absolutely
   nothing in it early, which was not very useful.

 * Some scripted programs written in Python did not get updated when
   PYTHON_PATH changed.

