#include <git2.h>
#include "messages.h"

git_repository* repo;

//function prototypes
void check_is_shallow();

void scan(git_repository* repository) {
    repo = repository;
    check_is_shallow();
    info("<p>Scan complete! Thanks for using git-teacher!</p>");
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
    }
}
