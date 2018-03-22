from pygithub3 import Github
import csv
import sys
import re
import base64
import my_util

reload(sys)
sys.setdefaultencoding('utf8')

# USER_NAME = 'squid-cache'
# REPOS_NAME = 'squid'
# USER_NAME = 'collectd'
# REPOS_NAME = 'collectd'

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
            is_log = re.search(my_util.LOG_PATTERN, line, re.I)
            if is_log:
                file_name = my_util.PATCH_FILE_PREFIX + str(counter) + '.diff'
                my_util.store_file(file_name, patch)
                writer.writerow(record + [file_name])
                return counter + 1
    
    return counter

def analyze_commit(gh, sha, total_counter, counter, writer):
    """
    @ param gh, sha, total_counter, counter and writer\n
    @ return total_counter, new counter\n
    @ involve retrive record info of commit [url, date, title, changes, file_name]\n
    """
    # retrieve info of commit with given sha
    commit = gh.repos.commits.get(sha=sha)
    title = commit.commit.message
    if title.startswith('Merge'):
        return total_counter, counter
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

    total_counter += 1
    return total_counter, store_patch_file(patch, counter, [url, date, title, changes], writer)

def analyze_commit_list(start_commit, writer, total_counter=0, counter=0):
    """
    @ param  and writer\n
    @ return new counter\n
    @ involve retrive record info of commit [url, date, title, changes, file_name]\n
    """
    # initiate Github with given user and repos 
    gh = Github(login='993273596@qq.com', password='nx153156', user=my_util.USER_NAME, repo=my_util.REPOS_NAME)

    # fetch all the commits of given repos
    commits = gh.repos.commits.list(sha=start_commit)
    for commit in commits.iterator():
        # invoke the deal_commit function
        total_counter, counter = analyze_commit(gh, commit.sha, total_counter, counter, writer)
        if total_counter % 5 == 0:
            print 'now have cawled %d commit, find %d log commit' %(total_counter, counter)


"""
main function
"""
if __name__ == "__main__":
    # several configuration constant: user, repos
    # set repos and user
    my_util.set_user_repos('git', 'git')
    commit_sha = '29bdbac1cd5fc4126b62c9a030403d56ae43c204'

    record_file = file(my_util.PATCH_RECORD_FILE, 'ab')
    writer = csv.writer(record_file)
    # writer.writerow(my_util.PATCH_RECORD_TITLE)

    # analyze commit list of given repos with start commit
    analyze_commit_list(commit_sha, writer, 21535, 3487)
    record_file.close()

