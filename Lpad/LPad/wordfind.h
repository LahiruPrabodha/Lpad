#ifndef WORDFIND_H
#define WORDFIND_H

#include <QDialog>

namespace Ui {
class wordfind;
}

class wordfind : public QDialog
{
    Q_OBJECT

public:
    explicit wordfind(QWidget *parent = 0);
    ~wordfind();

private:
    Ui::wordfind *ui;
};

#endif // WORDFIND_H
