#include <git2.h>
#include "git.h"
#include "homewindow.h"
#include "messages.h"
#include <QFileDialog>
#include "ui_homewindow.h"

HomeWindow::HomeWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::HomeWindow) {
    ui->setupUi(this);
    connect(ui->dirEntryButton, SIGNAL(clicked()), this, SLOT(handleDirSelectButton()));
    connect(ui->scanNowButton, SIGNAL(clicked()), this, SLOT(handleScanButton()));
    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(handleQuitButton()));
}

HomeWindow::~HomeWindow() {
    delete ui;
}

void HomeWindow::handleDirSelectButton() {
    QString dialog = QFileDialog::getExistingDirectory(this, tr("Pick a Git repo"), "/");
    ui->dirEntryButton->setText(dialog);
    ui->scanNowButton->setEnabled(true);
}

void HomeWindow::handleScanButton() {
    ui->progressBar->setEnabled(true);
    const char* path = ui->dirEntryButton->text().toLatin1().data();
    git_repository* repo = get_repo(path);
    info("Congrats on getting this far! Sadly, this program isn't ready yet :(");
    git_repository_free(repo);
}

void HomeWindow::handleQuitButton() {
    QApplication::quit();
}
