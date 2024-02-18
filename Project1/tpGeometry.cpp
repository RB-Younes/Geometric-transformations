#include "tpGeometry.h"
#include <cmath>
#include <algorithm>
#include <tuple>
using namespace cv;
using namespace std;

/**
    Transpose the input image,
    ie. performs a planar symmetry according to the
    first diagonal (upper left to lower right corner).
*/
Mat transpose(Mat image)
{      
    Mat res = Mat::zeros(image.cols,image.rows, CV_32F);
    /********************************************
                YOUR CODE HERE
    hint: consider a non square image
    *********************************************/

    for (int i = 0; i < image.rows; i++)
    {
        for (int j = 0; j < image.cols; j++)
        {
            res.at<float>(j, i) = image.at<float>(i, j);
        }
    }
   
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}

/**
    Compute the value of a nearest neighbour interpolation
    in image Mat at position (x,y)
*/
float interpolate_nearest(Mat image, float y, float x)
{
    float v=0;
    /********************************************
                YOUR CODE HERE
    *********************************************/

    if (x < 0 || x >= image.cols || y < 0 || y >= image.rows) {
        std::cerr << "Coordonnées en dehors des limites de l'image" << std::endl;
        return 0.0f; 
    }

    int nearest_x = cvRound(x);
    int nearest_y = cvRound(y);

    v = image.at<float>(nearest_y, nearest_x);

    /********************************************
                END OF YOUR CODE
    *********************************************/
    return v;

}

/**
    Multiply the image resolution by a given factor using the given interpolation method.
    If the input size is (h,w) the output size shall be ((h-1)*factor, (w-1)*factor)
*/
Mat expand(Mat image, int factor, float(* interpolationFunction)(cv::Mat image, float y, float x))
{
    assert(factor>0);
    Mat res = Mat::zeros((image.rows-1)*factor,(image.cols-1)*factor,CV_32FC1);
    /********************************************
                YOUR CODE HERE
    *********************************************/

    for (int y = 0; y < res.rows; ++y) {
        for (int x = 0; x < res.cols; ++x) {

            float orig_x = x / static_cast<float>(factor);
            float orig_y = y / static_cast<float>(factor);

            float value = interpolationFunction(image, orig_y, orig_x);

            res.at<float>(y, x) = value;
        }
    }
    
    /********************************************
                END OF YOUR CODE
    *********************************************/
    return res;
}
