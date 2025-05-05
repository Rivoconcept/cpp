#ifndef INKBRUSH_H
# define INKBRUSH_H

# include "Brush.hpp"

class InkBrush : public ABrush
{
    public:
        InkBrush();
        InkBrush(const InkBrush& inkbrush);
        InkBrush& operator=(const InkBrush& inkbrush);
        ~InkBrush();

        const std::string& getType() const;
};

#endif