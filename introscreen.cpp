#include "introscreen.h"
#include "ui_introscreen.h"


IntroScreen::IntroScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::IntroScreen)
{
    ui->setupUi(this);
}

IntroScreen::~IntroScreen()
{
    delete ui;
}

void IntroScreen::Easy()
{
    game = new Game();

    layout = new QHBoxLayout();
    layout->addWidget(game);

    w = new QWidget();
    w->setLayout(layout);
    w->setGeometry(535,100,850,850);
    w->show();

    // Closes IntroScreen Window
    close();
}

void IntroScreen::Medium()
{
    game = new Game(this, 1500, 1500, 2500);

    layout = new QHBoxLayout();
    layout->addWidget(game);

    w = new QWidget();
    w->setLayout(layout);
    w->setGeometry(535,100,850,850);
    w->show();

    // Closes IntroScreen Window
    close();
}

void IntroScreen::Hard()
{
    game = new Game(this, 500, 2500, 500);

    layout = new QHBoxLayout();
    layout->addWidget(game);

    w = new QWidget();
    w->setLayout(layout);
    w->setGeometry(535,100,850,850);
    w->show();

    // Closes IntroScreen Window
    close();
}

void IntroScreen::ShowInstructions()
{
    instructions = new Instructions();
    instructions->show();
}
