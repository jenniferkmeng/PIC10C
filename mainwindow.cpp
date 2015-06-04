#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "game.h"

#include <QString>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsTextItem>
#include <QPoint>

//extern Game* game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
void MainWindow::Easy()
{

    layout = new QHBoxLayout();

    game = new Game();

    layout->addWidget(game);

    w = new QWidget();
    w->setLayout(layout);
    w->setGeometry(535,100,850,850);
    w->show();

    centralWidget()->setLayout(layout);
}

void MainWindow::Medium()
{
    game = new Game();
    game->show();
    // Make the player focusable and set it to be the current focus
    this->setCentralWidget(game);

    game->player->setFlag(QGraphicsItem::ItemIsFocusable);
    game->player->setFocus();
}

void MainWindow::Hard()
{
    game = new Game();

    // Make the player focusable and set it to be the current focus
    game->player->setFlag(QGraphicsItem::ItemIsFocusable);
    game->player->setFocus();
    this->setCentralWidget(game);
}

void MainWindow::ShowInstructions()
{
    instructions = new Instructions();
    instructions->show();
}

void MainWindow::GameOver()
{
    // delete centralWidget();
    // Take Board in current game out of CentralWidget
    QWidget* wid = this->centralWidget();
    wid->setParent(nullptr);
    // Line above will delete the widget gracefully (no memory errors)

    // Display something which says that you lost, maybe display high score.

    // Reset the MainWindow with the initial startup screen
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
