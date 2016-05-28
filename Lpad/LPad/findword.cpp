#include "findword.h"
#include "ui_findword.h"
#include "lpad.h"
#include "ui_lpad.h"

findword::findword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::findword)
{
    ui->setupUi(this);
    getTextFile();      //call the getTextFile function
}

findword::~findword()
{
    delete ui;
}

void findword::on_FindButton_clicked()
{

//    lpad lp;
//    QString word=ui->lineEdit->text();  //get the word type in lineEdit
//    lp.ui->textEdit->find(word,QTextDocument::FindWholeWords); //Find the word

    //----------------------------
    LPad lp;
    QString word=ui->lineEdit->text();
    //here send word to lpad
    lp.findWord(word);



}

void findword::on_CancelButton_clicked()
{
    ui->lineEdit->close();

}

void findword::getTextFile()
{
    QFile *mFilename = new QFile();        //call the hello.txt File
//    mFilename.open(QIODevice::ReadOnly);   //open the File

//    QTextStream textStream(&mFilename);
//    QString line=textStream.readAll();
//    mFilename.close();                     //Close the File

//    ui->textEdit->setPlainText(line);   //take the File and display in textedit area

//    QTextCursor textCursor=ui->textEdit->textCursor();      //Cursor moves to the selected word
    //    textCursor.movePosition(QTextCursor::Start,QTextCursor::MoveAnchor,1);
}




