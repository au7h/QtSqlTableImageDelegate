#ifndef IMGDELEGATE_H
#define IMGDELEGATE_H
#include <QStyledItemDelegate>
#include <QSize>
#include <QPixmap>
#include <QPainter>

class ImgDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit ImgDelegate(QObject * parent = nullptr);
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const override;
    QSize sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const override;
};
#endif
