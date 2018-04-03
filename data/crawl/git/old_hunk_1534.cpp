class SMTPMailer(Mailer):
    """Send emails using Python's smtplib."""

    def __init__(self, envelopesender, smtpserver,
                 smtpservertimeout=10.0, smtpserverdebuglevel=0,
                 smtpencryption='none',
                 smtpuser='', smtppass='',
                 smtpcacerts=''
                 ):
        if not envelopesender:
            sys.stderr.write(
                'fatal: git_multimail: cannot use SMTPMailer without a sender address.\n'
                'please set either multimailhook.envelopeSender or user.email\n'
                )
