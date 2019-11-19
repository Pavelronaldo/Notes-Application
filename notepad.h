#ifndef NOTEPAD_H
#define NOTEPAD_H
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui {class Notepad;}
QT_END_NAMESPACE
class Notepad : public QMainWindow
{
    Q_OBJECT
public:
    explicit Notepad(QWidget *parent = nullptr);
    ~Notepad();
private slots:
    void newDocument();//Print Note
    void open();//Print one Note
    void save();//Save Note
    void saveAs();//Save Archive
    void print();//Print Archive
    void cut();//Clear
    void undo();//Back
    void redo(); //Next
    void about();//About
    void on_actionHome_triggered();

    void on_actionWork_triggered();

    void on_actionJust_note_triggered();

    void on_actionShow_home_triggered();

    void on_actionShow_work_triggered();

    void on_actionShow_just_note_triggered();

private:
    Ui::Notepad *ui;
    QString currentFile;
};
#endif
