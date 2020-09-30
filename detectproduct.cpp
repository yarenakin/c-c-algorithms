#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat hsv, imthresh, im;

vector<vector<Point> > contours;
vector<Vec4i>hierarchy;

int i;
int cizgi,color;
int areas[5];
int buyuk[5];

//çizgi renkleri
int linecolors[3][6] = { {129,255,161,255,0,208},//kırmızı çizgi
						 {0,255,234,255,0,255},//açık mavi çizgi
						 {0,0,0,0,255,255},//beyaz çizgi
};
 
//mavi çizgili ve 3 çizgili ürünler ürünler kategorisi.
int b_linesedproducts[3][6] ={{100,255,161,255,0,208},//mavi ürünler
					          {17,79,0,255,0,255},//yeşil ürünler
					          {0,0,0,0,255,255},//beyaz ürünler
};

//ürün rengini bulma
void detectproductcolor()
{   
	if (cizgi == 3 && color == 2)//eğer çizgi sayısı 3 ise ve mavi çizgi ise
	{
		for (int k = 0; k < 3; k++)
		{
			inRange(hsv, Scalar(b_linesedproducts[k][0], b_linesedproducts[k][2], b_linesedproducts[k][4]), Scalar(b_linesedproducts[k][1], b_linesedproducts[k][3], b_linesedproducts[k][5]), imthresh);
			erode(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
			dilate(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

			dilate(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
			erode(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
			findContours(imthresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
			vector<Moments> mu(contours.size());

	        if (b_linesedproducts[k][0] == 17 && b_linesedproducts[k][1] == 79 && b_linesedproducts[k][2] == 0 && b_linesedproducts[k][3] == 255 && b_linesedproducts[k][4] == 0 && b_linesedproducts[k][5] == 255)
	        {
			    for (int i = 0; i < contours.size(); i++)
				{
					mu[i] = moments(contours[i]);
					areas[0] = mu[i].m00;
					buyuk[0] = areas[0];
					if (areas[i] > buyuk[0])
					{
						buyuk[0] = areas[i];
					}
				}
				printf("en buyuk alan :%d",buyuk[0]);
	        }
			if (b_linesedproducts[k][0] == 100 && b_linesedproducts[i][k] == 255 && b_linesedproducts[k][2] == 161 && b_linesedproducts[k][3] == 255 && b_linesedproducts[k][4] == 0 && b_linesedproducts[k][5] == 208)
			{
				for (int i = 0; i < contours.size(); i++)
				{
					mu[i] = moments(contours[i]);
					areas[i] = mu[i].m00;
					if (areas[i] > buyuk[1])
					{
						buyuk[1] = areas[i];
					}
				}
			     printf("en buyuk alan :%d", buyuk[1]);
			}
		}
		/*
		if (areag > areab)
		{
			printf("This is green product.\n");

		}
		if (areab > areag)
		{
			printf("This is blue product.\n");
		}
		*/
	}
}
//ürün çizgi rengini ve sayısını bulma. Kırmızı çizgi ->color=1,mavi çizgi->color=2,beyaz çizgi->color=3 demektir.
void detectlinecolor()
{     
	im = imread("C:/Users/Lenovo/Desktop/Elastik Kolon Projesi Data setleri/b16.png");
	imshow("Orjinal", im);
	cvtColor(im, hsv, CV_BGR2HSV);

	for (i = 0; i < 3; i++)
	{
		inRange(hsv, Scalar(linecolors[i][0], linecolors[i][2], linecolors[i][4]), Scalar(linecolors[i][1], linecolors[i][3], linecolors[i][5]), imthresh);
		erode(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		dilate(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(imthresh, imthresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		findContours(imthresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

		if (contours.size() > 0 && contours.size() < 4)
		{
			if (linecolors[i][0] == 129 && linecolors[i][1] == 255 && linecolors[i][2] == 161 && linecolors[i][3] == 255 && linecolors[i][4] == 0 && linecolors[i][5] == 208)
			{
				printf("This is red line.\n");
				cizgi = contours.size();
				//imshow("red line", imthresh);
				color = 1;
				i = 4;

			}

			else if (linecolors[i][0] == 0 && linecolors[i][1] == 255 && linecolors[i][2] == 234 && linecolors[i][3] == 255 && linecolors[i][4] == 0 && linecolors[i][5] == 255)
			{
				printf("This is blue line.\n");
				cizgi = contours.size();
				//imshow("blue line", imthresh);
				color = 2;
				i = 4;
			}

			else if (linecolors[i][0] == 0 && linecolors[i][1] == 0 && linecolors[i][2] == 0 && linecolors[i][3] == 0 && linecolors[i][4] == 255 && linecolors[i][5] == 255)
			{
				printf("This is white line.\n");
				cizgi = contours.size();
				//imshow("white line", imthresh);
				color = 3;
				i = 4;
			}
		}
	}
	imshow("output", imthresh);
	printf("%d lines\n", cizgi);
}

int main()
{
	detectlinecolor();
	detectproductcolor();

	waitKey(0);
	return 0;
}
