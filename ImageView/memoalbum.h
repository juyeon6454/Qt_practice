#ifndef MEMOALBUM_H
#define MEMOALBUM_H

#include <QWidget>
#include <QSplitter>
#include <QListWidget>

class ImageView;
class QGraphicsScene;
class QListWidgetItem;

class MemoAlbum : public QSplitter
{
    Q_OBJECT
public:
    explicit MemoAlbum(QWidget *parent = nullptr);

    QString currentImage();

private:
    ImageView* imageView;
    QGraphicsScene* graphicsScene;
    QListWidget* listWidget;

signals:

public slots:
    void reset();
    void reloadImages();
    void selectItem(QListWidgetItem*);
    void setImage(QString);

};

#endif // MEMOALBUM_H
