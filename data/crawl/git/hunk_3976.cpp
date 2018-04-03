 
    The above except the "replacement" are all done with:
 
-     $ git am -3 -s mailbox
+     $ git checkout ai/topic ;# or "git checkout -b ai/topic master"
+     $ git am -sc3 mailbox
 
    while patch replacement is often done by:
 
      $ git format-patch ai/topic~$n..ai/topic ;# export existing
 
    then replace some parts with the new patch, and reapplying:
 
+     $ git checkout ai/topic
      $ git reset --hard ai/topic~$n
-     $ git am -3 -s 000*.txt
+     $ git am -sc3 -s 000*.txt
 
    The full test suite is always run for 'maint' and 'master'
    after patch application; for topic branches the tests are run
    as time permits.
 
- - Update "What's cooking" message to review the updates to
-   existing topics, newly added topics and graduated topics.
+ - Merge maint to master as needed:
 
-   This step is helped with Meta/cook script (where Meta/ contains
-   a checkout of the 'todo' branch).
-
- - Merge topics to 'next'.  For each branch whose tip is not
-   merged to 'next', one of three things can happen:
+     $ git checkout master
+     $ git merge maint
+     $ make test
 
-   - The commits are all next-worthy; merge the topic to next:
+ - Merge master to next as needed:
 
      $ git checkout next
-     $ git merge ai/topic     ;# or "git merge ai/maint-topic"
+     $ git merge master
      $ make test
 
+ - Review the last issue of "What's cooking" again and see if topics
+   that are ready to be merged to 'next' are still in good shape
+   (e.g. has there any new issue identified on the list with the
+   series?)
+
+ - Prepare 'jch' branch, which is used to represent somewhere
+   between 'master' and 'pu' and often is slightly ahead of 'next'.
+
+     $ Meta/Reintegrate master..pu >Meta/redo-jch.sh
+
+   The result is a script that lists topics to be merged in order to
+   rebuild 'pu' as the input to Meta/Reintegrate script.  Remove
+   later topics that should not be in 'jch' yet.  Add a line that
+   consists of '###' before the name of the first topic in the output
+   that should be in 'jch' but not in 'next' yet.
+
+ - Now we are ready to start merging topics to 'next'.  For each
+   branch whose tip is not merged to 'next', one of three things can
+   happen:
+
+   - The commits are all next-worthy; merge the topic to next;
    - The new parts are of mixed quality, but earlier ones are
-     next-worthy; merge the early parts to next:
+     next-worthy; merge the early parts to next;
+   - Nothing is next-worthy; do not do anything.
+
+   This step is aided with Meta/redo-jch.sh script created earlier.
+   If a topic that was already in 'next' gained a patch, the script
+   would list it as "ai/topic~1".  To include the new patch to the
+   updated 'next', drop the "~1" part; to keep it excluded, do not
+   touch the line.  If a topic that was not in 'next' should be
+   merged to 'next', add it at the end of the list.  Then:
+
+     $ git checkout -B jch master
+     $ Meta/redo-jch.sh -c1
+
+   to rebuild the 'jch' branch from scratch.  "-c1" tells the script
+   to stop merging at the '###' line you added earlier.
+
+   At this point, build-test the result.  It may reveal semantic
+   conflicts (e.g. a topic renamed a variable, another added a new
+   reference to the variable under its old name), in which case
+   prepare an appropriate merge-fix first (see appendix), and
+   rebuild the 'jch' branch from scratch, starting at the tip of
+   'master'.
+
+   Then do the same to 'next'
 
      $ git checkout next
-     $ git merge ai/topic~2   ;# the tip two are dubious
-     $ make test
+     $ sh Meta/redo-jch.sh -c1 -e
 
-   - Nothing is next-worthy; do not do anything.
+   The "-e" option allows the merge message that comes from the
+   history of the topic and the comments in the "What's cooking" to
+   be edited.  The resulting tree should match 'jch' as the same set
+   of topics are merged on 'master'; otherwise there is a mismerge.
+   Investigate why and do not proceed until the mismerge is found
+   and rectified.
 
- - [** OBSOLETE **] Optionally rebase topics that do not have any commit
-   in next yet, when they can take advantage of low-level framework
-   change that is merged to 'master' already.
+     $ git diff jch next
 
-     $ git rebase master ai/topic
+   When all is well, clean up the redo-jch.sh script with
 
-   This step is helped with Meta/git-topic.perl script to
-   identify which topic is rebaseable.  There also is a
-   pre-rebase hook to make sure that topics that are already in
-   'next' are not rebased beyond the merged commit.
+     $ sh Meta/redo-jch.sh -u
 
- - [** OBSOLETE **] Rebuild "pu" to merge the tips of topics not in 'next'.
+   This removes topics listed in the script that have already been
+   merged to 'master'.  This unfortunately loses the "###" marker,
+   so add it again to the appropriate place.
 
-     $ git checkout pu
-     $ git reset --hard next
-     $ git merge ai/topic     ;# repeat for all remaining topics
-     $ make test
+ - Rebuild 'pu'.
+
+     $ Meta/Reintegrate master..pu >Meta/redo-pu.sh
+
+   Edit the result by adding new topics that are not still in 'pu'
+   in the script.  Then
+
+     $ git checkout -B pu jch
+     $ sh Meta/redo-pu.sh
+
+   When all is well, clean up the redo-pu.sh script with
 
-   This step is helped with Meta/PU script
+     $ sh Meta/redo-pu.sh -u
 
- - Push four integration branches to a private repository at
-   k.org and run "make test" on all of them.
+   Double check by running
 
- - Push four integration branches to /pub/scm/git/git.git at
-   k.org.  This triggers its post-update hook which:
+     $ git branch --no-merged pu
 
-    (1) runs "git pull" in $HOME/git-doc/ repository to pull
-        'master' just pushed out;
+   to see there is no unexpected leftover topics.
 
-    (2) runs "make doc" in $HOME/git-doc/, install the generated
-        documentation in staging areas, which are separate
-        repositories that have html and man branches checked
-        out.
+   At this point, build-test the result for semantic conflicts, and
+   if there are, prepare an appropriate merge-fix first (see
+   appendix), and rebuild the 'pu' branch from scratch, starting at
+   the tip of 'jch'.
 
-    (3) runs "git commit" in the staging areas, and run "git
-        push" back to /pub/scm/git/git.git/ to update the html
-        and man branches.
+ - Update "What's cooking" message to review the updates to
+   existing topics, newly added topics and graduated topics.
+
+   This step is helped with Meta/cook script.
+
+     $ Meta/cook
+
+   This script inspects the history between master..pu, finds tips
+   of topic branches, compares what it found with the current
+   contents in Meta/whats-cooking.txt, and updates that file.
+   Topics not listed in the file but are found in master..pu are
+   added to the "New topics" section, topics listed in the file that
+   are no longer found in master..pu are moved to the "Graduated to
+   master" section, and topics whose commits changed their states
+   (e.g. used to be only in 'pu', now merged to 'next') are updated
+   with change markers "<<" and ">>".
 
-    (4) installs generated documentation to /pub/software/scm/git/docs/
-        to be viewed from http://www.kernel.org/
+   Look for lines enclosed in "<<" and ">>"; they hold contents from
+   old file that are replaced by this integration round.  After
+   verifying them, remove the old part.  Review the description for
+   each topic and update its doneness and plan as needed.  To review
+   the updated plan, run
 
- - Fetch html and man branches back from k.org, and push four
-   integration branches and the two documentation branches to
-   repo.or.cz and other mirrors.
+     $ Meta/cook -w
 
+   which will pick up comments given to the topics, such as "Will
+   merge to 'next'", etc. (see Meta/cook script to learn what kind
+   of phrases are supported).
+
+ - Compile, test and install all four (five) integration branches;
+   Meta/Dothem script may aid this step.
+
+ - Format documentation if the 'master' branch was updated;
+   Meta/dodoc.sh script may aid this step.
+
+ - Push the integration branches out to public places; Meta/pushall
+   script may aid this step.
 
 Some observations to be made.
 
- * Each topic is tested individually, and also together with
-   other topics cooking in 'next'.  Until it matures, none part
-   of it is merged to 'master'.
+ * Each topic is tested individually, and also together with other
+   topics cooking first in 'pu', then in 'jch' and then in 'next'.
+   Until it matures, no part of it is merged to 'master'.
 
  * A topic already in 'next' can get fixes while still in
    'next'.  Such a topic will have many merges to 'next' (in
    other words, "git log --first-parent next" will show many
-   "Merge ai/topic to next" for the same topic.
+   "Merge branch 'ai/topic' to next" for the same topic.
 
  * An unobvious fix for 'maint' is cooked in 'next' and then
    merged to 'master' to make extra sure it is Ok and then
