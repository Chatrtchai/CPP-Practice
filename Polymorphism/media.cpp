#include <iostream>
using namespace std;

class Media {
private:
    string title_name;
    int sizeInBytes;
public:

    /* Constructor */
    Media(string name, int bytes) : title_name(name), sizeInBytes(bytes) {}

    /* Getter */ 

    string GetTitle() {
        return title_name;
    }

    int GetSizeInBytes() {
        return sizeInBytes;
    }

    double GetSizeInKB() {
        return sizeInBytes / 1024.00;
    }

    double GetSizeInMB() {
        return GetSizeInKB() / 1024.00;
    }

    double GetSizeInGB() {
        return GetSizeInMB() / 1024.00;
    }

    virtual void info() = 0;
    virtual void toScreen() = 0;

};

class Image : public Media {
private:
    int width;
    int height;
    char pattern;
public:

    /* Constructor */
    Image(string name, int size, int w, int h, char x) : Media(name, size), width(w), height(h), pattern(x) {} 

    /* Getter */ 

    int GetWidth() {
        return width;
    }

    int GetHeight() {
        return height;
    }

    void info() {
        cout << "Title name : " << GetTitle() << endl;
        cout << "Size (MB) : " << GetSizeInMB() << endl;
        cout << "Resoluion : " << width << " x " << height << endl;
    }

    // Draw
    void toScreen() {
        // Draw each line 
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                cout << pattern;
            }
            cout << endl;
        }
    }

};

class Video : public Media {
private:
    int hour;
    int minutes;
public:

    /* Constructor */ 

    Video(string name, int size, int h, int m) : Media(name, size), hour(h), minutes(m) {}

    /* Getter */

    void GetDuration() {
        cout << hour << ":" << minutes << endl;
    }

    void info() {
        cout << "Title name : " << GetTitle() << endl;
        cout << "Size (MB) : " << GetSizeInMB() << endl;
        cout << "Duration : " << hour << ":" << minutes << endl;
    }

    void toScreen() {
        cout << GetTitle() << " is playing ..." << endl;
    }

};

int main() {

    // Create object pointer with Media Class
    // Media *media = new Media("Media", 1024);

    // cout << media->GetTitle() << endl;
    // cout << media->GetSizeInBytes() << endl;
    // cout << media->GetSizeInKB() << endl;
    // cout << media->GetSizeInMB() << endl;
    // cout << media->GetSizeInGB() << endl;

    cout << "--------------------" << endl;

    Media *image = new Image("image.jpg", 2048, 5, 5, '*');

    image->info();
    image->toScreen();
    cout << "--------------------" << endl;

    Media *video = new Video("video.mp4", 10485760, 6, 00);

    video->info();
    video->toScreen();

}