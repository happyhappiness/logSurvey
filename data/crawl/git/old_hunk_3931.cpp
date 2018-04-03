   streaming a zip archive, which confused some implementations of unzip.
   (merge 5ea2c84 rs/zip-with-uncompressed-size-in-the-header later to maint).

 * When "git clone --separate-git-dir=$over_there" is interrupted, it
   failed to remove the real location of the $GIT_DIR it created.
   This was most visible when interrupting a submodule update.
