#include "wordfind.h"
#include "ui_wordfind.h"

wordfind::wordfind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wordfind)
{
    ui->setupUi(this);
}

wordfind::~wordfind()
{
    delete ui;
}
