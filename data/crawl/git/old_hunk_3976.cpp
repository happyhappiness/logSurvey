
   The above except the "replacement" are all done with:

     $ git am -3 -s mailbox

   while patch replacement is often done by:

     $ git format-patch ai/topic~$n..ai/topic ;# export existing

   then replace some parts with the new patch, and reapplying:

     $ git reset --hard ai/topic~$n
     $ git am -3 -s 000*.txt

   The full test suite is always run for 'maint' and 'master'
   after patch application; for topic branches the tests are run
   as time permits.

 - Update "What's cooking" message to review the updates to
   existing topics, newly added topics and graduated topics.

   This step is helped with Meta/cook script (where Meta/ contains
   a checkout of the 'todo' branch).

 - Merge topics to 'next'.  For each branch whose tip is not
   merged to 'next', one of three things can happen:

   - The commits are all next-worthy; merge the topic to next:

     $ git checkout next
     $ git merge ai/topic     ;# or "git merge ai/maint-topic"
     $ make test

   - The new parts are of mixed quality, but earlier ones are
     next-worthy; merge the early parts to next:

     $ git checkout next
     $ git merge ai/topic~2   ;# the tip two are dubious
     $ make test

   - Nothing is next-worthy; do not do anything.

 - [** OBSOLETE **] Optionally rebase topics that do not have any commit
   in next yet, when they can take advantage of low-level framework
   change that is merged to 'master' already.

     $ git rebase master ai/topic

   This step is helped with Meta/git-topic.perl script to
   identify which topic is rebaseable.  There also is a
   pre-rebase hook to make sure that topics that are already in
   'next' are not rebased beyond the merged commit.

 - [** OBSOLETE **] Rebuild "pu" to merge the tips of topics not in 'next'.

     $ git checkout pu
     $ git reset --hard next
     $ git merge ai/topic     ;# repeat for all remaining topics
     $ make test

   This step is helped with Meta/PU script

 - Push four integration branches to a private repository at
   k.org and run "make test" on all of them.

 - Push four integration branches to /pub/scm/git/git.git at
   k.org.  This triggers its post-update hook which:

    (1) runs "git pull" in $HOME/git-doc/ repository to pull
        'master' just pushed out;

    (2) runs "make doc" in $HOME/git-doc/, install the generated
        documentation in staging areas, which are separate
        repositories that have html and man branches checked
        out.

    (3) runs "git commit" in the staging areas, and run "git
        push" back to /pub/scm/git/git.git/ to update the html
        and man branches.

    (4) installs generated documentation to /pub/software/scm/git/docs/
        to be viewed from http://www.kernel.org/

 - Fetch html and man branches back from k.org, and push four
   integration branches and the two documentation branches to
   repo.or.cz and other mirrors.


Some observations to be made.

 * Each topic is tested individually, and also together with
   other topics cooking in 'next'.  Until it matures, none part
   of it is merged to 'master'.

 * A topic already in 'next' can get fixes while still in
   'next'.  Such a topic will have many merges to 'next' (in
   other words, "git log --first-parent next" will show many
   "Merge ai/topic to next" for the same topic.

 * An unobvious fix for 'maint' is cooked in 'next' and then
   merged to 'master' to make extra sure it is Ok and then
