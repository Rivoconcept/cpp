#ifndef BRUSH_H
# define BRUSH_H

# include <iostream>
# include <string>

class ABrush
{
    protected:
        std::string _type;
    public:
        ABrush(const std::string& type);
        ABrush(const ABrush& brush);
        ABrush& operator=(const ABrush& brush);
        virtual ~ABrush();

        virtual const std::string& getType() const = 0;
};

#endif