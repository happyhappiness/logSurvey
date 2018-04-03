   will never come.  Teach the client side to notice this condition
   and abort the transfer.

 * Some platforms no longer understand "latin-1" that is still seen in
   the wild in e-mail headers; replace them with "iso-8859-1" that is
   more widely known when conversion fails from/to it.

 * Update the procedure to generate "tags" for developer support.

 * Update the definition of the MacOSX test environment used by
   TravisCI.

 * A few git-svn updates.

 * Compression setting for producing packfiles were spread across
   three codepaths, one of which did not honor any configuration.
   Unify these so that all of them honor core.compression and
   pack.compression variables the same way.

 * "git fast-import" sometimes mishandled while rebalancing notes
   tree, which has been fixed.

 * Recent update to the default abbreviation length that auto-scales
   lacked documentation update, which has been corrected.

 * Leakage of lockfiles in the config subsystem has been fixed.

 * It is natural that "git gc --auto" may not attempt to pack
   everything into a single pack, and there is no point in warning
   when the user has configured the system to use the pack bitmap,
   leading to disabling further "gc".

 * "git archive" did not read the standard configuration files, and
   failed to notice a file that is marked as binary via the userdiff
   driver configuration.

 * "git blame --porcelain" misidentified the "previous" <commit, path>
   pair (aka "source") when contents came from two or more files.

 * "git rebase -i" with a recent update started showing an incorrect
   count when squashing more than 10 commits.

 * "git <cmd> @{push}" on a detached HEAD used to segfault; it has
   been corrected to error out with a message.

 * Tighten a test to avoid mistaking an extended ERE regexp engine as
   a PRE regexp engine.


Also contains various documentation updates and code clean-ups.