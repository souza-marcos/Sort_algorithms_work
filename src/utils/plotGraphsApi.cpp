#include "../../lib/pbPlots/pbPlots.cpp"
#include "../../lib/pbPlots/supportLib.cpp"

#include <vector>
#include <iostream>

int main()
{
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();
    StringReference *errorMessage = new StringReference();

    std::vector<double> xs = {-2, -1, 0, 1, 2};
    std::vector<double> ys = {-2, -1, -2, -1, 2};

    bool success = DrawScatterPlot(imageReference, 600, 400, &xs, &ys, errorMessage);
    if(success){
        std::vector<double> *pngData = ConvertToPNG(imageReference->image);
        WriteToFile(pngData, "scatterPlot.png");
        DeleteImage(imageReference->image);
    }
}