Updates since v1.7.0
--------------------

 * Eric Raymond is the maintainer of updated CIAbot scripts, in contrib/.

 * Some commands (e.g. svn and http interfaces) that interactively ask
   password can be told to use an external program given via GIT_ASKPASS.

 * Conflict markers that lead the common ancestor in diff3-style output
   now has a label, which hopefully would help third-party tools that
   expect one.

 * Comes with an updated bash-completion script.

 * "git am" learned "--keep-cr" option to handle inputs that are
   mixture of changes to files with and without CRLF line endings.

