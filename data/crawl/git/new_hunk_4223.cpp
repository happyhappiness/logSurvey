
5) Back in the compose window: add whatever other text you wish to the
message, complete the addressing and subject fields, and press send.


Gmail
-----

GMail does not appear to have any way to turn off line wrapping in the web
interface, so this will mangle any emails that you send.  You can however
use any IMAP email client to connect to the google imap server, and forward
the emails through that.  Just make sure to disable line wrapping in that
email client.  Alternatively, use "git send-email" instead.

Submitting properly formatted patches via Gmail is simple now that
IMAP support is available. First, edit your ~/.gitconfig to specify your
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

Next, ensure that your Gmail settings are correct. In "Settings" the
"Use Unicode (UTF-8) encoding for outgoing messages" should be checked.

Once your commits are ready to send to the mailing list, run the following
command to send the patch emails to your Gmail Drafts folder.

	$ git format-patch -M --stdout origin/master | git imap-send

Go to your Gmail account, open the Drafts folder, find the patch email, fill
in the To: and CC: fields and send away!

