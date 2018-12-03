#ifndef FIGURE_H
#define FIGURE_H
#include "shape.h"

class Figure
{
private:
  Shape **shapes = nullptr;
  int amountOfShapes = 0;

public:
  ~Figure();
  void AddShape(Shape *s);
  std::string GetBoundingBox() const;
};
#endif
