#include "imgdelegate.h"

ImgDelegate::ImgDelegate(QObject * parent)
    : QStyledItemDelegate(parent){}

QSize ImgDelegate::sizeHint(const QStyleOptionViewItem & option, const QModelIndex & index) const
{

    if(index->data().type() == QVariant::ByteArray)
        return QSize(80, 80); //tutaj zamiast zwracać 80, 80 możesz pobierać wielkość obrazka i ustawiać rozmiar komorki tabeli
    else
        return QStyledItemDelegate::sizeHint(option, index);
}

void ImgDelegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
    if (index->data().type() == QVariant::ByteArray)
    {
        QPixmap pm;
        pm.loadFromData(index.data().toByteArray());
        painter->drawPixmap(option.rect, pm);
    } else {
        QStyledItemDelegate::paint(painter, option, index);
    }
}
