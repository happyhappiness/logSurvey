                        self.smtp.sock,
                        cert_reqs=ssl.CERT_NONE
                        )
                    self.environment.get_logger().error(
                        '*** Warning, the server certificat is not verified (smtp) ***\n'
                        '***          set the option smtpCACerts                   ***\n'
                        )
