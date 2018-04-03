                        self.smtp.sock,
                        cert_reqs=ssl.CERT_NONE
                        )
                    sys.stderr.write(
                        '*** Warning, the server certificat is not verified (smtp) ***\n'
                        '***          set the option smtpCACerts                   ***\n'
                        )
