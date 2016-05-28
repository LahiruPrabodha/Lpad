/*  Author :- Lahiru Prabodha Wicramarathne
 * Student of Plymouth University @ NSBM
 * LPad 0.1v
*/
#include "lpad.h"
#include "ui_lpad.h"
#include "about.h"

#include "QTextCursor"
#include <QFileDialog>
#include <QMessageBox>
#include <QDialog>
#include <QtGui>
#include <QColorDialog>
#include <QFontDialog>
#include <QFont>
//librarys for document printer
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include "QTextStream"

//#include<QPrinter>
//#include<QPrintDialog>



/**
 * @brief LPad::closeEvent
 * @param event
 */
void LPad::closeEvent(QCloseEvent *event)
{
    on_actionExit_triggered();
    event->ignore();
}
/**
 * @brief LPad::LPad
 * @param parent
 */
LPad::LPad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LPad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    this->setWindowTitle("LPad");
}
/**
 * @brief LPad::~LPad
 */
LPad::~LPad()
{
    delete ui;
}
/**
 * @brief LPad::on_actionOpen_triggered
 */
void LPad::on_actionOpen_triggered()
{
   openfile();
}
/**
 * @brief LPad::on_actionNew_triggered
 */
void LPad::on_actionNew_triggered()
{
    newfile();
}
/**
 * @brief LPad::on_actionSave_triggered
 */
void LPad::on_actionSave_triggered()
{
    savefile();
}
/**
 * @brief LPad::on_actionSave_As_triggered
 */
void LPad::on_actionSave_As_triggered()
{
    saveasfile();
}
/**
 * @brief LPad::on_actionCopy_triggered
 */
void LPad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}
/**
 * @brief LPad::on_actionCut_triggered
 */
void LPad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}
/**
 * @brief LPad::on_actionPaste_triggered
 */
void LPad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
/**
 * @brief LPad::on_actionUndo_triggered
 */
void LPad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}
/**
 * @brief LPad::on_actionRedo_triggered
 */
void LPad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
/**
 * @brief LPad::on_actionZoom_In_triggered
 */
void LPad::on_actionZoom_In_triggered()
{
    ui->textEdit->zoomIn();
}
/**
 * @brief LPad::on_actionZoom_Out_triggered
 */
void LPad::on_actionZoom_Out_triggered()
{
    ui->textEdit->zoomOut();
}
/**
 * @brief LPad::on_actionClose_triggered
 */
void LPad::on_actionClose_triggered()

{

    QMessageBox *dialog = new QMessageBox();
    dialog->setText(tr("The content has been modified."));
    dialog->setInformativeText(tr("Do you want to save the changes?"));
    dialog->setStandardButtons(QMessageBox::Save | QMessageBox::Discard);
    dialog->setDefaultButton(QMessageBox::Save);

    int ret = dialog->exec();

    switch (ret) {
    case QMessageBox::Save:
        if(mFilename==NULL)
        {
            on_actionSave_As_triggered();
        }
        else
        {
            on_actionSave_triggered();
        }
        break;
    case QMessageBox::Discard:
        ui->textEdit->close();
        exit(0);
        break;
    default:
        break;
    }

}
/**
 * @brief LPad::on_actionExit_triggered
 */
void LPad::on_actionExit_triggered()

{

    QMessageBox *dialog = new QMessageBox();
    dialog->setText(tr("Exit LPad Editor"));
    dialog->setInformativeText(tr("Do you want to Save Text Editor Press 'YES',Do you want to Exit Text Editor Press 'NO'"));
    dialog->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    dialog->setDefaultButton(QMessageBox::No);

    int ret = dialog->exec();

    switch (ret) {
    case QMessageBox::Yes:
        if(mFilename==NULL)
        {
            on_actionSave_As_triggered();
        }
        else
        {
            on_actionSave_triggered();
        }
        break;
    case QMessageBox::No:
        ui->textEdit->close();
        exit(0);
        break;
    default:
        break;
    }

}
/**
 * @brief LPad::on_actionFind_triggered
 */
void LPad::on_actionFind_triggered()
{
    ui->FinddockWidget->show();
    ui->FinddockWidget->setFloating(true);
}
/**
 * @brief LPad::on_actionLeft_Align_triggered
 */
void LPad::on_actionLeft_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignLeft);
}
/**
 * @brief LPad::on_actionRight_Align_triggered
 */
void LPad::on_actionRight_Align_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignRight);
}
/**
 * @brief LPad::on_actionCenter_triggered
 */
void LPad::on_actionCenter_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignCenter);
}
/**
 * @brief LPad::on_actionJestify_triggered
 */
void LPad::on_actionJestify_triggered()
{
    ui->textEdit->setAlignment(Qt::AlignJustify);
}
/**
 * @brief LPad::on_actionPrint_triggered
 */
void LPad::on_actionPrint_triggered()
{
    printFile();
}
/**
 * @brief LPad::on_actionFind_Word_triggered
 */
void LPad::on_actionFind_Word_triggered()
{


}
/**
 * @brief LPad::on_actionAbout_triggered
 */
void LPad::on_actionAbout_triggered()
{
       Aboutt = new about(this);
       Aboutt->show();
}
/**
 * @brief LPad::printFile
 */
void LPad::printFile()
{
    //this code not working becouse some librarys cannot insert
//    QPrinter printer;
//       printer.setOutputFormat(QPrinter::PdfFormat);
//       printer.setOutputFileName("/foobar/nonwritable.pdf");
//       QPainter painter;
//       if (! painter.begin(&printer)) { // failed to open file
//           qWarning("failed to open file, is it writable?");
//           return 1;
//       }
//       painter.drawText(10, 10, "Test");
//       if (! printer.newPage()) {
//           qWarning("failed in flushing page to disk, disk full?");
//           return 1;
//       }
//       painter.drawText(10, 10, "Test 2");
//       painter.end();



//    QPrinter printer;

//      QPrintDialog *dialog = new QPrintDialog(&printer, this);
//      dialog->setWindowTitle(tr("Print Document"));
//      if (edinr->textCursor().hasSelection())
//          dialog->addEnabledOption(QAbstractPrintDialog::PrintSelection);
//      if (dialog->exec() != QDialog::Accepted)
//          return;
}
/**
 * @brief LPad::savefile
 * @return
 */
bool LPad::savefile()
{


    if (mFilename.isEmpty())
            return saveasfile();

        QTextDocumentWriter writer(mFilename);
        bool success = writer.write(ui->textEdit->document());
        if (success)
            ui->textEdit->document()->setModified(false);
        return success;

}
/**
 * @brief LPad::saveasfile
 * @return
 */
bool LPad::saveasfile()
{

    QString file = QFileDialog::getSaveFileName(this, tr("Save as..."),QString(), tr("Text files (*.txt);;All Files (*)"));

    if (file.isEmpty())
            return false;
        if (! (file.endsWith(".txt", Qt::CaseInsensitive) ) )
            file += ".txt"; // default type
        mFilename = file;
        return savefile();
}
/**
 * @brief LPad::openfile
 */
void LPad::openfile()
{
    QString file = QFileDialog::getOpenFileName(this,tr("Open file"), mFilename, "Text files (*.txt);;All files (*.)");


    if(!file.isEmpty())
    {
        QFile sFile(file);

        if(sFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFilename = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
        }
    }

}
/**
 * @brief LPad::newfile
 */
void LPad::newfile()
{
        mFilename = "";
        ui->textEdit->setPlainText("");

        New = new LPad(this);
        New->show();
}
/**
 * @brief LPad::on_findButton_clicked
 */

void LPad::on_findButton_clicked()
{
    QString findText = ui->findlineEdit->text();
    QString textEditText = ui->textEdit->toPlainText();
    if(textEditText.contains(findText)){

        textEditText.replace(findText,"<b><font color='red'>"+findText+"</b></font>");
        ui->textEdit->setText(textEditText);

        /*QTextStream textStream(&myfile);
        QString line=textStream.readAll();
        myfile.close();         */            //Close the File

       // ui->textEdit->setPlainText(line); //take the File and display in textedit area
//         ui->textEdit->setPlainText();
//        ui->textEdit->setPlainText(line);
//        QTextCursor textCursor=ui->textEdit->textCursor();      //Cursor moves to the selected word
//        textCursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor,1);
    }
    else{
        QMessageBox msgBox;
         msgBox.setText("No result found in this document!");
         msgBox.exec();
    }
}
/**
 * @brief LPad::getTextFile
 */
void LPad::getTextFile(){

      QFile myFile(""); /* set file path in here */
      myFile.open(QIODevice::ReadOnly);

      QTextStream textStream(&myFile);
      QString line = textStream.readAll();
      myFile.close();


      ui->textEdit->setPlainText(line);
      QTextCursor textCursor = ui->textEdit->textCursor();
      textCursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor, 1);


}

/**
 * @brief LPad::on_actionColor_triggered
 */

void LPad::on_actionColor_triggered()
{
    QColor Fcolor;
    Fcolor = QColorDialog::getColor(Qt::white,this);
    ui->textEdit->setTextColor(Fcolor);
}
/**
 * @brief LPad::on_actionFont_2_triggered
 */
void LPad::on_actionFont_2_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont("Times", 12), this);

     if (ok) {
        ui->textEdit->setFont(font);
     } else {

      }
}
/**
 * @brief LPad::on_actionBackground_Color_triggered
 */
void LPad::on_actionBackground_Color_triggered()
{
    QColor Bcolor;
    Bcolor = QColorDialog::getColor(Qt::white,this);
    ui->textEdit->setTextBackgroundColor(Bcolor);
}
/**
 * @brief LPad::on_actionBold_triggered
 */
void LPad::on_actionBold_triggered()
{
    ui->textEdit->setFontWeight(QFont::Bold);
}
/**
 * @brief LPad::on_actionUnderline_triggered
 */
void LPad::on_actionUnderline_triggered()
{
    ui->textEdit->setFontUnderline(true);
}
/**
 * @brief LPad::on_actionItalic_triggered
 */
void LPad::on_actionItalic_triggered()
{
    ui->textEdit->setFontItalic(true);
}
