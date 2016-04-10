#include <git2.h>
#include "homewindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    HomeWindow w;
    git_libgit2_init(); //Don't move this.
    w.show();
    return a.exec();
}
