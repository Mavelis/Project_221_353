#include "taskform.h"
#include "ui_taskform.h"

TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    ui->setupUi(this);
    ui->taskText->setWordWrap(true);
}

void TaskForm::initTask(QString taskText, int taskId) {
    this->taskId = taskId;
    this->ui->taskText->setText(taskText);
}



TaskForm::~TaskForm()
{
    delete ui;
}

void TaskForm::on_TryButton_clicked()
{
    QString userAnswer = "";
    int selectedId = this->ui->buttonGroup->checkedId();
    qDebug() << selectedId;

    if (selectedId == -2) {
        userAnswer = "1";
    } else if (selectedId == -3) {
        userAnswer = "0";
    }

    bool status = checkTask(this->taskId, userAnswer);
    if (status) this->ui->statusLabel->setText("Правильный ответ");
        else this->ui->statusLabel->setText("Неправильный ответ");
}


void TaskForm::on_LoseButton_clicked()
{
    this->close();
}

