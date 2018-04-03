
   The above except the "replacement" are all done with:

     $ git checkout ai/topic ;# or "git checkout -b ai/topic master"
     $ git am -sc3 mailbox

   while patch replacement is often done by:

     $ git format-patch ai/topic~$n..ai/topic ;# export existing

   then replace some parts with the new patch, and reapplying:

     $ git checkout ai/topic
     $ git reset --hard ai/topic~$n
     $ git am -sc3 -s 000*.txt

   The full test suite is always run for 'maint' and 'master'
   after patch application; for topic branches the tests are run
   as time permits.

 - Merge maint to master as needed:

     $ git checkout master
     $ git merge maint
     $ make test

 - Merge master to next as needed:

     $ git checkout next
     $ git merge master
     $ make test

 - Review the last issue of "What's cooking" again and see if topics
   that are ready to be merged to 'next' are still in good shape
   (e.g. has there any new issue identified on the list with the
   series?)

 - Prepare 'jch' branch, which is used to represent somewhere
   between 'master' and 'pu' and often is slightly ahead of 'next'.

     $ Meta/Reintegrate master..pu >Meta/redo-jch.sh

   The result is a script that lists topics to be merged in order to
   rebuild 'pu' as the input to Meta/Reintegrate script.  Remove
   later topics that should not be in 'jch' yet.  Add a line that
   consists of '###' before the name of the first topic in the output
   that should be in 'jch' but not in 'next' yet.

 - Now we are ready to start merging topics to 'next'.  For each
   branch whose tip is not merged to 'next', one of three things can
   happen:

   - The commits are all next-worthy; merge the topic to next;
   - The new parts are of mixed quality, but earlier ones are
     next-worthy; merge the early parts to next;
   - Nothing is next-worthy; do not do anything.

   This step is aided with Meta/redo-jch.sh script created earlier.
   If a topic that was already in 'next' gained a patch, the script
   would list it as "ai/topic~1".  To include the new patch to the
   updated 'next', drop the "~1" part; to keep it excluded, do not
   touch the line.  If a topic that was not in 'next' should be
   merged to 'next', add it at the end of the list.  Then:

     $ git checkout -B jch master
     $ Meta/redo-jch.sh -c1

   to rebuild the 'jch' branch from scratch.  "-c1" tells the script
   to stop merging at the '###' line you added earlier.

   At this point, build-test the result.  It may reveal semantic
   conflicts (e.g. a topic renamed a variable, another added a new
   reference to the variable under its old name), in which case
   prepare an appropriate merge-fix first (see appendix), and
   rebuild the 'jch' branch from scratch, starting at the tip of
   'master'.

   Then do the same to 'next'

     $ git checkout next
     $ sh Meta/redo-jch.sh -c1 -e

   The "-e" option allows the merge message that comes from the
   history of the topic and the comments in the "What's cooking" to
   be edited.  The resulting tree should match 'jch' as the same set
   of topics are merged on 'master'; otherwise there is a mismerge.
   Investigate why and do not proceed until the mismerge is found
   and rectified.

     $ git diff jch next

   When all is well, clean up the redo-jch.sh script with

     $ sh Meta/redo-jch.sh -u

   This removes topics listed in the script that have already been
   merged to 'master'.  This unfortunately loses the "###" marker,
   so add it again to the appropriate place.

 - Rebuild 'pu'.

     $ Meta/Reintegrate master..pu >Meta/redo-pu.sh

   Edit the result by adding new topics that are not still in 'pu'
   in the script.  Then

     $ git checkout -B pu jch
     $ sh Meta/redo-pu.sh

   When all is well, clean up the redo-pu.sh script with

     $ sh Meta/redo-pu.sh -u

   Double check by running

     $ git branch --no-merged pu

   to see there is no unexpected leftover topics.

   At this point, build-test the result for semantic conflicts, and
   if there are, prepare an appropriate merge-fix first (see
   appendix), and rebuild the 'pu' branch from scratch, starting at
   the tip of 'jch'.

 - Update "What's cooking" message to review the updates to
   existing topics, newly added topics and graduated topics.

   This step is helped with Meta/cook script.

     $ Meta/cook

   This script inspects the history between master..pu, finds tips
   of topic branches, compares what it found with the current
   contents in Meta/whats-cooking.txt, and updates that file.
   Topics not listed in the file but are found in master..pu are
   added to the "New topics" section, topics listed in the file that
   are no longer found in master..pu are moved to the "Graduated to
   master" section, and topics whose commits changed their states
   (e.g. used to be only in 'pu', now merged to 'next') are updated
   with change markers "<<" and ">>".

   Look for lines enclosed in "<<" and ">>"; they hold contents from
   old file that are replaced by this integration round.  After
   verifying them, remove the old part.  Review the description for
   each topic and update its doneness and plan as needed.  To review
   the updated plan, run

     $ Meta/cook -w

   which will pick up comments given to the topics, such as "Will
   merge to 'next'", etc. (see Meta/cook script to learn what kind
   of phrases are supported).

 - Compile, test and install all four (five) integration branches;
   Meta/Dothem script may aid this step.

 - Format documentation if the 'master' branch was updated;
   Meta/dodoc.sh script may aid this step.

 - Push the integration branches out to public places; Meta/pushall
   script may aid this step.

Some observations to be made.

 * Each topic is tested individually, and also together with other
   topics cooking first in 'pu', then in 'jch' and then in 'next'.
   Until it matures, no part of it is merged to 'master'.

 * A topic already in 'next' can get fixes while still in
   'next'.  Such a topic will have many merges to 'next' (in
   other words, "git log --first-parent next" will show many
   "Merge branch 'ai/topic' to next" for the same topic.

 * An unobvious fix for 'maint' is cooked in 'next' and then
   merged to 'master' to make extra sure it is Ok and then
