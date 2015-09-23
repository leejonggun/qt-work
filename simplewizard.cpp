#include "simplewizard.h"
#include "customlogger.h"

SimpleWizard::SimpleWizard(QWidget *parent):QWizard(parent)
{
    nameLineEdit = new QLineEdit();
    ageBox = new QComboBox();
    inputName = "";
    inputAge = 0;
}

QWizardPage *SimpleWizard::createIntroPage()
{
    QWizardPage *introPage = new QWizardPage();
    introPage->setTitle("QWizard is one of the QDialog Type.");

    QLabel *label = new QLabel("This is an example for QDialog."
                               "You can learn how to get result from the user through registration page.");
    label->setWordWrap(true);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(label);
    introPage->setLayout(layout);

    return introPage;
}

QWizardPage *SimpleWizard::createRegistrationPage()
{
    QWizardPage *registrationPage = new QWizardPage();
    registrationPage->setTitle("Registation page. get input from user.");
    registrationPage->setSubTitle("Please fill your name and age and your gender."
                                  "You can get the result from user to next page.");

    QLabel *name = new QLabel("Name:");
    connect(nameLineEdit, SIGNAL(editingFinished()), this, SLOT(on_nameLineEdit_editingFinished()));

    QLabel *age = new QLabel("Age:");
    for (int i=0; i < 100; i++)
        ageBox->addItem(QString::number(i));
    connect(ageBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_ageBox_currentIndexChanged(int)));

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(name, 0, 0);
    layout->addWidget(nameLineEdit, 0, 1);
    layout->addWidget(age, 1, 0);
    layout->addWidget(ageBox, 1, 1);
    registrationPage->setLayout(layout);

    return registrationPage;
}

QWizardPage *SimpleWizard::createConclusionPage()
{
    QWizardPage *conclusionPage = new QWizardPage();
    conclusionPage->setTitle("Conclusion Page");
    conclusionPage->setSubTitle("How great! Below is you input the registration page. Have a nice day!");

    QLabel *name = new QLabel("Input Name:");
    customLog(DEBUG, "createConclusionPage: inputName = %s", inputName.toStdString().c_str());
    QLabel *inputNameLabel = new QLabel(inputName);

    QLabel *age = new QLabel("Input Age:");
    customLog(DEBUG, "createConclusionPage: inputAge = %d", inputAge);
    QLabel *inputAgeLabel = new QLabel(QString::number(inputAge));

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(name, 0, 0);
    layout->addWidget(inputNameLabel, 0, 1);
    layout->addWidget(age, 1, 0);
    layout->addWidget(inputAgeLabel, 1, 1);
    conclusionPage->setLayout(layout);

    return conclusionPage;
}

void SimpleWizard::on_nameLineEdit_editingFinished()
{
    customLog(DEBUG, "nameLineEdit->text() = %s", nameLineEdit->text().toStdString().c_str());
    inputName = nameLineEdit->text();
    customLog(DEBUG, "inputName = %s, nextId = %d", inputName.toStdString().c_str(), nextId());
    int next = nextId();
    addPage(createConclusionPage());
    removePage(next);
}

void SimpleWizard::on_ageBox_currentIndexChanged(int index)
{
    customLog(DEBUG, "index = %d", index);
    inputAge = index;
    customLog(DEBUG, "inputAge = %d, nextId = %d", inputAge, nextId());
    int next = nextId();
    addPage(createConclusionPage());
    removePage(next);
}

QWizard *SimpleWizard::buildWizardPages()
{
    addPage(createIntroPage());
    addPage(createRegistrationPage());
    addPage(createConclusionPage());

    customLog(DEBUG, "createSimpleWizard");
    return this;
}
