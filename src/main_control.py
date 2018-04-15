#-*-coding: utf-8 -*-
from gumtree_api import Gumtree
import gumtree_api
import fetch_hunk
import fetch_log
import cluster_log
import my_util
import statistic

# repos name squid, git, collectd, make, tar, wget
if __name__ == "__main__":
    my_util.set_user_repos(repos_name='collectd')
    fetch_hunk.fetch_patch()
    gumtree=Gumtree()
    fetch_log.fetch_hunk(gumtree)
    cluster_log.cluster_edition()
    statistic.get_statistic()
    gumtree_api.close_jvm()