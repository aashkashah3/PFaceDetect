import processing.video.*;
import pFaceDetect.PFaceDetect;

Capture cap;
PFaceDetect face;
PImage img;
float scaleFactor;
int w, h;

void setup() {
  size(640, 480);
  scaleFactor = 2.0;
  w = round(width/scaleFactor);
  h = round(height/scaleFactor);
  cap = new Capture(this, width, height);
  cap.start();
  face = new PFaceDetect(this, w, h, "haarcascade_frontalface_alt.xml");
  img = createImage(w, h, ARGB);
  smooth();
  noFill();
  stroke(255, 100, 0);
}

void draw() {
  image(cap, 0, 0);
  img.copy(cap, 0, 0, cap.width, cap.height, 0, 0, img.width, img.height);
  img.updatePixels();
  face.findFaces(img);
  int [][] faces = face.getFaces();
  drawFaces(faces);
}

void captureEvent(Capture _c) {
  _c.read();
}

void drawFaces(int [][] _f) {
  if (_f == null) {
    return;
  }
  if (_f.length == 0) {
    return;
  }
  scale(scaleFactor);
  for (int i=0; i<_f.length; i++) {
    rect(_f[i][0], _f[i][1], _f[i][2], _f[i][3]);
  }
}

