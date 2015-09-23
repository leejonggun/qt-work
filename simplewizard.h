#ifndef SIMPLEWIZARD
#define SIMPLEWIZARD

#include <QWizard>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QVBoxLayout>

class SimpleWizard : public QWizard
{
    Q_OBJECT

public:
    explicit SimpleWizard(QWidget *parent = 0);
    virtual ~SimpleWizard() {};

private slots:
    void on_nameLineEdit_editingFinished();
    void on_ageBox_currentIndexChanged(int index);

public:
    QLineEdit *nameLineEdit;
    QComboBox *ageBox;
    QString inputName;
    int inputAge;

private:
    QWizardPage *createIntroPage();
    QWizardPage *createRegistrationPage();
    QWizardPage *createConclusionPage();
public:
    QWizard *buildWizardPages();
};

#endif // SIMPLEWIZARD
