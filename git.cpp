#include <git2.h>
#include "messages.h"
#include <QString>

git_repository* get_repo(const char* path) {
    git_repository* repo = NULL;
    int error = git_repository_open(&repo, path);
    if(error < 0) {
        const git_error *e = giterr_last();
        switch(error) {
            case -3: //repo not found
                info("<p><b>No Git repository found!</b></p>"
                     "<p>You did not point this program towards a Git repository. A Git repository is a folder that contains source code and a hidden folder titled <code>.git</code>.</p>"
                     "<p>You create a Git directory every time you run <code>git init</code> or <code>git clone</code>.</p>");
                break;
            default:
                info(QString("<p><b>Unknown Error</b></p><p>Error %1/%2: %3").arg(QString::number(error), QString::number(e->klass), e->message));
                break;
        }
    }
    return repo;
}
