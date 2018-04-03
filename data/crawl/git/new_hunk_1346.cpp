                to_addrs = [email for (name, email) in getaddresses([to_addrs])]
            self.smtp.sendmail(self.envelopesender, to_addrs, msg)
        except smtplib.SMTPResponseException:
            err = sys.exc_info()[1]
            self.environment.get_logger().error(
                '*** Error sending email ***\n'
                '*** Error %d: %s\n'
                % (err.smtp_code, bytes_to_str(err.smtp_error)))
            try:
                smtp = self.smtp
                # delete the field before quit() so that in case of
                # error, self.smtp is deleted anyway.
                del self.smtp
                smtp.quit()
            except:
                self.environment.get_logger().error(
                    '*** Error closing the SMTP connection ***\n'
                    '*** Exiting anyway ... ***\n'
                    '*** %s\n' % sys.exc_info()[1])
            sys.exit(1)


