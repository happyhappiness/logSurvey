      (setq coding-system-for-write buffer-file-coding-system))
    (let ((commit
           (git-get-string-sha1
            (with-output-to-string
              (with-current-buffer standard-output
                (let ((env `(("GIT_AUTHOR_NAME" . ,author-name)
                             ("GIT_AUTHOR_EMAIL" . ,author-email)
                             ("GIT_COMMITTER_NAME" . ,(git-get-committer-name))
                             ("GIT_COMMITTER_EMAIL" . ,(git-get-committer-email)))))
                  (when author-date (push `("GIT_AUTHOR_DATE" . ,author-date) env))
                  (apply #'git-run-command-region
                         buffer log-start log-end env
                         "commit-tree" tree (nreverse args))))))))
      (and (git-update-ref "HEAD" commit head subject)
           commit))))

(defun git-empty-db-p ()
  "Check if the git db is empty (no commit done yet)."