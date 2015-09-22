#ifndef CUSTOMDIALOG_H
#define CUSTOMDIALOG_H

#include <QDialog>

class CustomDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomDialog(QWidget *parent = 0);

signals:

public slots:

private:

};

void createSimpleWizard();
#endif // CUSTOMDIALOG_H
