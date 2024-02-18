#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "tpGeometry.h"

using namespace cv;

int main()
{


    std::string image_path = samples::findFile("Mona_lisa.jpg");
    Mat img = imread(image_path, IMREAD_GRAYSCALE);
    if (img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    //convert to float
    if (img.type() != CV_32F) {
        img.convertTo(img, CV_32F);
    }

    Mat res = expand(img,2,interpolate_nearest);

    std::cout << interpolate_nearest(img, 30.5f,41.6f)<<"\n";

    // Normaliser les valeurs de l'image dans la plage [0, 1]
    normalize(img, img, 0.0, 1.0, NORM_MINMAX);
    normalize(res, res, 0.0, 1.0, NORM_MINMAX);
    imshow("Display window1", img);

    imshow("Display window2", res);



    int k = waitKey(0); // Wait for a keystroke in the window
    int k1 = waitKey(0); // Wait for a keystroke in the window





}