#include <Magick++.h>
#include <iostream>
#include <string>

using namespace std;
using namespace Magick;

void displayMenu() {
    cout << "\nImage Processing Tool\n";
    cout << "1. Load Image\n";
    cout << "2. Display Image\n";
    cout << "3. Resize Image\n";
    cout << "4. Crop Image\n";
    cout << "5. Apply Grayscale Filter\n";
    cout << "6. Apply Blur Filter\n";
    cout << "7. Adjust Brightness/Contrast\n";
    cout << "8. Save Image\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main(int argc, char **argv) {
    InitializeMagick(*argv);
    Image image;
    string filePath, savePath;
    bool imageLoaded = false;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the path to the image: ";
                cin >> filePath;
                try {
                    image.read(filePath);
                    imageLoaded = true;
                    cout << "Image loaded successfully.\n";
                } catch (Exception &error_) {
                    cout << "Error loading image: " << error_.what() << endl;
                }
                break;

            case 2:
                if (imageLoaded) {
                    image.display();
                } else {
                    cout << "No image loaded.\n";
                }
                break;

            case 3:
                if (imageLoaded) {
                    int width, height;
                    cout << "Enter new width: ";
                    cin >> width;
                    cout << "Enter new height: ";
                    cin >> height;
                    image.resize(Geometry(width, height));
                    cout << "Image resized successfully.\n";
                } else {
                    cout << "No image loaded.\n";
                }
                break;

            case 4:
                if (imageLoaded) {
                    int x, y, width, height;
                    cout << "Enter x-coordinate: ";
                    cin >> x;
                    cout << "Enter y-coordinate: ";
                    cin >> y;
                    cout << "Enter width: ";
                    cin >> width;
                    cout << "Enter height: ";
                    cin >> height;
                    image.crop(Geometry(width, height, x, y));
                    cout << "Image cropped successfully.\n";
                } else {
                    cout << "No image loaded.\n";
                }
                break;

            case 5:
                if (imageLoaded) {
                    image.type(GrayscaleType);
                    cout << "Grayscale filter applied.\n";
                } else {
                    cout << "No image loaded.\n";
                }
                break;

            case 6:
                if (imageLoaded) {
                    double radius;
                    cout << "Enter blur radius: ";
                    cin >> radius;
                    image.blur(radius);
                    cout << "Blur filter applied.\n";
                } else {
                    cout << "No image loaded.\n";
                }
                break;

            case 7:
                if (imageLoaded) {
                    double brightness, contrast;
                    cout << "Enter brightness adjustment (100 = no change): ";
                    cin >> brightness;
                    cout << "Enter contrast adjustment (100 = no change): ";
                    cin >> contrast;
                    image.modulate(brightness, contrast);
                    cout << "Brightness and contrast adjusted.\n";
                } else {
                    cout << "No image loaded.\n";
                }
                break;

            case 8:
                if (imageLoaded) {
                    cout << "Enter the path to save the image: ";
                    cin >> savePath;
                    try {
                        image.write(savePath);
                        cout << "Image saved successfully.\n";
                    } catch (Exception &error_) {
                        cout << "Error saving image: " << error_.what() << endl;
                    }
                } else {
                    cout << "No image loaded.\n";
                }
                break;

            case 9:
                cout << "Exiting Image Processing Tool.\n";
                return 0;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}
