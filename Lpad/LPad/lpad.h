#ifndef LPAD_H
#define LPAD_H

#include "about.h"
#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QTextEdit>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>


namespace Ui {
class LPad;
}

class LPad : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *event);

public:
    explicit LPad(QWidget *parent = 0);
    ~LPad();
    QString mFilename;
    void findWord(QString word);

private slots:
    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionSave_As_triggered();

    void on_actionClose_triggered();

    void on_actionPrint_triggered();

    void on_actionFind_Word_triggered();

    void on_actionAbout_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_findButton_clicked();

    void on_actionFind_triggered();

    void on_actionLeft_Align_triggered();

    void on_actionRight_Align_triggered();

    void on_actionCenter_triggered();

    void on_actionJestify_triggered();

    void on_actionColor_triggered();

    void on_actionFont_2_triggered();

    void on_actionBackground_Color_triggered();

    void on_actionBold_triggered();

    void on_actionUnderline_triggered();

    void on_actionItalic_triggered();

private:
    Ui::LPad *ui;
    QAction *printAction;
    about *Aboutt;
    QPrinter *printer;
    QPrintDialog *printDialog;
    LPad *New;
    QTextDocument *document;



public slots:
    void printFile();
    void openfile();
    void newfile();
    void getTextFile();
    bool saveasfile();
    bool savefile();

};

#endif // LPAD_H
