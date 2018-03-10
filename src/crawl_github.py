from pygithub3 import Github
import csv
import sys
import re
import base64
import my_util

reload(sys)
sys.setdefaultencoding('utf8')

USER_NAME = 'squid-cache'
REPOS_NAME = 'squid'
LOG_PATTERN = my_util.get_log_function_pattern(REPOS_NAME)

def store_patch_file(patch, counter, record, writer):
    """
    @ param patch, counter, record and writer\n
    @ return new counter\n
    @ involve check patch for log modification and store patch file if success\n
    """
    if patch is None:
        print record
    for line in patch:
        if line.startswith('-') or line.startswith('+'):
            is_log = re.search(LOG_PATTERN, line, re.I)
            if is_log:
                file_name = 'data/crawl/' + REPOS_NAME + '/patch_' + str(counter) + '.diff'
                my_util.store_file(file_name, patch)
                writer.writerow(record + [file_name])
                return counter + 1
    
    return counter

def analyze_commit(gh, sha, counter, writer):
    """
    @ param gh, sha, counter and writer\n
    @ return new counter\n
    @ involve retrive record info of commit [url, date, title, changes, file_name]\n
    """
    # retrieve info of commit with given sha
    commit = gh.repos.commits.get(sha=sha)

    # save commit patch according to files
    patch = []
    for changed_file in commit.files:
        # append this patch file into current patch
        try:
            patch += changed_file.patch.split('\n')
        except AttributeError as ae:
            print 'no patch attribute for this file %s in commit %s' %(changed_file.filename, sha)

    # fetch url, date, title and changes
    changes = commit.stats.total
    url = commit.html_url
    date = commit.commit.committer.date.strftime('%d %b %Y')
    title = commit.commit.message

    return store_patch_file(patch, counter, [url, date, title, changes], writer)

def analyze_commit_list(start_commit, writer, total_counter=0, counter=0):
    """
    @ param  and writer\n
    @ return new counter\n
    @ involve retrive record info of commit [url, date, title, changes, file_name]\n
    """
    # initiate Github with given user and repos 
    gh = Github(login='993273596@qq.com', password='nx153156', user=USER_NAME, repo=REPOS_NAME)

    # fetch all the commits of given repos
    commits = gh.repos.commits.list(sha=start_commit)
    for commit in commits.iterator():
        # invoke the deal_commit function
        total_counter += 1
        counter = analyze_commit(gh, commit.sha, counter, writer)
        if total_counter % 5 == 0:
            print 'now have cawled %d commit, find %d log commit' %(total_counter, counter)


"""
main function
"""
if __name__ == "__main__":
    # several configuration constant: user, repos
    commit_sha = '25f983407b3c3df95d9f81edf1bd917316f2dfda'

    record_file = file('data/analyze/' + REPOS_NAME + '_log_commit.csv', 'ab')
    writer = csv.writer(record_file)
    # writer.writerow(['url', 'date', 'title', 'changes', 'file_name'])

    # analyze commit list of given repos with start commit
    analyze_commit_list(commit_sha, writer, 6375, 735)
    record_file.close()

