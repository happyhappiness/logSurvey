..........................


EXAMPLE
-------
To submit patches using GMail's IMAP interface, first, edit your ~/.gitconfig
to specify your account settings:

---------
[imap]
	folder = "[Gmail]/Drafts"
	host = imaps://imap.gmail.com
	user = user@gmail.com
	port = 993
	sslverify = false
---------

You might need to instead use: folder = "[Google Mail]/Drafts" if you get an error
that the "Folder doesn't exist".

Once the commits are ready to be sent, run the following command:

  $ git format-patch --cover-letter -M --stdout origin/master | git imap-send

Just make sure to disable line wrapping in the email client (GMail's web
interface will wrap lines no matter what, so you need to use a real
IMAP client).

CAUTION
-------
It is still your responsibility to make sure that the email message
