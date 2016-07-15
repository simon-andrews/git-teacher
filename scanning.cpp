#include <git2.h>
#include "messages.h"

git_repository* repo;
int error_count;
int branchcount;

//function prototypes
void check_is_shallow();
void check_master_exists();

void scan(git_repository* repository) {
    error_count = 0;
    repo = repository;

    //check the repo (general stuff)
    check_is_shallow();

    //check branches
    check_master_exists();

    info(QString("<p>Scan complete! Thanks for using git-teacher!</p><p>There were potential %1 problems found.</p>").arg(QString::number(error_count)));
}

/*
 * Checks for a shallow clone. New users may be tempted by the promise of a
 * faster clone time, but might not understand that the tradeoff is that they
 * won't be able to do much on the Git side of things.
 */
void check_is_shallow() {
    if(git_repository_is_shallow(repo) == 1) {
        warn("<p><b>Your repository is shallow.</b></p>"
             "<p>When you cloned your repository, you performed a shallow clone, probably by using the <code>--depth=n</code> flag.</p>"
             "<p>While this made your clone faster, it achieved this by not downloading the full history of the repository. This means you can't perform actions like merging or viewing the log.</p>"
             "<p>You're probably going to want to reclone, but make sure to leave off the <code>--depth</code> flag this time!</p>");
        error_count++;
    }
}

/*
 * Makes sure the repository has a master branch
 */
void check_master_exists() {
    git_reference* ref;
    if(git_reference_dwim(&ref, repo, "master") != 0) {
        warn("<p><b>No master branch found.</b></p>"
             "<p>For some reason, you don't have a master branch in your repository. The master branch is usually the main branch that the others are based off of.</p>"
             "<p>While this isn't <em>necessarily</em> a bad thing, chances are you want a master branch.</p>"
             "<p>You can create a master branch with <code>git checkout -b master</code>.");
        error_count++;
    }
    git_reference_free(ref);
}
