import SimpleOpenNI.*; 
SimpleOpenNI kinect;
void setup() { 
  kinect = new SimpleOpenNI(this); 
  // enable depthMap and RGB image 
  kinect.enableDepth(); 
  kinect.enableRGB(); 
  // enable mirror 
  kinect.setMirror(true); 

  size(kinect.depthWidth()+kinect.rgbWidth(), kinect.depthHeight());
} 
void draw() { 
  kinect.update(); 
  // draw depthImageMap and RGB images 
  image(kinect.depthImage(), 0, 0); 
  image(kinect.rgbImage(), kinect.depthWidth(), 0);
}

