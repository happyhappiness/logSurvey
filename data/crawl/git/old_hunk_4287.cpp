whitespaces (fatal in patches).  Running 'C-u g' to display the
message in raw form before using '|' to run the pipe can work
this problem around.


Gmail

GMail does not appear to have any way to turn off line wrapping in the web
interface, so this will mangle any emails that you send.  You can however
use "git send-email" and send your patches through the GMail SMTP server, or
use any IMAP email client to connect to the google IMAP server and forward
the emails through that.

To use "git send-email" and send your patches through the GMail SMTP server,
edit ~/.gitconfig to specify your account settings:

[sendemail]
	smtpencryption = tls
	smtpserver = smtp.gmail.com
	smtpuser = user@gmail.com
	smtppass = p4ssw0rd
	smtpserverport = 587

Once your commits are ready to be sent to the mailing list, run the
following commands:

  $ git format-patch --cover-letter -M origin/master -o outgoing/
  $ edit outgoing/0000-*
  $ git send-email outgoing/*

To submit using the IMAP interface, first, edit your ~/.gitconfig to specify your
account settings:

[imap]
	folder = "[Gmail]/Drafts"
	host = imaps://imap.gmail.com
	user = user@gmail.com
	pass = p4ssw0rd
	port = 993
	sslverify = false

You might need to instead use: folder = "[Google Mail]/Drafts" if you get an error
that the "Folder doesn't exist".

Once your commits are ready to be sent to the mailing list, run the
following commands:

  $ git format-patch --cover-letter -M --stdout origin/master | git imap-send

Just make sure to disable line wrapping in the email client (GMail web
interface will line wrap no matter what, so you need to use a real
IMAP client).
