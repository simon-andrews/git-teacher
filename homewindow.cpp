#include <git2.h>
#include "git.h"
#include "homewindow.h"
#include <iostream>
#include "messages.h"
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::HomeWindow) {
    ui->setupUi(this);
    connect(ui->scanNowButton, SIGNAL(clicked()), this, SLOT(handleScanButton()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(handleQuitButton()));
}

HomeWindow::~HomeWindow() {
    delete ui;
}

void HomeWindow::handleScanButton() {
    ui->progressBar->setEnabled(true);
    const char* path = ui->lineEdit->text().toLatin1().data();
    git_repository* repo = get_repo(path);
    info("Congrats on getting this far! Sadly, this program isn't ready yet :(");
    git_repository_free(repo);
}

void HomeWindow::handleQuitButton() {
    QApplication::quit();
}
