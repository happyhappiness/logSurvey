                self.smtp = call(smtplib.SMTP_SSL, self.smtpserver, timeout=self.smtpservertimeout)
            elif self.security == 'tls':
                if 'ssl' not in sys.modules:
                    sys.stderr.write(
                        '*** Your Python version does not have the ssl library installed\n'
                        '*** smtpEncryption=tls is not available.\n'
                        '*** Either upgrade Python to 2.6 or later\n'
