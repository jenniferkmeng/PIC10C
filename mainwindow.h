#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include "instructions.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QWidget>
#include <QHBoxLayout>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QWidget* w;
public slots:

    void Easy();
    void Medium();
    void Hard();

    void ShowInstructions();

    void GameOver();

private:
    Ui::MainWindow *ui;

    Game* game;
    QDialog* instructions;


    QHBoxLayout* layout;


};

#endif // MAINWINDOW_H
