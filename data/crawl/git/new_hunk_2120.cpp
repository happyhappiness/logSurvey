   branch we locally checked out).
   (merge 95c38fb jk/branch-shortening-funny-symrefs later to maint).

 * A partial rewrite of "git submodule" in the 2.7 timeframe changed
   the way the gitdir: pointer in the submodules point at the real
   repository location to use absolute paths by accident.  This has
   been corrected.
   (merge 1f15ba1 sb/submodule-helper-clone-regression-fix later to maint).

 * "git commit" misbehaved in a few minor ways when an empty message
   is given via -m '', all of which has been corrected.
   (merge 27014cb ad/commit-have-m-option later to maint).

 * Support for CRAM-MD5 authentication method in "git imap-send" did
   not work well.
   (merge eb94ee7 ky/imap-send later to maint).

 * Upcoming OpenSSL 1.1.0 will break compilation b updating a few APIs
   we use in imap-send, which has been adjusted for the change.
   (merge 1245c74 ky/imap-send-openssl-1.1.0 later to maint).

 * The socks5:// proxy support added back in 2.6.4 days was not aware
   that socks5h:// proxies behave differently.
   (merge 87f8a0b jc/http-socks5h later to maint).

 * "git config" had a codepath that tried to pass a NULL to
   printf("%s"), which nobody seems to have noticed.
   (merge 1cae428 jk/do-not-printf-NULL later to maint).

 * On Cygwin, object creation uses the "create a temporary and then
   rename it to the final name" pattern, not "create a temporary,
   hardlink it to the final name and then unlink the temporary"
   pattern.

   This is necessary to use Git on Windows shared directories, and is
   already enabled for the MinGW and plain Windows builds.  It also
   has been used in Cygwin packaged versions of Git for quite a while.
   See http://thread.gmane.org/gmane.comp.version-control.git/291853
   (merge e53a64b ad/cygwin-wants-rename later to maint).

 * Other minor clean-ups and documentation updates
   (merge aed7480 mm/lockfile-error-message later to maint).
   (merge bfee614 jc/index-pack later to maint).
