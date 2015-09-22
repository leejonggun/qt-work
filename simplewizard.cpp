//#include <QWizard>
//#include <QLabel>
//#include <QLineEdit>
//#include <QComboBox>
//#include <QVBoxLayout>

//class WizardHelper : public QWidget
//{
//    Q_OBJECT

//public:
//    QLineEdit *nameLineEdit;
//    QComboBox *ageBox;
//    QString inputName;
//    QString inputAge;
//
//private slots:
//    void on_nameLineEdit_editingFinished() { inputName = nameLineEdit->text(); };
//    void on_ageBox_currentIndexChanged();
//
//public:
//    explicit WizardHelper(QWidget *parent):QWidget(parent)
//    {
//        nameLineEdit = new QLineEdit();
//        ageBox = new QComboBox();
//    }
//};

//QWizardPage *createIntroPage()
//{
//    QWizardPage *introPage = new QWizardPage();
//    introPage->setTitle("QWizard is one of the QDialog Type.");
//
//    QLabel *label = new QLabel("This is an example for QDialog."
//                               "You can learn how to get result from the user through registration page.");
//    label->setWordWrap(true);
//
//    QVBoxLayout *layout = new QVBoxLayout();
//    layout->addWidget(label);
//    introPage->setLayout(layout);
//
//    return introPage;
//}
//
//QWizardPage *createRegistrationPage()
//{
//    QWizardPage *registrationPage = new QWizardPage();
//    registrationPage->setTitle("Registation page. get input from user.");
//    registrationPage->setSubTitle("Please fill your name and age and your gender."
//                                  "You can get the result from user to next page.");
//
//    QLabel *name = new QLabel("Name:");
//    QLineEdit *nameLineEdit = new QLineEdit();
////    connect(nameLineEdit, SIGNAL(editingFinished()), helper, SLOT(on_nameLineEdit_editingFinished()));
//
//    QLabel *age = new QLabel("Age:");
//    QComboBox *ageBox = new QComboBox();
//    for (int i=0; i < 100; i++)
//        ageBox->addItem("%d", i);
//
//    QGridLayout *layout = new QGridLayout();
//    layout->addWidget(name, 0, 0);
//    layout->addWidget(nameLineEdit, 0, 1);
//    layout->addWidget(age, 1, 0);
//    layout->addWidget(ageBox, 1, 1);
//    registrationPage->setLayout(layout);
//
//    return registrationPage;
//}
//
//QWizardPage *createConclusionPage()
//{
//    QWizardPage *conclusionPage = new QWizardPage();
//    conclusionPage->setTitle("Conclusion Page");
//    conclusionPage->setSubTitle("How great! Below is you input the registration page. Have a nice day!");
//
//    QLabel *name = new QLabel("Input Name:");
//    QLabel *inputNameLabel = new QLabel("Input Name should be printed");
//
//    QLabel *age = new QLabel("Input Age:");
//    QLabel *inputAgeLabel = new QLabel("Input Age should be printed");
//
//    QGridLayout *layout = new QGridLayout();
//    layout->addWidget(name, 0, 0);
//    layout->addWidget(inputNameLabel, 0, 1);
//    layout->addWidget(age, 1, 0);
//    layout->addWidget(inputAgeLabel, 1, 1);
//    conclusionPage->setLayout(layout);
//
//    return conclusionPage;
//}
//
//void createSimpleWizard()
//{
//    QWizard trivialWizard;
//    trivialWizard.addPage(createIntroPage());
//    trivialWizard.addPage(createRegistrationPage());
//    trivialWizard.addPage(createConclusionPage());
//}
//
