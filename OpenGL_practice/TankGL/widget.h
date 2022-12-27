#ifndef WIDGET_H
#define WIDGET_H

#include <QtOpenGL>
#include <QtOpenGLWidgets>
#include <QWidget>

#ifdef _APPLE_ //MAC OS X인 경우
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#else          //Linux 등의 OS인 경우
#include <GL/glut.h>
#include <GL/glu.h>
#endif

struct bullet{
    float ypos;
    float xpos;
    float speed;
    bullet *next;
};

struct enemy{
    float ypos;
    float xpos;
    float speed;
    enemy *next;
};

class Widget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    GLuint filter;
    GLuint texture[4];
    GLuint base;

    bullet *headB;
    bullet *tailB;
    bullet *currentB;

    bool firstShot;
    bool enemyAround;
    float tankPosHoriz;
    float lastShot;
    float newShot;
    float lastMove, newMove;

    enemy normalEnemy;

    GLUquadricObj *quadratic;

    QTimer timer;

    void updateBullet();
    void updateEnemy();
    int loadGLTextures();

private:
    void paintGL();
    void resizeGL(int w, int h);
    void initializeGL();

    void mousePressEvent(QMouseEvent*);
    void keyPressEvent(QKeyEvent*);

private slots:
    void updateTimer();
};
#endif // WIDGET_H
