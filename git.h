#ifndef GIT_H
#define GIT_H

#include <git2.h>

git_repository* get_repo(const char* path);

#endif // GIT_H
