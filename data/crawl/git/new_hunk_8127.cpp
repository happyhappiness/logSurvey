Localizing git-gui for your language
====================================

This short note is to help you, who reads and writes English and your
own language, help us getting git-gui localized for more languages.  It
does not try to be a comprehensive manual of GNU gettext, which is the
i18n framework we use, but tries to help you get started by covering the
basics and how it is used in this project.

1. Getting started.

You would first need to have a working "git".  Your distribution may
have it as "git-core" package (do not get "GNU Interactive Tools" --
that is a different "git").  You would also need GNU gettext toolchain
to test the resulting translation out.  Although you can work on message
translation files with a regular text editor, it is a good idea to have
specialized so-called "po file editors" (e.g. emacs po-mode, KBabel,
poedit, GTranslator --- any of them would work well).  Please install
them.

You would then need to clone the git-gui internationalization project
repository, so that you can work on it:

	$ git clone mob@repo.or.cz:/srv/git/git-gui/git-gui-i18n.git/
	$ cd git-gui-i18n
	$ git checkout --track -b mob origin/mob
	$ git config remote.origin.push mob

The "git checkout" command creates a 'mob' branch from upstream's
corresponding branch and makes it your current branch.  You will be
working on this branch.

The "git config" command records in your repository configuration file
that you would push "mob" branch to the upstream when you say "git
push".


2. Starting a new language.

In the git-gui-i18n directory is a po/ subdirectory.  It has a
handful files whose names end with ".po".  Is there a file that has
messages in your language?

If you do not know what your language should be named, you need to find
it.  This currently follows ISO 639-1 two letter codes:

	http://www.loc.gov/standards/iso639-2/php/code_list.php

For example, if you are preparing a translation for Afrikaans, the
language code is "af".  If there already is a translation for your
language, you do not have to perform any step in this section, but keep
reading, because we are covering the basics.

If you did not find your language, you would need to start one yourself.
Copy po/git-gui.pot file to po/af.po (replace "af" with the code for
your language).  Edit the first several lines to match existing *.po
files to make it clear this is a translation table for git-gui project,
and you are the primary translator.  The result of your editing would
look something like this:

    # Translation of git-gui to Afrikaans
    # Copyright (C) 2007 Shawn Pearce
    # This file is distributed under the same license as the git-gui package.
    # YOUR NAME <YOUR@E-MAIL.ADDRESS>, 2007.
    #
    #, fuzzy
    msgid ""
    msgstr ""
    "Project-Id-Version: git-gui\n"
    "Report-Msgid-Bugs-To: \n"
    "POT-Creation-Date: 2007-07-24 22:19+0300\n"
    "PO-Revision-Date: 2007-07-25 18:00+0900\n"
    "Last-Translator: YOUR NAME <YOUR@E-MAIL.ADDRESS>\n"
    "Language-Team: Afrikaans\n"
    "MIME-Version: 1.0\n"
    "Content-Type: text/plain; charset=UTF-8\n"
    "Content-Transfer-Encoding: 8bit\n"

You will find many pairs of a "msgid" line followed by a "msgstr" line.
These pairs define how messages in git-gui application are translated to
your language.  Your primarily job is to fill in the empty double quote
pairs on msgstr lines with the translation of the strings on their
matching msgid lines.  A few tips:

 - Control characters, such as newlines, are written in backslash
   sequence similar to string literals in the C programming language.
   When the string given on a msgid line has such a backslash sequence,
   you would typically want to have corresponding ones in the string on
   your msgstr line.

 - Often the messages being translated are format strings given to
   "printf()"-like functions.  Make sure "%s", "%d", and "%%" in your
   translated messages match the original.

   When you have to change the order of words, you can add "<number>\$"
   between '%' and the conversion ('s', 'd', etc.) to say "<number>-th
   parameter to the format string is used at this point".  For example,
   if the original message is like this:

	"Length is %d, Weight is %d"

   and if for whatever reason your translation needs to say weight first
   and then length, you can say something like:

	"WEIGHT IS %2\$d, LENGTH IS %1\$d"

   The reason you need a backslash before dollar sign is because
   this is a double quoted string in Tcl language, and without
   it the letter introduces a variable interpolation, which you
   do not want here.

 - A long message can be split across multiple lines by ending the
   string with a double quote, and starting another string on the next
   line with another double quote.  They will be concatenated in the
   result.  For example:

   #: lib/remote_branch_delete.tcl:189
   #, tcl-format
   msgid ""
   "One or more of the merge tests failed because you have not fetched the "
   "necessary commits.  Try fetching from %s first."
   msgstr ""
   "HERE YOU WILL WRITE YOUR TRANSLATION OF THE ABOVE LONG "
   "MESSAGE IN YOUR LANGUAGE."

You can test your translation by running "make install", which would
create po/af.msg file and installs the result, and then running the
resulting git-gui under your locale:

	$ make install
	$ LANG=af git-gui

There is a trick to test your translation without first installing, if
you prefer.  First, create this symbolic link in the source tree:

	$ ln -s ../po lib/msgs

After setting up such a symbolic link, you can:

	$ make
	$ LANG=af ./git-gui.sh

When you are satisfied with your translation, commit your changes, and
push it back to the 'mob' branch:

	$ edit po/af.po
	... be sure to update Last-Translator: and
	... PO-Revision-Date: lines.
	$ git add po/af.po
	$ git commit -m 'Started Afrikaans translation.'
	$ git push


3. Updating your translation.

There may already be a translation for your language, and you may want
to contribute an update.  This may be because you would want to improve
the translation of existing messages, or because the git-gui software
itself was updated and there are new messages that need translation.

In any case, make sure you are up-to-date before starting your work:

	$ git pull

In the former case, you will edit po/af.po (again, replace "af" with
your language code), and after testing and updating the Last-Translator:
and PO-Revision-Date: lines, "add/commit/push" as in the previous
section.

By comparing "POT-Creation-Date:" line in po/git-gui.pot file and
po/af.po file, you can tell if there are new messages that need to be
translated.  You would need the GNU gettext package to perform this
step.

	$ msgmerge -U po/af.po po/git-gui.pot

[NEEDSWORK: who is responsible for updating po/git-gui.pot file by
running xgettext?  IIRC, Christian recommended against running it
nilly-willy because it can become a source of unnecessary merge
conflicts.  Perhaps we should mention something like "

The po/git-gui.pot file is updated by the internationalization
coordinator from time to time.  You _could_ update it yourself, but
translators are discouraged from doing so because we would want all
language teams to be working off of the same version of git-gui.pot.

" here?]

This updates po/af.po (again, replace "af" with your language
code) so that it contains msgid lines (i.e. the original) that
your translation did not have before.  There are a few things to
watch out for:

 - The original text in English of an older message you already
   translated might have been changed.  You will notice a comment line
   that begins with "#, fuzzy" in front of such a message.  msgmerge
   tool made its best effort to match your old translation with the
   message from the updated software, but you may find cases that it
   matched your old translated message to a new msgid and the pairing
   does not make any sense -- you would need to fix them, and then
   remove the "#, fuzzy" line from the message (your fixed translation
   of the message will not be used before you remove the marker).

 - New messages added to the software will have msgstr lines with empty
   strings.  You would need to translate them.