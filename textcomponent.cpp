#include "textcomponent.h"

QFont *TextComponent::getFont() const
{
    return font;
}

void TextComponent::setFont(QFont *value)
{
    font = value;
}

QPen *TextComponent::getPen() const
{
    return pen;
}

void TextComponent::setPen(QPen *value)
{
    pen = value;
}

QString TextComponent::getText() const
{
    return text;
}

void TextComponent::setText(const QString &value)
{
    text = value;
}

float TextComponent::getX() const
{
    return x;
}

void TextComponent::setX(float value)
{
    x = value;
}

float TextComponent::getY() const
{
    return y;
}

void TextComponent::setY(float value)
{
    y = value;
}

TextComponent::TextComponent()
{
    pen=NULL;

}
void TextComponent::draw(QPainter *painter)
{
painter->setPen(*(this->getPen()));
painter->setFont(*(this->getFont()));
painter->drawText(QPoint(this->getX(),this->getY()),this->getText());
}

bool TextComponent::isClicked(QPoint *)
{
return false;
}

QString TextComponent::componentName()
{
return "Text Component";
}

void TextComponent::select(QPainter *p)
{

}

void TextComponent::update(int x, int y)
{

}
