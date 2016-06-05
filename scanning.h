#ifndef SCANNING_H
#define SCANNING_H

#include <git2.h>

void scan(git_repository* repo);
//don't include any of the other functions in scanning.cpp here.
//They should all be run from scan().

#endif
