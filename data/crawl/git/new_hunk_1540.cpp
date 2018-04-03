        if emailprefix is not None:
            emailprefix = emailprefix.strip()
            if emailprefix:
                emailprefix += ' '
        else:
            emailprefix = '[%(repo_shortname)s] '
        short_name = self.get_repo_shortname()
        try:
            return emailprefix % {'repo_shortname': short_name}
        except:
            self.get_logger().error(
                '*** Invalid multimailhook.emailPrefix: %s\n' % emailprefix +
                '*** %s\n' % sys.exc_info()[1] +
                "*** Only the '%(repo_shortname)s' placeholder is allowed\n"
                )
            raise ConfigurationException(
                '"%s" is not an allowed setting for emailPrefix' % emailprefix
                )

    def get_sender(self):
        return self.config.get('envelopesender')
