        if emailprefix is not None:
            emailprefix = emailprefix.strip()
            if emailprefix:
                return emailprefix + ' '
            else:
                return ''
        else:
            return '[%s] ' % (self.get_repo_shortname(),)

    def get_sender(self):
        return self.config.get('envelopesender')
