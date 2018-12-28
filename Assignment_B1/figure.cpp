#include "figure.h"

void Figure::AddShape(Shape *s)
{
    amountOfShapes += 1;
    Shape **tempShapes = new Shape *[amountOfShapes];

    for (int i = 0; i < (amountOfShapes - 1); i++)
    {
        tempShapes[i] = shapes[i];
    }
    tempShapes[amountOfShapes - 1] = s;

    if (shapes)
    {
        delete[] shapes;
        shapes = nullptr;
    }

    shapes = tempShapes;
}

std::string Figure::GetBoundingBox() const
{
    std::string textToRet = "";
    if (amountOfShapes > 0)
    {
        double minX = 0;
        double maxX = 0;

        double minY = 0;
        double maxY = 0;

        // Loop through all shapes and their coordinates
        for (int i = 0; i < amountOfShapes; i++)
        {
            if (shapes[i])
            {
                int cordAmount = shapes[i]->GetAmountOfCoordinates();
                Coordinate *tempCordsArr = new Coordinate[cordAmount];
                shapes[i]->CopyCoordinates(tempCordsArr);

                if (i == 0)
                {
                    minX = tempCordsArr[0].GetX();
                    maxX = tempCordsArr[0].GetX();

                    minY = tempCordsArr[0].GetY();
                    maxY = tempCordsArr[0].GetY();
                }
                for (int j = 0; j < cordAmount; j++)
                {
                    double x = tempCordsArr[j].GetX();
                    double y = tempCordsArr[j].GetY();
                    if (x > maxX)
                    {
                        maxX = x;
                    }
                    else if (x < minX)
                    {
                        minX = x;
                    }
                    if (y > maxY)
                    {
                        maxY = y;
                    }
                    else if (y < minY)
                    {
                        minY = y;
                    }
                }

                delete[] tempCordsArr;
                tempCordsArr = nullptr;
            }
        }

        std::stringstream stringS;

        double topLeftX = round(minX * 1000) / 1000;
        double topLeftY = round(maxY * 1000) / 1000;

        double bottomRightX = round(maxX * 1000) / 1000;
        double bottomRightY = round(minY * 1000) / 1000;
        stringS << "Corners of the bounding box in coordinates (X,Y) \n";
        stringS << "Top left corner: (" << topLeftX << ", " << topLeftY << ") \n";
        stringS << "Bottom right corner: (" << bottomRightX << ", " << bottomRightY << ") \n";

        textToRet = stringS.str();
    }
    else
    {
        textToRet = "No shapes, no bounding box.";
    }

    return textToRet;
}

Figure::~Figure()
{
    for (int i = 0; i < amountOfShapes; i++)
    {
        if (shapes[i])
        {
            delete shapes[i];
        }
    }

    if (shapes)
    {
        delete[] shapes;
    }
}
