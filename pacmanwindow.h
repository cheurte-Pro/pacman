#ifndef PACMANWINDOW_H
#define PACMANWINDOW_H

#include <QtCore/QtCore>
#include <QtWidgets/QtWidgets>
#include "jeu.h"

class PacmanWindow : public QFrame
{
  protected:
    Jeu jeu;
    QPixmap pixmapPacman, pixmapFantome, pixmapMur;

  public:
    PacmanWindow(QWidget *pParent=0, Qt::WindowFlags flags=0);
    void handleTimer();

  protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);

  private:
    void clickMonBouton();
};

class PacmanButton : public QPushButton
{
    public:
        PacmanButton() {}
        PacmanButton(QWidget *parent = 0) : QPushButton(parent){};

    protected:
        void keyPressEvent(QKeyEvent *);
};
#endif
