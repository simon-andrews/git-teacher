#include <QMessageBox>

void info(QString message) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setWindowTitle("Git Teacher Info");
    msgBox.setText(message);
    msgBox.exec();
}

void warn(QString message) {
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setWindowTitle("Git Teacher Warning");
    msgBox.setText(message);
    msgBox.exec();
}
