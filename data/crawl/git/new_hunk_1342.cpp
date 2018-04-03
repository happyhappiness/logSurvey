class SMTPMailer(Mailer):
    """Send emails using Python's smtplib."""

    def __init__(self, environment,
                 envelopesender, smtpserver,
                 smtpservertimeout=10.0, smtpserverdebuglevel=0,
                 smtpencryption='none',
                 smtpuser='', smtppass='',
                 smtpcacerts=''
                 ):
        super(SMTPMailer, self).__init__(environment)
        if not envelopesender:
            self.environment.get_logger().error(
                'fatal: git_multimail: cannot use SMTPMailer without a sender address.\n'
                'please set either multimailhook.envelopeSender or user.email\n'
                )
